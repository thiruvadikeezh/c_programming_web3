cmake_minimum_required(VERSION 3.16)

project (string_sanitizer_practice)

set(CMAKE_C_STANDARD 99)

add_executable(string_formatting
	test.c
	)

target_compile_options(string_formatting PRIVATE
	-Wall
	-Wextra
	-Werror
	)

