cmake_minimum_required(VERSION 3.20)

project(PiCalculator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Hide compiler commands
set(CMAKE_VERBOSE_MAKEFILE OFF)

# Sources
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
)

add_executable(pi
    main.cpp
    ${SOURCES}
)

target_include_directories(pi PRIVATE
    include
)

# GMP + MPFR
find_library(GMP_LIB gmp REQUIRED)
find_library(MPFR_LIB mpfr REQUIRED)

target_link_libraries(pi
    ${GMP_LIB}
    ${MPFR_LIB}
)
