/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkSquareNeighborhood.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSquareNeighborhood - describes a square neighborhood around a pixel
// .SECTION Description
// vtkSquareNeighborhood describes a square neighborhood around a pixel

#ifndef __vtkSquareNeighborhood_h
#define __vtkSquareNeighborhood_h

#include "vtkRectangularNeighborhood.h"

class vtkImageData;

class vtkSquareNeighborhood : public vtkRectangularNeighborhood
{
public:

  void SetSize(int s);
};

#endif