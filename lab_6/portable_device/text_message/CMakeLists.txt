cmake_minimum_required(VERSION 3.13)

project(text_message)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PUBLIC
    "${PROJECT_SOURCE_DIR}/include/text_message.h"
    "${PROJECT_SOURCE_DIR}/src/text_message.c"
)

target_link_libraries(${PROJECT_NAME} 
        pico_stdlib
        hardware_spi
        ili9341
        )

target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")