cmake_minimum_required(VERSION 3.20)
project(bleeper_c)

set(CMAKE_CXX_STANDARD 14)

add_executable(bleeper_c main.cpp bleeper.cpp bleeper.h)
