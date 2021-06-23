cmake_minimum_required(VERSION 3.18)
project(List)

set(CMAKE_CXX_STANDARD 14)

add_executable(exe main.cpp List.h FilterCriteria.h Functors.h List.cpp Functors.cpp FilterCriteria.cpp)