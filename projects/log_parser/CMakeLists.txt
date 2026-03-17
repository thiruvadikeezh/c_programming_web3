cmake_minimum_required(VERSION 3.10)

project(log_parser)

set(SOURCES
	main.c
	log_parser.c
)

add_executable(log_parser ${SOURCES})
