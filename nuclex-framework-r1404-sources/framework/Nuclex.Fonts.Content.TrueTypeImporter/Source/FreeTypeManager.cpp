#pragma region CPL License
/*
Nuclex Framework
Copyright (C) 2002-2011 Nuclex Development Labs

This library is free software; you can redistribute it and/or
modify it under the terms of the IBM Common Public License as
published by the IBM Corporation; either version 1.0 of the
License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
IBM Common Public License for more details.

You should have received a copy of the IBM Common Public
License along with this library
*/
#pragma endregion

#include "FreeTypeManager.h"
#include "ReverseStringLengthComparer.h"

#include <shlobj.h>
#include <comdef.h>

#include "clix.h"

using namespace std;
using namespace clix;

using namespace System;

using namespace Microsoft::Win32;

using namespace Microsoft::Xna::Framework;
using namespace Microsoft::Xna::Framework::Graphics;
using namespace Microsoft::Xna::Framework::Content::Pipeline::Graphics;

namespace Nuclex { namespace Fonts { namespace Content {

  // ------------------------------------------------------------------------------------------- //

  namespace { // anonymous

    /// <summary>Returns the matching FreeType style flags for a FontDescriptionStyle</summary>
    /// <param name="style">Style whose equivalent style flags will be returned</param>
    /// <returns>The matching FeeeType style flags</returns>
    int styleFlagsFromFontDescriptionStyle(FontDescriptionStyle style) {
      if(style == FontDescriptionStyle::Bold)
        return FT_STYLE_FLAG_BOLD;
      else if(style == FontDescriptionStyle::Italic)
        return FT_STYLE_FLAG_ITALIC;
      else if(style == (FontDescriptionStyle::Bold | FontDescriptionStyle::Italic))
        return FT_STYLE_FLAG_BOLD | FT_STYLE_FLAG_ITALIC;
      else
        return 0;
    }

    // ----------------------------------------------------------------------------------------- //

    /// <summary>Opens the registry key of Windows' font name lookup table</summary>
    /// <returns>The registry key where Windows stores its font names</returns>
    Microsoft::Win32::RegistryKey ^openFontRegistryKey() {
      return Microsoft::Win32::Registry::LocalMachine->OpenSubKey(
        L"Software\\Microsoft\\Windows NT\\CurrentVersion\\Fonts"
      );
    }

  } // anonymous namespace

  // ------------------------------------------------------------------------------------------- //

  void FreeTypeManager::initializeFreeType() {
    FT_Library newFreeTypeLibrary;

    // Try to initialize the freetype library
    FT_Error error = ::FT_Init_FreeType(&newFreeTypeLibrary);
    if(error)
      throw gcnew System::Exception(L"Could not initialize FreeType library");

    freeTypeLibrary = newFreeTypeLibrary;
  }

  // ------------------------------------------------------------------------------------------- //

  void FreeTypeManager::shutdownFreeType() {

    // Release the current library instance
    ::FT_Done_FreeType(freeTypeLibrary);
    freeTypeLibrary = 0;

  }

  // ------------------------------------------------------------------------------------------- //

  std::wstring FreeTypeManager::getFontsDirectory() {

    // We need the shell's memory allocator to free the item id list afterwards
    IMallocPtr shellMallocPointer;
    if(FAILED(SHGetMalloc(&shellMallocPointer)))
      throw gcnew Exception(L"Failed to obtain shell malloc interface");

    LPITEMIDLIST itemIDListPointer;

    // Query for the windows fonts folder
    if(FAILED(::SHGetSpecialFolderLocation(NULL, CSIDL_FONTS, &itemIDListPointer)))
      throw gcnew Exception(L"Could not locate the windows fonts folder");

    wchar_t path[MAX_PATH];
    try {
      // Try to obtain the file system path of the folder
      if(FAILED(::SHGetPathFromIDList(itemIDListPointer, path)))
        throw gcnew Exception(L"Error retrieving the windows fonts folder path");
    }
    finally {
      shellMallocPointer->Free(itemIDListPointer);
    }

    return std::wstring(path) + L"\\";

  }

  // ------------------------------------------------------------------------------------------- //

