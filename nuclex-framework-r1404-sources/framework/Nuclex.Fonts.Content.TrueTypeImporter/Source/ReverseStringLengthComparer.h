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

  // ------------------------------------------------------------------------------------------- //

  /// <summary>Compares strings based on their length</summary>
  ref class ReverseStringLengthComparer :
    System::Collections::Generic::IComparer<System::String ^> {

    /// <summary>The default instance of the length-based string comparer</summary>
    public: static initonly ReverseStringLengthComparer ^Default =
      gcnew ReverseStringLengthComparer();

    /// <summary>Calculates the rank of the left string compared to the right</summary>
    /// <param name="left">String that will be compared on the left side</param>
    /// <param name="right">String that will be compared on the right side</param>
    /// <returns>The relative ranking between the left string and the right string</returns>
    public: virtual int Compare(System::String ^left, System::String ^right) {
      bool leftIsNull = System::String::IsNullOrEmpty(left);
      bool rightIsNull = System::String::IsNullOrEmpty(right);

      if(leftIsNull) {
        if(rightIsNull) {
          return 0;
        }

        return -right->Length;
      } else if(rightIsNull) {
        return left->Length;
      }

      return left->Length - right->Length;
    }

  };

  // ------------------------------------------------------------------------------------------- //

}}} // namespace Nuclex::Fonts::Content
