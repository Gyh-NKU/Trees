cmake_minimum_required(VERSION 3.20)
project(BST)

set(CMAKE_CXX_STANDARD 14)

MATH(EXPR stack_size "1024*1024*1024*10*100")

set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(BST main.cpp)
