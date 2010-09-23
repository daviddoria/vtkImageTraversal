#include <vtkSmartPointer.h>
#include <vtkImageData.h>

#include "vtkImageTraversal.h"

void GenerateData(vtkImageData*);

int main (int, char*[])
{
  vtkSmartPointer<vtkImageData> image =
    vtkSmartPointer<vtkImageData>::New();
  GenerateData(image);
  
  vtkImageTraversal it;
  it.SetImage(image);
  
  std::cout << "Reading data..." << std::endl;
  while(it.HasNextPixel())
    {
    unsigned char pixel = it.GetPixel();
    std::cout << (int)pixel << std::endl;
    it.NextPixel();
    }
  
  // Get the last pixel (annoying)
  unsigned char pixel = it.GetPixel();
  std::cout << (int)pixel << std::endl;
  
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