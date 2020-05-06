cmake_minimum_required(VERSION 3.15)
project(Shapes)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(Shapes main.cpp IShape.h ISolidShape.h CTriangle.cpp CTriangle.h
        CRectangle.cpp CRectangle.h CCircle.cpp CCircle.h CPoint.h CLineSegment.cpp CLineSegment.h CShapeProcessor.cpp CShapeProcessor.h
        ICanvasDrawable.h ICanvas.h CCanvas.cpp CCanvas.h)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Shapes sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


