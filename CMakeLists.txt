cmake_minimum_required(VERSION 3.10)

project(hhgen-cli LANGUAGES C)

# Set GCC as the C compiler
# set(CMAKE_C_COMPILER gcc)

# (Optional) Set additional flags for GCC (e.g., -Wall for warnings)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

if (CMAKE_BUILD_TYPE MATCHES Debug)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
endif ()

if (CMAKE_BUILD_TYPE MATCHES Release)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")
endif ()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(lib/jlib)

add_executable(hhgen-cli
               src/main.c
               src/hhgen.c
               )

target_include_directories(hhgen-cli PRIVATE
	${CMAKE_SOURCE_DIR}/lib/jlib)

target_link_libraries(hhgen-cli PRIVATE jlib jio jdate)
