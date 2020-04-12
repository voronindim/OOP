cmake_minimum_required(VERSION 3.15)
project(Car)

set(CMAKE_CXX_STANDARD 20)

add_executable(Car main.cpp CCar.cpp CCar.h AutoPilot.cpp AutoPilot.h Control.cpp Control.h ControlWithAutopilot.cpp ControlWithAutopilot.h)