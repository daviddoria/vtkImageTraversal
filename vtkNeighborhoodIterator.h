// .NAME vtkNeighborhoodIterator
// .SECTION Description

#ifndef __vtkNeighborhoodIterator_h
#define __vtkNeighborhoodIterator_h

#include "vtkPixelIterator.h"

class vtkImageData;

class vtkNeighborhood;

class vtkNeighborhoodIterator : public vtkPixelIterator
{
public:
  vtkNeighborhoodIterator();

  // Description:
  // Set the neighborhood to use.
  void SetNeighborhood(vtkNeighborhood* n);
protected:

  // Description:
  // The neighborhood to use.
  vtkNeighborhood* Neighborhood;
};

#endif

