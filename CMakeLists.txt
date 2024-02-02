cmake_minimum_required(VERSION 3.28)
project(ConsoleGraphics)
set(CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED)

include_directories(headers)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(ConsoleGraphics source/main.cpp source/ansi.cpp source/str4.cpp)

target_link_libraries(ConsoleGraphics ${Boost_LIBRARIES})
