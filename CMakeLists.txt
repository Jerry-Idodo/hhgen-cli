cmake_minimum_required(VERSION 3.10)

project(hhgen-cli)

# Set GCC as the C compiler
set(CMAKE_C_COMPILER gcc)

# (Optional) Set additional flags for GCC (e.g., -Wall for warnings)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_executable(hhgen-cli
               src/main.c
               src/hhgen.c
       	       src/lib/jlib/jlib.c
               src/lib/jlib/jio.c
               src/lib/jlib/jdate.c
               )

# target_include_directories(hhgen-cli PRIVATE lib/jlib)
