cmake_minimum_required(VERSION 3.1)

project(sdizo)

set(CMAKE_CXX_STANDARD 17)


file(GLOB SOURCES "*.cpp")
add_executable(sdizo ${SOURCES})

