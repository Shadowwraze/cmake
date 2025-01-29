CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
PROJECT(demo-app)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_executable(demoapplication app.cpp)


target_link_libraries(demoapplication PUBLIC speaker)


target_include_directories(demoapplication PUBLIC ${CMAKE_SOURCE_DIR}/library)
