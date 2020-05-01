cmake_minimum_required(VERSION 3.15)
project(Shapes)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(Shapes main.cpp IShape.cpp IShape.h ISolidShape.cpp ISolidShape.h CTriangle.cpp CTriangle.h CRectangle.cpp CRectangle.h CCircle.cpp CCircle.h CPoint.h CLineSegment.cpp CLineSegment.h CShapeProcessor.cpp CShapeProcessor.h)