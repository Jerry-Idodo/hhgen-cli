cmake_minimum_required(VERSION 3.10)

project(JLib LANGUAGES C)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(jlib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/jlib.c)
add_library(jio STATIC ${CMAKE_CURRENT_SOURCE_DIR}/jio.c)
add_library(jdate STATIC ${CMAKE_CURRENT_SOURCE_DIR}/jdate.c)

target_link_libraries(jio PRIVATE jlib)
target_link_libraries(jdate PRIVATE jlib jio)
