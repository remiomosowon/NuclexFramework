﻿#region CPL License
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
#endregion

#if ENABLE_RTREES

using System;
using System.Collections.Generic;

using Microsoft.Xna.Framework;

namespace Nuclex.Game.Space {

  partial class RectangleTree<ItemType> {

    /// <summary>A node in a rectangle tree (R-Tree)</summary>
    protected class Node {

      /// <summary>Minimum bounding rectangle of the contained items</summary>
      public BoundingRectangle BoundingRectangle;

      /// <summary>Items the node contains</summary>
      public ItemType[] Items;

      /// <summary>Child nodes to this node</summary>
      public Node[] Children;

      /// <summary>Whether the node is a leaf node</summary>
      public bool IsLeaf;

    }

  }

} // namespace Nuclex.Game.Space

#endif // ENABLE_RTREES
