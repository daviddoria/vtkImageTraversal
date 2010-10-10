#include "vtkRectangularNeighborhood.h"

#include <iostream>

void vtkRectangularNeighborhood::SetCenter(int c[3])
{
  this->SetCenter(c[0], c[1], c[2]);
}

void vtkRectangularNeighborhood::SetCenter(int i, int j, int k)
{
  // This should only be called by a vtkNeighborhoodIterator, so we trust that (i,j,k) is in bounds.

  this->Center[0] = i;
  this->Center[1] = j;
  this->Center[2] = k;
}

void* vtkRectangularNeighborhood::GetPixelAtOffset(int p[3])
{
  this->GetPixelAtOffset(p[0], p[1], p[2]);
}

void* vtkRectangularNeighborhood::GetPixelAtOffset(int i, int j, int k)
{
  int index = (k * (i + j)) + (j * i) + i;
  return this->Pixels[index];
}

void vtkRectangularNeighborhood::SetSize(int s[3])
{
  this->SetSize(s[0], s[1], s[2]);
}

void vtkRectangularNeighborhood::SetSize(int i, int j, int k)
{
  if((i % 2 == 0) || (j % 2 == 0) || (k % 2 == 0) ) // If i, j, or k is even
    {
    std::cerr << "vtkRectangularNeighborhood::SetSize must be called with odd integers!" << std::endl;
    return;
    }

  this->Size[0] = i;
  this->Size[1] = j;
  this->Size[2] = k;

  this->Pixels.resize(i*j*k);
}