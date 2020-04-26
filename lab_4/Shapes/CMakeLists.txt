cmake_minimum_required(VERSION 3.15)
project(Shapes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shapes main.cpp IShape.cpp IShape.h ISolidShape.cpp ISolidShape.h CTriangle.cpp CTriangle.h CRectangle.cpp CRectangle.h CCircle.cpp CCircle.h CPoint.h CLineSegment.cpp CLineSegment.h)