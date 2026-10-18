cmake_minimum_required(VERSION 3.16)

project(2048 C)

find_package(raylib REQUIRED)

add_executable(2048 main.c)

target_link_libraries(2048 PRIVATE raylib)

