CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

PROJECT(vtkImageTraversal)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(PixelIteratorExample PixelIteratorExample.cxx
vtkPixelIterator.cxx)
TARGET_LINK_LIBRARIES(PixelIteratorExample vtkHybrid)

ADD_EXECUTABLE(NeighborhoodIteratorExample NeighborhoodIteratorExample.cxx
vtkPixelIterator.cxx
vtkNeighborhoodIterator.cxx
vtkNeighborhood.cxx
vtkSquareNeighborhood.cxx
vtkRectangularNeighborhood.cxx
vtkPixelList.cxx

)
TARGET_LINK_LIBRARIES(NeighborhoodIteratorExample vtkHybrid)

