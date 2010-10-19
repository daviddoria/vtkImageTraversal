/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkRectangularNeighborhood.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkRectangularNeighborhood.h"
#include "vtkNeighborhood.h"

#include "vtkVector.h"

#include <iostream>

//----------------------------------------------------------------------------
void vtkRectangularNeighborhood::SetSize(int s[3])
{
  this->SetSize(s[0], s[1], s[2]);
}

//----------------------------------------------------------------------------
void vtkRectangularNeighborhood::SetSize(int i, int j, int k)
{
  // If the size is (1,1,1), no pixels will be stored (the only pixel is "CurrentPixel" of vtkPixelIterator).
  if((i % 2 == 0) || (j % 2 == 0) || (k % 2 == 0) ) // If i, j, or k is even
    {
    std::cerr << "vtkRectangularNeighborhood::SetSize must be called with odd integers!" << std::endl;
    return;
    }

  this->Size[0] = i;
  this->Size[1] = j;
  this->Size[2] = k;

  this->Pixels.SetNumberOfPixels(i*j*k - 0); // Don't include the center pixel

  unsigned int id = 0;
  for(int z = -k/2; z <= k/2; z++)
    {
    for(int y = -j/2; y <= j/2; j++)
      {
      for(int x = -i/2; x <= i/2; x++)      
        {
        vtkVector3i v;
        v.SetX(x); v.SetY(y), v.SetZ(z);
        this->Pixels.SetPixel(id, v);
        id++;
        }
      }
    }
}