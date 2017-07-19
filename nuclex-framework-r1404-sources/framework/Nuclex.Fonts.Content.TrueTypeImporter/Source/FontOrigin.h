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

  /// <summary>Origins that can be used to vertically align fonts</summary>
  public enum class FontOrigin {

    /// <summary>
    ///   The font's upper end will be aligned with the text draw location
    /// </summary>
    UpperEnd,

    /// <summary>
    ///   The font's base line will be aligned with the text draw location
    /// </summary>
    BaseLine,

  };

}}} // namespace Nuclex::Fonts::Content
