cmake_minimum_required(VERSION 3.10)

project(TestProject)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

set(SOURCES main.cpp)

add_executable(func_test ${SOURCES})