cmake_minimum_required(VERSION 3.15)
project(Car___Tests)

set(CMAKE_CXX_STANDARD 20)

add_executable(Car___Tests main.cpp testsAutoPilot.cpp testsCar.cpp testsControl.cpp ../Car/CCar.cpp ../Car/CCar.h ../Car/AutoPilot.cpp ../Car/AutoPilot.h ../Car/Control.cpp ../Car/Control.cpp ../Car/Control.h ../Car/ControlAutoPilot.cpp ../Car/ControlAutoPilot.h testsControlAutoPilot.cpp MockCCar.cpp MockCCar.h)
