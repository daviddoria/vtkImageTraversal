// .NAME vtkPixelIterator
// .SECTION Description

#ifndef __vtkPixelIterator_h
#define __vtkPixelIterator_h

class vtkImageData;

class vtkPixelIterator
{
public:
  vtkPixelIterator();

  // Description:
  // Set the image that the iterator will operate on.
  void SetImage(vtkImageData* image);

  // Description:
  // Check if the pixel is inside the image extent.
  bool IsValidPixel(int i, int j, int k);
  bool IsValidPixel(int pixel[3]);

  // Description:
  // Move the iterator to the beginning of the image.
  void Reset();

  // Description:
  // Move the iterator to the next pixel. Returns false if the end of the image is reached,
  // returns true otherwise.
  bool NextPixel();

  // Description:
  // Get a pointer to the current pixel. The user is responsible for casting it to
  // the appropriate type.
  void* GetPixel();

protected:
  // Description:
  // THe current position of the iterator.
  int CurrentPixel[3];

  // Description:
  // The image which the iterator iterates over.
  vtkImageData* Image;
};

#endif

