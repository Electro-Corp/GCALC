cmake_minimum_required(VERSION 3.12)

project(GCALC)

# Compiler settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# SDL
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

# CTRE
find_package(CTRE REQUIRED)

# Java
find_package(JNI)

# Include directories
include_directories(src)



# Compiler executable
add_executable(GCALC
    # Java helper
    src/java.cpp
    # Graphics
    src/graphics.cpp
    src/draw/line.cpp
    src/draw/text.cpp
    src/draw/drawableFunction.cpp
    # Function
    src/function/function.cpp
    #ctre-addon
    src/ctre-consts.hpp
    src/ctreextra.hpp
    # main
    src/main.cpp
)


# Flags
target_compile_options(GCALC PUBLIC -fpermissive -g -O2)

target_link_libraries(GCALC ${SDL2_LIBRARIES} ${SDLTTF_LIBRARIES} SDL2_ttf)

target_link_libraries(GCALC ${JNI_LIBRARIES})

target_link_libraries(GCALC ${CTRE_LIBRARIES})