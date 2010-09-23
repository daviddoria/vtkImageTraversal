#include "vtkImageTraversal.h"

#include "vtkImageData.h"

bool vtkImageTraversal::IsValidPixel(int i, int j)
{
  int size[3];
  this->Image->GetDimensions(size);

  if((i < 0) || (i >= size[0]) || (j < 0) || (j >= size[1]))
    {
    return false;
    }
  else
    {
    return true;
    }
}

bool vtkImageTraversal::IsValidPixel(int pixel[2])
{
  return this->IsValidPixel(pixel[0], pixel[1]);
}

// Check for neighbors
bool vtkImageTraversal::HasLeftNeighbor()
{
  return this->IsValidPixel(CurrentPixel[0]-1, CurrentPixel[1]);
}

bool vtkImageTraversal::HasRightNeighbor()
{
  return this->IsValidPixel(CurrentPixel[0]+1, CurrentPixel[1]);
}

bool vtkImageTraversal::HasTopNeighbor()
{
  return this->IsValidPixel(CurrentPixel[0], CurrentPixel[1]-1);
}

bool vtkImageTraversal::HasBottomNeighbor()
{
  return this->IsValidPixel(CurrentPixel[0], CurrentPixel[1]+1);
}

unsigned char vtkImageTraversal::GetPixel()
{
  unsigned char* pixel = static_cast<unsigned char*>(this->Image->GetScalarPointer(CurrentPixel[0],CurrentPixel[1],0));
  return pixel[0];
}

// Access neighbors
unsigned char vtkImageTraversal::GetLeftNeighbor()
{
  unsigned char* pixel = static_cast<unsigned char*>(this->Image->GetScalarPointer(CurrentPixel[0]-1,CurrentPixel[1],0));
  return pixel[0];
}

unsigned char vtkImageTraversal::GetRightNeighbor()
{
  unsigned char* pixel = static_cast<unsigned char*>(this->Image->GetScalarPointer(CurrentPixel[0]+1,CurrentPixel[1],0));
  return pixel[0];
}

unsigned char vtkImageTraversal::GetTopNeighbor()
{
  unsigned char* pixel = static_cast<unsigned char*>(this->Image->GetScalarPointer(CurrentPixel[0],CurrentPixel[1]-1,0));
  return pixel[0];
}

unsigned char vtkImageTraversal::GetBottomNeighbor()
{
  unsigned char* pixel = static_cast<unsigned char*>(this->Image->GetScalarPointer(CurrentPixel[0],CurrentPixel[1]+1,0));
  return pixel[0];
}

void vtkImageTraversal::NextPixel()
{
  // Iterate over the image from left to right, top to bottom
  if(this->HasRightNeighbor())
    {
    this->CurrentPixel[0]++;
    return;
    }
  
  // If we get to here, we are at the right edge of the image
  if(this->HasBottomNeighbor())
    {
    this->CurrentPixel[0] = 0;
    this->CurrentPixel[1]++;
    return;
    }
    
  // If we get to here, we are done, move the iterator back to the beginning
  this->Reset();  
}

bool vtkImageTraversal::HasNextPixel()
{
  if(this->HasRightNeighbor() || this->HasBottomNeighbor())
    {
    return true;
    }
  
  return false;
}