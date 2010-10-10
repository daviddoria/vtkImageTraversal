#include "vtkNeighborhoodIterator.h"

vtkNeighborhoodIterator::vtkNeighborhoodIterator()
{

}

void vtkNeighborhoodIterator::SetNeighborhood(vtkNeighborhood* n)
{
  this->Neighborhood = n;
}