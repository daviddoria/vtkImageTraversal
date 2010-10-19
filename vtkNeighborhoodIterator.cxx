/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkNeighborhoodIterator.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkNeighborhoodIterator.h"

#include "vtkImageData.h"

vtkNeighborhoodIterator::vtkNeighborhoodIterator()
{
  this->NearBorder = true;
}

bool vtkNeighborhoodIterator::NextPixel()
{
  // Move the center pixel
  vtkPixelIterator::NextPixel();
  
}

void vtkNeighborhoodIterator::SetNeighborhood(vtkNeighborhood n)
{
  this->Neighborhood = n;
}

void* vtkNeighborhoodIterator::GetPixelValue(const int i)
{
  if(this->NearBorder == false) // Get the pixel without checking
    {
    return this->Image->GetScalarPointer(this->Neighborhood.GetPixel(i).GetData());
    }
  else
    {
    int imageExtent[6];
    this->Image->GetExtent(imageExtent);

    vtkVector3i p = this->Neighborhood.GetPixel(i);

    if(this->CurrentPixel[0] + p.GetX() >= imageExtent[0] && this->CurrentPixel[0] + p.GetX() <= imageExtent[1] &&
      this->CurrentPixel[1] + p.GetY() >= imageExtent[2] && this->CurrentPixel[1] + p.GetY() <= imageExtent[3] &&
      this->CurrentPixel[2] + p.GetZ() >= imageExtent[4] && this->CurrentPixel[2] + p.GetZ() <= imageExtent[5])
      {
      return this->Image->GetScalarPointer(this->Neighborhood.GetPixel(i).GetData());
      }
    else
      {
      return NULL;
      }
    }
}

int vtkNeighborhoodIterator::GetNumberOfPixelsInNeighborhood()
{
  return this->Neighborhood.GetNumberOfPixels();
}