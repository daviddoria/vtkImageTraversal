#include "vtkPixelList.h"

vtkVector3i vtkPixelList::GetPixel(const int i)
{
  return this->pixels[i];
}

void vtkPixelList::SetPixel(const int i, const vtkVector3i p)
{
  this->pixels[i] = p;
}

unsigned int vtkPixelList::GetNumberOfPixels()
{
  return this->pixels.size();
}

void vtkPixelList::SetNumberOfPixels(const int i)
{
  this->pixels.resize(i);
}
