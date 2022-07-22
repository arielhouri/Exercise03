cmake_minimum_required(VERSION 3.22)
project(Ex01)

set(CMAKE_CXX_STANDARD 11)

include_directories(../../../Downloads)

add_executable(Ex01
        Iris.h
        Iris.cpp)
