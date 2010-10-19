// .NAME vtkImageTraversal
// .SECTION Description

#ifndef __vtkNeighborhood_h
#define __vtkNeighborhood_h

class vtkImageData;
class vtkVector3i;

#include <vector>

#include "vtkPixelList.h"

class vtkNeighborhood
{
public:
  vtkNeighborhood(){}
  

  // Description:
  // Get the number of pixels in the neighborhood.
  unsigned int GetNumberOfPixels();

  // Description:
  // Get a pixel location.
  vtkVector3i GetPixel(const int i);

  // Description:
  // Get the extent of the neighborhood.
  vtkVector3i GetExtent(int extent[6]);

protected:

  vtkPixelList Pixels;
  
};

#endif