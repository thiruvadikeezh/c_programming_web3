cmake_minimum_required(VERSION 3.16)

project(string_sanitizer_c)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(string_sanitizer
	main.c
	)

target_compile_options(string_sanitizer PRIVATE
	-Wall
	-Wextra
	-Werror
	)