  FT_Face FreeTypeManager::OpenFont(
    System::String ^pathOrFaceName,
    Microsoft::Xna::Framework::Content::Pipeline::Graphics::FontDescriptionStyle style
  ) {

    // Allow a path to a truetype font to be specified instead of the windows
    // font name so we can easily ship custom fonts with our applications
    if(System::IO::File::Exists(pathOrFaceName)) {

      FT_Face face;

      // Get the ANSI filename of the font
      string filename = marshalString<E_ANSI>(pathOrFaceName);

      // Try to open the font with FreeType
      FT_Open_Args openArgs;
      openArgs.flags = FT_OPEN_PATHNAME;
      openArgs.pathname = const_cast<char *>(filename.c_str());

      FT_Error error = ::FT_Open_Face(freeTypeLibrary, &openArgs, 0, &face);
      if(error)
        throw gcnew Exception("Error openening font file");

      return face;

    } else {

      return OpenWindowsFont(pathOrFaceName, style);

    }

  }

  // ------------------------------------------------------------------------------------------- //

  FT_Face FreeTypeManager::OpenWindowsFont(
    System::String ^searchedFaceName,
    Microsoft::Xna::Framework::Content::Pipeline::Graphics::FontDescriptionStyle style
  ) {
    System::String ^fontsFolderPath = marshalString<E_UTF16>(getFontsDirectory());
    int searchedStyleFlags = styleFlagsFromFontDescriptionStyle(style);

    Microsoft::Win32::RegistryKey ^fontsKey = openFontRegistryKey();
    try {
      array<System::String ^> ^fontNames = fontsKey->GetValueNames();
      System::Array::Sort(fontNames, ReverseStringLengthComparer::Default);

      for each(System::String ^fontName in fontNames) {

        // Font names have appended extra data like "(TrueType)", "(OpenType)" and
        // in some cases other things like "10,12,15". To avoid having to filter these
        // out, we only look for fonts beginning with the searched face name. Fonts
        // are checked from shortest name to longest name so "Arial" will first be
        // compared with "Arial", not "Arial Extra Bold".
        bool isCandidate = fontName->StartsWith(
          searchedFaceName, System::StringComparison::CurrentCultureIgnoreCase
        );
        if(!isCandidate) {
          continue;
        }

        // Look up the font filename. We only consider TrueType (.ttf) fonts because
        // other formats are not supported by FreeType
        System::String ^fontFilename = dynamic_cast<System::String ^>(
          fontsKey->GetValue(fontName)
        );
        if(!fontFilename->EndsWith(".ttf", System::StringComparison::CurrentCultureIgnoreCase)) {
          continue;
        }

        // If the registry specifies an absolute path, use it directly, otherwise assume
        // the path is relative to Windows' fonts directory.
        System::String ^fontPath;
        if(System::IO::Path::IsPathRooted(fontFilename)) {
          fontPath = fontFilename;
        } else {
          fontPath = System::IO::Path::Combine(fontsFolderPath, fontFilename);
        }

        //  Try to open the font with FreeType
        FT_Open_Args openArgs;
        openArgs.flags = FT_OPEN_PATHNAME;
        string ansiFontPath = marshalString<E_ANSI>(fontPath);
        openArgs.pathname = const_cast<char *>(ansiFontPath.c_str());
  
        FT_Face face;
        FT_Error error = ::FT_Open_Face(freeTypeLibrary, &openArgs, -1, &face);

        // If FreeType was able to open the font, check whether it is the font we're
        // looking for based on the style flags encoded in its faces.
        if(!error) {
          int faceCount = face->num_faces;
          ::FT_Done_Face(face);

          for(int faceIndex = 0; faceIndex < faceCount; ++faceIndex) {
            FT_Error error = ::FT_Open_Face(freeTypeLibrary, &openArgs, faceIndex, &face);
            if(!error) {
              if(face->style_flags == searchedStyleFlags)
                return face; // Match!

              ::FT_Done_Face(face);
            }
          }
        } // if !error

      } // for each fontName
    }
    finally {
      fontsKey->Close();
    }

    // If we reach this point, the specified font could not be found
    throw gcnew Exception(L"Font could not be found");
  }

  // ------------------------------------------------------------------------------------------- //

}}} // namespace Nuclex::Fonts::Content
