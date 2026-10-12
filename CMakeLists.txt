cmake_minimum_required(VERSION 3.10)
project(josephus_ring)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compile to executable named 'code'
add_executable(code main.cpp)

# Set compiler flags
target_compile_options(code PRIVATE -Wall -Wextra -O2)