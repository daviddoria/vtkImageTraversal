#ifndef PixelList
#define PixelList

#include <vector>

#include "vtkVector.h"

class vtkPixelList
{
public:
  // Description:
  // Get a pixel location
  vtkVector3i GetPixel(const int i);

  // Description:
  // Set a pixel location.
  void SetPixel(const int i, const vtkVector3i p);

  // Description:
  // Get the number of pixels in the neighborhood.
  unsigned int GetNumberOfPixels();

  // Description:
  // Size the pixel vector.
  void SetNumberOfPixels(const int i);

private:
  std::vector<vtkVector3i> pixels;
};

#endif