cmake_minimum_required(VERSION 3.16)
project(Shapes_Tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shapes_Tests main.cpp ../Shapes/CCircle.cpp ../Shapes/CCircle.h CCircle_tests.cpp
        ../Shapes/CLineSegment.cpp ../Shapes/CLineSegment.h CLineSegment_tests.cpp
        ../Shapes/CRectangle.cpp ../Shapes/CRectangle.h CRectangle_tests.cpp
        ../Shapes/CTriangle.cpp ../Shapes/CTriangle.h CTriangle_tests.cpp CMockedCanvas.cpp CMockedCanvas.h
        ../Shapes/CShapeProcessor.cpp ../Shapes/CShapeProcessor.h CShapeProcessor_tests.cpp
        ../Shapes/CCanvas.cpp ../Shapes/CCanvas.h)

include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Shapes_Tests sfml-system sfml-window sfml-graphics sfml-audio sfml-network)