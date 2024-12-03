cmake_minimum_required(VERSION 3.29)
project(Calculator)

set(CMAKE_CXX_STANDARD 20)

add_executable(Calculator main.cpp
        "Basic operations.cpp"
        "Advanced operations.cpp"
        "Polish algorithm.cpp"
        calc.h
        LineToEquation.cpp
)
