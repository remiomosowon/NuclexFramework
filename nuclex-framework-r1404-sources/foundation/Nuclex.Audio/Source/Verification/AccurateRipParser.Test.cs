﻿#region CPL License
/*
Nuclex Framework
Copyright (C) 2002-2009 Nuclex Development Labs

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
#endregion

using System;
using System.Collections.Generic;
using System.IO;

#if UNITTEST

using NUnit.Framework;

namespace Nuclex.Audio.Verification {

  /// <summary>Unit Test for the AccurateRip response parser</summary>
  [TestFixture]
  public class AccurateRipParserTest {

    /// <summary>
    ///   Tests whether responses to AccurateRip database queries can be parsed
    /// </summary>
    [Test]
    public void TestQueryResponseParsing() {

      using(MemoryStream testResponseMemory = new MemoryStream(testResponse)) {
        AccurateRipParser.DecodeQueryResponse(new BinaryReader(testResponseMemory));

        // Make sure the parser has consumed the entire response
        Assert.AreEqual(testResponseMemory.Length, testResponseMemory.Position);
      }

    }

    /// <summary>
    ///   A recorded response from the AccurateRip server that is used for testing
    /// </summary>
    private static readonly byte[] testResponse = new byte[927] {
      0x0A, 0x5C, 0x08, 0x12, 0x00, 0xB5, 0x54, 0x90,
      0x00, 0x0A, 0x3D, 0x0B, 0x6A, 0x42, 0x82, 0x7B,
      0x29, 0xF9, 0xBF, 0x0F, 0x0E, 0x08, 0x45, 0x55,
      0x4D, 0x61, 0xFF, 0x15, 0x08, 0x24, 0x2B, 0x45,
      0x03, 0x03, 0xA4, 0xEB, 0x60, 0x5C, 0xFE, 0x03,
      0x46, 0xDC, 0x5B, 0xDD, 0xC0, 0x66, 0xE7, 0x74,
      0x8B, 0x44, 0x12, 0x3C, 0xDE, 0xD7, 0x68, 0x0C,
      0x10, 0x65, 0x44, 0xC8, 0x13, 0x17, 0xE1, 0xD0,
      0x6F, 0xBC, 0xA4, 0x45, 0x31, 0xEA, 0xFF, 0xAD,
      0xF9, 0xFA, 0x38, 0x0D, 0x44, 0x6A, 0xD4, 0xF8,
      0xFA, 0xB5, 0xD5, 0x40, 0x81, 0x44, 0x97, 0xF6,
      0x8B, 0x32, 0xD8, 0xE2, 0x18, 0x22, 0x40, 0x88,
      0xE6, 0x54, 0x7E, 0xB9, 0xB8, 0xA0, 0x96, 0x0A,
      0x5C, 0x08, 0x12, 0x00, 0xB5, 0x54, 0x90, 0x00,
      0x0A, 0x3D, 0x0B, 0x6A, 0x13, 0x12, 0xE2, 0xA8,
      0xB5, 0xF7, 0xFF, 0x69, 0xD7, 0x14, 0xD0, 0xF8,
      0x58, 0x88, 0x1B, 0xA7, 0x30, 0xC8, 0x12, 0xBF,
      0x73, 0x51, 0x00, 0x6D, 0xD5, 0xF6, 0x70, 0x12,
      0xEA, 0x36, 0xBE, 0x6C, 0x8E, 0xB3, 0x84, 0xCB,
      0x13, 0x9D, 0x40, 0x06, 0xBD, 0xFB, 0xD3, 0x46,
      0xB1, 0x13, 0x10, 0x8B, 0xE6, 0xFE, 0xAE, 0xA9,
      0x47, 0xD4, 0x13, 0xA0, 0x07, 0x45, 0x15, 0x7D,
      0x7E, 0x4E, 0xF4, 0x12, 0x53, 0x68, 0xE6, 0xF7,
      0x9B, 0x53, 0xFA, 0x26, 0x13, 0x42, 0x16, 0x4B,
      0x7D, 0x65, 0x53, 0xA2, 0x86, 0x13, 0x22, 0xF1,
      0xC1, 0xBE, 0x19, 0xB3, 0x7E, 0x65, 0x0A, 0x5C,
      0x08, 0x12, 0x00, 0xB5, 0x54, 0x90, 0x00, 0x0A,
      0x3D, 0x0B, 0x6A, 0x11, 0x93, 0x6A, 0xFF, 0x04,
      0x14, 0x7F, 0x2E, 0xB3, 0x11, 0x9E, 0xF2, 0xFF,
      0xD5, 0xE3, 0x81, 0xB9, 0xD1, 0x11, 0xD1, 0xA6,
      0xCD, 0xA5, 0xD8, 0x08, 0x77, 0x95, 0x11, 0xD2,
      0x27, 0xB2, 0x58, 0x11, 0xCA, 0x03, 0xA0, 0x11,
      0x02, 0x80, 0xE2, 0x5A, 0xB0, 0x4A, 0x11, 0x40,
      0x10, 0x3A, 0x02, 0x07, 0x20, 0x33, 0x43, 0xC9,
      0xB5, 0x11, 0x7B, 0x87, 0x4B, 0x15, 0x72, 0x42,
      0x1E, 0xB9, 0x11, 0xB0, 0xDA, 0x59, 0x39, 0x35,
      0xF3, 0x6F, 0xE3, 0x11, 0xA8, 0xEA, 0xA2, 0xF1,
      0x05, 0xAC, 0x13, 0xFF, 0x10, 0xA9, 0x41, 0xE1,
      0x5A, 0xA3, 0xCD, 0xDA, 0x4F, 0x0A, 0x5C, 0x08,
      0x12, 0x00, 0xB5, 0x54, 0x90, 0x00, 0x0A, 0x3D,
      0x0B, 0x6A, 0x07, 0xF2, 0x4C, 0x34, 0xAB, 0x99,
      0xD1, 0xD0, 0x84, 0x07, 0x23, 0x3B, 0xDB, 0x73,
      0x01, 0xDA, 0x2F, 0x0B, 0x07, 0x44, 0x9E, 0x6F,
      0xA0, 0xA8, 0x22, 0x0F, 0xC0, 0x07, 0x2B, 0x13,
      0xC0, 0x42, 0x4B, 0x4F, 0x2B, 0xF0, 0x07, 0x68,
      0xB3, 0x2E, 0xA8, 0xFD, 0x03, 0xFF, 0x4F, 0x07,
      0x00, 0x43, 0xF9, 0x5F, 0xD8, 0x37, 0xCB, 0x70,
      0x07, 0x97, 0x11, 0xEB, 0x93, 0x39, 0x80, 0x0C,
      0xC9, 0x07, 0xF4, 0x44, 0x27, 0xA1, 0x28, 0x5A,
      0xC1, 0x2A, 0x07, 0xC9, 0x49, 0xC5, 0x04, 0xF6,
      0x57, 0x96, 0x31, 0x07, 0x58, 0x51, 0xC2, 0x15,
      0x0C, 0xE7, 0x9C, 0x34, 0x0A, 0x5C, 0x08, 0x12,
      0x00, 0xB5, 0x54, 0x90, 0x00, 0x0A, 0x3D, 0x0B,
      0x6A, 0x06, 0x5B, 0x47, 0x9B, 0x07, 0x72, 0x11,
      0xCD, 0x69, 0x06, 0xBD, 0x25, 0xF5, 0x85, 0x18,
      0xE6, 0x73, 0xCD, 0x06, 0x8D, 0x72, 0xDE, 0x0A,
      0x89, 0x8B, 0x61, 0xDB, 0x06, 0x04, 0x38, 0x0A,
      0x02, 0x2D, 0xE5, 0x34, 0x3A, 0x06, 0x3B, 0x25,
      0x10, 0xBF, 0x1A, 0xE3, 0xF9, 0xFA, 0x06, 0x50,
      0xF4, 0x39, 0x85, 0x14, 0x38, 0x9F, 0x87, 0x06,
      0x96, 0x91, 0xCF, 0x47, 0xD3, 0x40, 0x86, 0x39,
      0x06, 0xCD, 0x5C, 0xD7, 0xA9, 0x90, 0x0C, 0xBE,
      0x4D, 0x06, 0xA8, 0xC0, 0xA4, 0x09, 0x26, 0x3E,
      0x39, 0x7E, 0x06, 0x4A, 0xC5, 0xAD, 0x07, 0x78,
      0xC6, 0x09, 0xEC, 0x0A, 0x5C, 0x08, 0x12, 0x00,
      0xB5, 0x54, 0x90, 0x00, 0x0A, 0x3D, 0x0B, 0x6A,
      0x02, 0x00, 0xBD, 0x93, 0x0C, 0xC0, 0x4D, 0xE3,
      0xC7, 0x02, 0x7E, 0x48, 0x39, 0x50, 0x01, 0x35,
      0x1A, 0xC9, 0x02, 0x3A, 0xAA, 0x91, 0xC2, 0x2D,
      0x97, 0xB4, 0x15, 0x02, 0xB3, 0x87, 0xC9, 0x98,
      0x02, 0xBB, 0x9B, 0xBE, 0x02, 0xE7, 0xB0, 0x62,
      0xDA, 0x27, 0x78, 0x3B, 0xE5, 0x02, 0x8A, 0xD3,
      0x41, 0x68, 0x6E, 0xAD, 0xAE, 0x48, 0x02, 0xB4,
      0x2E, 0x61, 0x9A, 0x7B, 0x16, 0x58, 0xEF, 0x02,
      0x5F, 0x7C, 0x7C, 0x66, 0x11, 0xF6, 0x1F, 0x11,
      0x02, 0xBA, 0x2D, 0xC6, 0x83, 0x0C, 0xA4, 0xE5,
      0x3D, 0x02, 0x76, 0x36, 0xDC, 0x7E, 0x4C, 0xCA,
      0x05, 0x0E, 0x0A, 0x5C, 0x08, 0x12, 0x00, 0xB5,
      0x54, 0x90, 0x00, 0x0A, 0x3D, 0x0B, 0x6A, 0x0B,
      0x47, 0x84, 0x19, 0xB3, 0x45, 0xB0, 0xFD, 0x21,
      0x0A, 0x54, 0x96, 0x3F, 0x5F, 0xC5, 0x4D, 0x84,
      0xEF, 0x0A, 0x80, 0x5D, 0xB3, 0x7A, 0x17, 0xB8,
      0x64, 0xEE, 0x0B, 0x83, 0x82, 0x30, 0x02, 0xCD,
      0x2F, 0xE4, 0x21, 0x0A, 0x6C, 0xBB, 0xF9, 0xBC,
      0x42, 0x9D, 0x32, 0x38, 0x0B, 0xE2, 0x90, 0xB3,
      0x12, 0xD7, 0x40, 0x48, 0x3C, 0x0B, 0xB5, 0x11,
      0x24, 0x7F, 0xFB, 0x3F, 0x1E, 0x30, 0x0A, 0x86,
      0x79, 0x84, 0x9C, 0x35, 0xB0, 0x22, 0xF8, 0x0A,
      0x0C, 0x26, 0xBB, 0x1D, 0x0B, 0x85, 0xB0, 0x83,
      0x0B, 0xBF, 0x8A, 0xDC, 0x3F, 0xCF, 0xED, 0x84,
      0xD0, 0x0A, 0x5C, 0x08, 0x12, 0x00, 0xB5, 0x54,
      0x90, 0x00, 0x0A, 0x3D, 0x0B, 0x6A, 0x04, 0x59,
      0xAD, 0x2E, 0x8E, 0x38, 0x8B, 0xFA, 0x4D, 0x04,
      0x99, 0xB2, 0x32, 0x5E, 0x59, 0xFF, 0xD9, 0x2C,
      0x04, 0x79, 0xE1, 0xCE, 0x22, 0x5B, 0xCD, 0xFF,
      0xC3, 0x04, 0x4C, 0x73, 0xF7, 0xFC, 0x76, 0x26,
      0x5C, 0xF5, 0x04, 0x73, 0xF7, 0x51, 0x2B, 0xC2,
      0xD7, 0x01, 0x21, 0x04, 0x1A, 0x9D, 0xE8, 0xC0,
      0x3D, 0x34, 0x9D, 0x5C, 0x04, 0x80, 0x7D, 0x37,
      0x66, 0x71, 0x3C, 0xE0, 0x2F, 0x04, 0x73, 0x5D,
      0xD9, 0xB2, 0x92, 0x71, 0x40, 0xA9, 0x04, 0xEF,
      0x1F, 0xB2, 0x55, 0x4B, 0x26, 0x79, 0x0E, 0x04,
      0xED, 0x9B, 0xF5, 0x41, 0xDF, 0x28, 0xA3, 0xDF,
      0x0A, 0x5C, 0x08, 0x12, 0x00, 0xB5, 0x54, 0x90,
      0x00, 0x0A, 0x3D, 0x0B, 0x6A, 0x04, 0x56, 0x40,
      0x8D, 0xBF, 0x44, 0xEE, 0xF1, 0x01, 0x04, 0x80,
      0xEF, 0xFB, 0x6E, 0xE1, 0x4E, 0x05, 0x4F, 0x04,
      0x2F, 0xEB, 0x6E, 0x7E, 0xD2, 0xD1, 0xBD, 0x2B,
      0x04, 0xEE, 0xD1, 0x9E, 0x82, 0x03, 0x51, 0xC7,
      0x0C, 0x04, 0x99, 0x71, 0xB8, 0xD6, 0xF9, 0x73,
      0xEF, 0x68, 0x04, 0xF8, 0xC3, 0x6A, 0xC2, 0x38,
      0x39, 0x24, 0x33, 0x04, 0x54, 0x6A, 0xC2, 0x15,
      0x91, 0xE9, 0x73, 0x65, 0x04, 0xBF, 0x91, 0xE5,
      0xCA, 0x26, 0xE3, 0xE3, 0x88, 0x04, 0x25, 0xAD,
      0x1F, 0x76, 0x8A, 0x22, 0x1C, 0x8B, 0x04, 0x27,
      0xB3, 0x88, 0xCC, 0x58, 0x73, 0xE7, 0x61
    };

  }

} // namespace Nuclex.Audio.Verification

#endif // UNITTEST
