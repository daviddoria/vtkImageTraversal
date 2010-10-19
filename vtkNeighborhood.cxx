/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkNeighborhood.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkNeighborhood.h"

#include "vtkImageData.h"
#include "vtkVector.h"

#include <vector>

//----------------------------------------------------------------------------
unsigned int vtkNeighborhood::GetNumberOfPixels()
{
  return this->Pixels.GetNumberOfPixels();
}

//----------------------------------------------------------------------------
vtkVector3i vtkNeighborhood::GetPixel(const int i)
{
  return this->Pixels.GetPixel(i);
}

//----------------------------------------------------------------------------
vtkVector3i vtkNeighborhood::GetExtent(int extent[6])
{
  // Initialize
  vtkVector3i p0 = this->GetPixel(0);
  int xmin = p0.GetX();
  int xmax = p0.GetX();
  int ymin = p0.GetY();
  int ymax = p0.GetY();
  int zmin = p0.GetZ();
  int zmax = p0.GetZ();
  
  for(unsigned int i = 0; i < this->Pixels.GetNumberOfPixels(); i++)
    {
    vtkVector3i p = this->GetPixel(i);
    if(p.GetX() < xmin)
      {
      xmin = p.GetX();
      }
    if(p.GetX() > xmax)
      {
      xmax = p.GetX();
      }

    if(p.GetY() < ymin)
      {
      ymin = p.GetY();
      }

    if(p.GetY() > ymax)
      {
      ymax = p.GetY();
      }

    if(p.GetZ() < zmin)
      {
      zmin = p.GetZ();
      }

    if(p.GetZ() > zmax)
      {
      zmax = p.GetZ();
      }
    }

  extent[0] = xmin;
  extent[1] = xmax;
  extent[2] = ymin;
  extent[3] = ymax;
  extent[4] = zmin;
  extent[5] = zmax;
}