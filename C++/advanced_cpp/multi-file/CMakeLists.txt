cmake_minimum_required(VERSION 3.10)
project(LoggerProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all source files
add_executable(one one.cpp Logger.cpp)
