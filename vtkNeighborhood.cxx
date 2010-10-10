#include "vtkNeighborhood.h"

#include "vtkImageData.h"

void vtkNeighborhood::SetImage(vtkImageData* image)
{
  this->Image = image;
}

unsigned int vtkNeighborhood::GetNumberOfPixels()
{
  return this->Pixels.size();
}

void* vtkNeighborhood::GetPixel(int i)
{
  if(i > this->GetNumberOfPixels())
    {
    std::cerr << "vtkNeighborhood::GetPixel out of bounds!" << std::endl;
    return NULL;
    }
  return this->Pixels[i];
}