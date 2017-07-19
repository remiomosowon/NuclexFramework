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

namespace Nuclex { namespace Fonts { namespace Content {

  /// <summary>Hinting methods that can be used to position strokes in a font</summary>
  public enum class FontHinter {

    /// <summary>
    ///   Do not use any hinting to position the font's strokes. Causes the font
    ///   to appear blurry but accurately retains stroke positions.
    /// </summary>
    Disable = -1,

    /// <summary>
    ///   Performs hinting based on the font's embedded hinting rules, which
    ///   usually prefer sharpness to accuracy. This should result in characters
    ///   perfectly matching in shape that of GDI text rendering.
    /// </summary>
    Native = 0,

    /// <summary>
    ///   Uses FreeType's auto-hinter, providing a good compromise between
    ///   accuracy and sharpness.
    /// </summary>
    AutoHinter = 1

  };

}}} // namespace Nuclex::Fonts::Content
