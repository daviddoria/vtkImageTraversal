/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkNeighborhoodIterator.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkNeighborhoodIterator - iterate over the pixels in an image carrying a neighborhood
// .SECTION Description
// vtkNeighborhoodIterator allows a user to iterate over the pixels in an image
// keeping track of the relative locations of a neighborhood

#ifndef __vtkNeighborhoodIterator_h
#define __vtkNeighborhoodIterator_h

#include "vtkPixelIterator.h"

class vtkImageData;

#include "vtkNeighborhood.h"

class vtkNeighborhoodIterator : public vtkPixelIterator
{
public:
  vtkNeighborhoodIterator();

  // Description:
  // Set the neighborhood to use.
  void SetNeighborhood(vtkNeighborhood n);

  // Description:
  // Get the ith pixel of the neighborhood.
  void* GetPixelValue(const int i);

  // Description:
  // Get the number of pixels in the neighborhood.
  int GetNumberOfPixelsInNeighborhood();

  // Description:
  // Move the iterator to the next pixel. Returns false if the end of the image is reached,
  // returns true otherwise.
  bool NextPixel();
  
protected:

  // Description:
  // The neighborhood to use.
  vtkNeighborhood Neighborhood;

  bool NearBorder;
};

#endif

