cmake_minimum_required(VERSION 3.10)

project(Minesweeper VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

add_executable(Minesweeper main.c)

target_include_directories(Minesweeper PUBLIC "${PROJECT_BINARY_DIR}")
