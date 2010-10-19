/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkRectangularNeighborhood.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkRectangularNeighborhood - describes a rectangular neighborhood around a pixel
// .SECTION Description
// vtkRectangularNeighborhood describes a rectangular neighborhood around a pixel

#ifndef __vtkRectangularNeighborhood_h
#define __vtkRectangularNeighborhood_h

#include "vtkNeighborhood.h"

class vtkImageData;

class vtkRectangularNeighborhood : public vtkNeighborhood
{
public:

  // Description:
  // Set the edge lengths of the rectangle. i, j, and k must be odd.
  void SetSize(int i, int j, int k);
  void SetSize(int s[3]);

protected:

  // Description:
  // The size of the rectangle.
  int Size[3];

};

#endif
