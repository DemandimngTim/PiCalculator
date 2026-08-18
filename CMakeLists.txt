cmake_minimum_required(VERSION 3.20)



project(PiCalculator LANGUAGES CXX)



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

find_path(GMP_INCLUDE_DIR gmp.h REQUIRED)

find_library(GMP_LIB gmp REQUIRED)



find_path(MPFR_INCLUDE_DIR mpfr.h REQUIRED)

find_library(MPFR_LIB mpfr REQUIRED)



target_include_directories(pi PRIVATE

    ${GMP_INCLUDE_DIR}

    ${MPFR_INCLUDE_DIR}

)



target_link_libraries(pi PRIVATE

    ${GMP_LIB}

    ${MPFR_LIB}

)



# Put the executable in bin/

set_target_properties(pi PROPERTIES

    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"

)
