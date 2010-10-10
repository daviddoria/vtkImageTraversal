#include "vtkSquareNeighborhood.h"

void vtkSquareNeighborhood::SetSize(int s)
{
  vtkRectangularNeighborhood::SetSize(s,s,s);
}