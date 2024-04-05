cmake_minimum_required(VERSION 3.12)

project(GCALC)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SDL
find_package(SDL2 REQUIRED)

# Include directories
include_directories(src)

# Compiler executable
add_executable(GCALC
    # Graphics
    src/graphics.cpp
    src/draw/line.cpp
    # main
    src/main.cpp
)


# Flags
target_compile_options(GCALC PUBLIC -fpermissive -g -O2)

target_link_libraries(GCALC ${SDL2_LIBRARIES})