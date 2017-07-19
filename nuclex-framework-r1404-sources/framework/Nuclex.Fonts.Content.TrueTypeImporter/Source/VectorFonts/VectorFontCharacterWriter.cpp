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

#include "VectorFontCharacterWriter.h"

using namespace std;

using namespace System::Collections::Generic;

using namespace Microsoft::Xna::Framework::Content::Pipeline::Graphics;

namespace Nuclex { namespace Fonts { namespace Content {

  // ------------------------------------------------------------------------------------------- //

  void VectorFontCharacterWriter::Write(
    Microsoft::Xna::Framework::Content::Pipeline::Serialization::Compiler::ContentWriter ^output,
    Nuclex::Fonts::Content::VectorFontCharacterContent ^characterContent
  ) {

    // List: Vector font vertices
    output->WriteObject(characterContent->Vertices);

    // Vector2: Pen advancement after this character
    output->WriteObject(characterContent->Advancement);

    // Int32 x (Int32, Int32): Vertex indices for the character's outline
    output->Write(characterContent->Outlines->Count);
    for each(VectorFontCharacterContent::Outline outline in characterContent->Outlines) {
      output->Write(outline.StartVertexIndex);
      output->Write(outline.VertexCount);
    }

    // Int32 x (Int32, Int32, Int32): Vertex indices for the character's face
    output->Write(characterContent->Faces->Count);
    for each(VectorFontCharacterContent::Face face in characterContent->Faces) {
      output->Write(face.FirstVertexIndex);
      output->Write(face.SecondVertexIndex);
      output->Write(face.ThirdVertexIndex);
    }

  }

  // ------------------------------------------------------------------------------------------- //

  System::String ^VectorFontCharacterWriter::GetRuntimeReader(
    Microsoft::Xna::Framework::Content::Pipeline::TargetPlatform targetPlatform
  ) {

    // This will resolve to either the VectorFontReader of the PC assembly
    // or to the BitmapFontReader of the XBox 360 assembly
    return
      "Nuclex.Fonts.Content.VectorFontCharacterReader, "
      "Nuclex.Fonts, "
      "Version=4.0.0.0, "
      "Culture=neutral, "
      "PublicKeyToken=96bb577564343f16";

  }

  // ------------------------------------------------------------------------------------------- //

  System::String ^VectorFontCharacterWriter::GetRuntimeType(
    Microsoft::Xna::Framework::Content::Pipeline::TargetPlatform targetPlatform
  ) {

    return
      "Nuclex.Fonts.VectorFontCharacter, "
      "Nuclex.Fonts, "
      "Version=4.0.0.0, "
      "Culture=neutral, "
      "PublicKeyToken=96bb577564343f16";

  }

  // ------------------------------------------------------------------------------------------- //

}}} // namespace Nuclex::Fonts::Content
