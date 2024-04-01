cmake_minimum_required(VERSION 3.8)
project(ReverseCodeArithmetic)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE sources "src/*.cpp")

file(GLOB_RECURSE headers "include/*.h")

add_executable(ReverseCodeArithmetic ${sources} ${headers})
