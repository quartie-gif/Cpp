cmake_minimum_required(VERSION 3.1)
project (Lab12)

#----------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE   ON)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O2")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#----------------------------------------------------------------------------
# prevent for in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

#----------------------------------------------------------------------------
set(PROJECT_LINK_DIRECTORY ${PROJECT_SOURCE_DIR})
add_compile_options(${CMAKE_CXX_FLAGS})

#----------------------------------------------------------------------------
include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

#----------------------------------------------------------------------------
# Add the executable
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
