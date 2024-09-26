cmake_minimum_required(VERSION 3.12.4)
project(cppds VERSION 0.1.0 LANGUAGES C CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib)
add_subdirectory(test)
