cmake_minimum_required(VERSION 3.21)

project(1553_security_lab C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_subdirectory(firmware/bc)
add_subdirectory(firmware/rt)
