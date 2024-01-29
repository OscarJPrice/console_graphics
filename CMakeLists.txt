cmake_minimum_required(VERSION 3.28)
project(ConsoleGraphics)
set(CMAKE_CXX_STANDARD 17)

include_directories(headers)
add_executable(ConsoleGraphics source/main.cpp source/ansi.cpp source/str4.cpp)

