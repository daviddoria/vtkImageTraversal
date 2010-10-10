// .NAME vtkSquareNeighborhood
// .SECTION Description

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