cmake_minimum_required(VERSION 3.0)

project(vsim)

add_library(vsim SHARED vsim_main.cpp)
set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -O2")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

#set(LIB_NAME "vsim")

#set(LIB_SRC "vsim_main.cpp")
#set(LIB_TYPE "SHARED")



