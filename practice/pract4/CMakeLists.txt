cmake_minimum_required(VERSION 3.24)
project(pract4)

set(CMAKE_CXX_STANDARD 17)


include_directories("inc/")

add_executable(pract4 main.cpp)
file(COPY devices.txt DESTINATION /)