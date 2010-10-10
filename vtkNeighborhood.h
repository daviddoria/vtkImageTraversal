// .NAME vtkImageTraversal
// .SECTION Description

#ifndef __vtkNeighborhood_h
#define __vtkNeighborhood_h

class vtkImageData;

#include <vector>

class vtkNeighborhood
{
public:
  // Description:
  // Set the image that the neighborhood refers to.
  void SetImage(vtkImageData* image);

  // Description:
  // Get the number of pixels that the iterator contains.
  unsigned int GetNumberOfPixels();

  // Description:
  // Get the ith pixel of the neighborhood.
  void* GetPixel(int i);

protected:
  std::vector<void*> Pixels;
  vtkImageData* Image;
};

#endif