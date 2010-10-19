/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPixelIterator.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkPixelIterator.h"

#include "vtkImageData.h"

//----------------------------------------------------------------------------
vtkPixelIterator::vtkPixelIterator()
{
  this->CurrentPixel[0] = 0;
  this->CurrentPixel[1] = 0;
  this->CurrentPixel[2] = 0;
}

//----------------------------------------------------------------------------
bool vtkPixelIterator::IsValidPixel(int i, int j, int k)
{
  int extent[6];
  this->Image->GetExtent(extent);

  if((i < extent[0]) || (i > extent[1]) ||
     (j < extent[2]) || (j > extent[3]) ||
     (k < extent[4]) || (k > extent[5]))
    {
    return false;
    }
  else
    {
    return true;
    }
}

//----------------------------------------------------------------------------
void vtkPixelIterator::SetImage(vtkImageData* image)
{
  this->Image = image;

  int extent[6];
  this->Image->GetExtent(extent);
  this->CurrentPixel[0] = extent[0];
  this->CurrentPixel[1] = extent[2];
  this->CurrentPixel[2] = extent[4];
}

//----------------------------------------------------------------------------
bool vtkPixelIterator::IsValidPixel(int pixel[3])
{
  return this->IsValidPixel(pixel[0], pixel[1], pixel[2]);
}

//----------------------------------------------------------------------------
void* vtkPixelIterator::GetCurrentPixelValue()
{
  return this->Image->GetScalarPointer(CurrentPixel);
}

//----------------------------------------------------------------------------
bool vtkPixelIterator::NextPixel()
{
  // Step in x, then y, then z

  int extent[6];
  this->Image->GetExtent(extent);

  if(IsValidPixel(this->CurrentPixel[0] + 1, this->CurrentPixel[1], this->CurrentPixel[2]))
    {
    this->CurrentPixel[0]++;
    return true;
    }

  // If we get to here, we are at the x edge of the image
  if(IsValidPixel(this->CurrentPixel[0], this->CurrentPixel[1] + 1, this->CurrentPixel[2]))
    {
    this->CurrentPixel[0] = extent[0];
    this->CurrentPixel[1]++;
    return true;
    }

  // If we get to here, we are at the y edge of the image
  if(IsValidPixel(this->CurrentPixel[0], this->CurrentPixel[1], this->CurrentPixel[2] + 1))
    {
    this->CurrentPixel[0] = extent[0];
    this->CurrentPixel[1] = extent[2];
    this->CurrentPixel[2]++;
    return true;
    }

  return false;
}

//----------------------------------------------------------------------------
void vtkPixelIterator::Reset()
{
  int extent[6];
  this->Image->GetExtent(extent);
  this->CurrentPixel[0] = extent[0];
  this->CurrentPixel[1] = extent[2];
  this->CurrentPixel[2] = extent[4];
}