cmake_minimum_required(VERSION 3.0)
project(sche_study CXX)

add_subdirectory(vsim)
add_executable(sche_study main.cpp)
target_link_libraries(sche_study PRIVATE vsim "-pthread")

