#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkVector.h>

#include "vtkNeighborhoodIterator.h"
#include "vtkRectangularNeighborhood.h"

void GenerateData(vtkImageData*);

int main (int, char*[])
{
  vtkSmartPointer<vtkImageData> image =
    vtkSmartPointer<vtkImageData>::New();
  GenerateData(image);

  vtkRectangularNeighborhood neighborhood;
  neighborhood.SetSize(3,3,1);

  vtkNeighborhoodIterator it;
  it.SetImage(image);
  it.SetNeighborhood(neighborhood);

  std::cout << "Reading data..." << std::endl;
  do // visit each pixel in the image
    {
    for(unsigned int i = 0; i < it.GetNumberOfPixelsInNeighborhood(); i++) // visit all the neighbors of the current pixel
      {
      unsigned char* pixel = static_cast<unsigned char*>(it.GetPixelValue(i));
      std::cout << (int)(*pixel) << std::endl;
      }
    }while(it.NextPixel());

  return EXIT_SUCCESS;
}

void GenerateData(vtkImageData* image)
{
  image->SetDimensions(2,3,1);
  image->SetNumberOfScalarComponents(1);
  image->SetScalarTypeToUnsignedChar();

  int* dims = image->GetDimensions();
  std::cout << "Creating data..." << std::endl;
  for(int y = 0; y < dims[1]; y++)
    {
    for(int x = 0; x < dims[0]; x++)
      {
      unsigned char* pixel = static_cast<unsigned char*>(image->GetScalarPointer(x,y,0));
      pixel[0] = x + y;
      std::cout << (int)pixel[0] << std::endl;
      }
    }
}