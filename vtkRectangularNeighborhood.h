
// .NAME vtkRectangularNeighborhood
// .SECTION Description

#ifndef __vtkRectangularNeighborhood_h
#define __vtkRectangularNeighborhood_h

#include "vtkNeighborhood.h"

class vtkImageData;

class vtkRectangularNeighborhood : public vtkNeighborhood
{
public:
  // Description:
  // Set the center of the rectangle. (i,j,k) must be inside
  // this->Image->GetExtent().
  void SetCenter(int i, int j, int k);
  void SetCenter(int c[3]);

  // Description:
  // Set the edge lengths of the rectangle. i, j, and k must be odd.
  void SetSize(int i, int j, int k);
  void SetSize(int s[3]);

protected:
  // Description:
  // Get the pixel at (i,j,k) offset from the center of the rectangle.
  void* GetPixel(int i, int j, int k);

  // Description:
  // The size of the rectangle.
  int Size[3];

  // Description:
  // The center of the rectangle.
  int Center[3];
};

#endif
