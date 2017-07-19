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

#pragma once

#include "FreeTypeFontRasterizer.h"
#include "SpriteFontContent.h"
#include "../FontOrigin.h"

namespace Nuclex { namespace Fonts { namespace Content {

  /// <summary>Processes sprite font descriptions for usage with the XNA framework</summary>
  [
    Microsoft::Xna::Framework::Content::Pipeline::ContentProcessorAttribute(
      DisplayName = "Sprite Font - Nuclex Framework"
    )
  ]
  public ref class NuclexSpriteFontDescriptionProcessor :
    Microsoft::Xna::Framework::Content::Pipeline::ContentProcessor<
      Microsoft::Xna::Framework::Content::Pipeline::Graphics::FontDescription ^,
      Nuclex::Fonts::Content::SpriteFontContent ^
    > {

    /// <summary>Creates an XNA sprite font from the font description</summary>
    /// <param name="input">Provided font description to create the sprite font from</param>
    /// <param name="context">Additional informations for the content processor</param>
    /// <returns>The generated XNA sprite font</returns>
    public: virtual Nuclex::Fonts::Content::SpriteFontContent ^Process(
      Microsoft::Xna::Framework::Content::Pipeline::Graphics::FontDescription ^input,
      Microsoft::Xna::Framework::Content::Pipeline::ContentProcessorContext ^context
    ) override;

    /// <summary>How the font should be aligned to the drawing location</summary>
    [System::ComponentModel::DefaultValueAttribute(FontOrigin::UpperEnd)]
    [System::ComponentModel::DisplayNameAttribute("Vertical Font Origin")]
    [
      System::ComponentModel::DescriptionAttribute(
        "Controls where the text will be placed relative to the drawing position. "
        "Use \"UpperEnd\" to match the behavior of XNA's content processor, placing "
        "the text's upper end at the drawing location. \"BaseLine\" will place "
        "the text's base line (the line normal characters stand on) at the "
        "drawing location."
      )
    ]
    property FontOrigin Origin {
      FontOrigin get() { return this->origin; }
      void set(FontOrigin value) { this->origin = value; }
    }

    /// <summary>Font hinting algorithm that will be used to position strokes</summary>
    [System::ComponentModel::DefaultValueAttribute(FontHinter::Native)]
    [System::ComponentModel::DisplayNameAttribute("Hinting Method")]
    [
      System::ComponentModel::DescriptionAttribute(
        "Hinting adjusts the font's strokes to better align with pixel boundaries, "
        "producing sharper text at the cost of accuracy. \"Native\" matches GDI font "
        "shaping and produces very sharp text, \"AutoHinter\" uses FreeType's auto-"
        "hinter, usually a good compromise between both extremes and \"Disable\" "
        "completely disables hinting, accurately placing strokes but looking blurry."
      )
    ]
    property FontHinter Hinter {
      FontHinter get() { return this->hinter; }
      void set(FontHinter value) { this->hinter = value; }
    }

    /// <summary>Determines the optimal texture size for the font</summary>
    /// <param name="input">
    ///   Font description containined the list of characters to import
    /// </param>
    /// <param name="rasterizer">Rasterizer that has been set up for the font</param>
    /// <returns>The smallest texture size sufficient to contain all characters</returns>
    private: int NuclexSpriteFontDescriptionProcessor::determineOptimalTextureSize(
      Microsoft::Xna::Framework::Content::Pipeline::Graphics::FontDescription ^input,
      Nuclex::Fonts::Content::FreeTypeFontRasterizer %rasterizer
    );

    /// <summary>How the font should be aligned to the drawing location</summary>
    private: FontOrigin origin;

    /// <summary>Font hinter that will be used</summary>
    private: FontHinter hinter;

  };

}}} // namespace Nuclex::Fonts::Content
