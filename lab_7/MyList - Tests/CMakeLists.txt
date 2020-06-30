cmake_minimum_required(VERSION 3.16)
project(MyList___Tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyList___Tests main.cpp MyList_Tests_String.cpp ../MyList/MyList.h MyList_Tests_Int.cpp)