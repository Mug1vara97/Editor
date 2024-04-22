cmake_minimum_required(VERSION 3.28)
project(Editor)

set(CMAKE_CXX_STANDARD 17)

add_executable(editor 
src/main.cpp 
src/editor.cpp 
src/editor.h 
)