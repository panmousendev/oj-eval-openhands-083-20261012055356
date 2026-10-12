cmake_minimum_required(VERSION 3.10)
project(josephus_ring C)

# Compile to executable named 'code'
add_executable(code main.c)

# Set compiler flags
target_compile_options(code PRIVATE -Wall -Wextra -O2)