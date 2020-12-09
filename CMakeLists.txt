cmake_minimum_required(VERSION 3.17)
project(CDaily C)

set(CMAKE_C_STANDARD 99)

add_executable(CDaily "main.c")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")