cmake_minimum_required(VERSION 3.1)

project(sdizo)

set(CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wendif-labels " )

set(TSOURCES catch/catch_main.cpp)
file(GLOB SOURCES "*.cpp")
add_executable(sdizo ${SOURCES} ${TSOURCES})