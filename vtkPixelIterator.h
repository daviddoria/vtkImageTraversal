/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkPixelIterator.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkPixelIterator - iterate over the pixels in an image
// .SECTION Description
// vtkPixelIterator offloads the work of the image traversal when writing algorithms,
// which is often the most complicated part of the code.
// Typical usage:
// vtkPixelIterator it;
// it.SetImage(image);

// do
// {
// unsigned char* pixel = static_cast<unsigned char*>(it.GetPixel());
// std::cout << (int)(*pixel) << std::endl;
// }while(it.NextPixel());

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
  virtual bool NextPixel();

  // Description:
  // Get a pointer to the current pixel. The user is responsible for casting it to
  // the appropriate type.
  void* GetCurrentPixelValue();

protected:
  // Description:
  // The current position of the iterator.
  int CurrentPixel[3];

  // Description:
  // The image which the iterator iterates over.
  vtkImageData* Image;
};

#endif

