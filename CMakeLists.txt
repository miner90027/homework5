cmake_minimum_required(VERSION 3.19)
project(homework5)

set(CMAKE_CXX_STANDARD 17)

add_executable(homework5 main.cpp myreadwrite.hpp Rational.hpp)
add_executable(recursion recursion.cpp StopWatch.cpp StopWatch.hpp)