// .NAME vtkImageTraversal
// .SECTION Description

// In VTK images (0,0) is the top left corner

#ifndef __vtkImageTraversal_h
#define __vtkImageTraversal_h

class vtkImageData;

class vtkImageTraversal
{
public:
  vtkImageTraversal()
  {
    this->CurrentPixel[0] = 0; 
    this->CurrentPixel[1] = 0;
  }
  
  void SetImage(vtkImageData* image){this->Image = image;}
  bool IsValidPixel(int i, int j);
  bool IsValidPixel(int pixel[2]);
  
  void Reset()
  {
    this->CurrentPixel[0] = 0; 
    this->CurrentPixel[1] = 0;
  }
  
  bool HasNextPixel();
  void NextPixel();
  
  bool HasLeftNeighbor();
  bool HasRightNeighbor();
  bool HasTopNeighbor();
  bool HasBottomNeighbor();
  
  unsigned char GetLeftNeighbor();
  unsigned char GetRightNeighbor();
  unsigned char GetTopNeighbor();
  unsigned char GetBottomNeighbor();
  
  unsigned char GetPixel();
  
private:
  int CurrentPixel[2];
  vtkImageData* Image;
};

#endif

