cmake_minimum_required(VERSION 3.16)

project( strobe C)

find_package(raylib REQUIRED)

add_executable(strobe main.c)

target_link_libraries(strobe PRIVATE raylib)
