CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
PROJECT(applied_library)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(speaker SHARED speaker.cpp)

target_include_directories(speaker PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
