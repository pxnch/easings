cmake_minimum_required(VERSION 3.23)
project(easings)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE LIB lib/*.hh)

add_library(easings_lib ${LIB})

set_target_properties(easings_lib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(easings example/main.cc)

target_include_directories( easings PUBLIC lib/ )
