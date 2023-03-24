cmake_minimum_required(VERSION 3.24)
project(Parser_css)

set(CMAKE_CXX_STANDARD 17)

add_executable(Parser_css main.cpp List.h List.cpp String.h String.cpp Attribute.cpp Selector.h Selector.cpp)
