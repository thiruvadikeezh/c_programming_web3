cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico2_w)

include(pico_sdk_import.cmake)

project(pico_tcp_client C CXX ASM)

pico_sdk_init()

add_executable(pico_tcp_client
    main.c
)

pico_enable_stdio_usb(pico_tcp_client 1)
pico_enable_stdio_uart(pico_tcp_client 0)

target_include_directories(pico_tcp_client PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(pico_tcp_client
    pico_stdlib
    pico_cyw43_arch_lwip_threadsafe_background
)

pico_add_extra_outputs(pico_tcp_client)
