cmake_minimum_required(VERSION 3.20)
project(BirthdayGreeting3)

set(CMAKE_CXX_STANDARD 14)

add_executable(BirthdayGreeting3 main.cpp)

add_subdirectory(src)
add_subdirectory(test)
