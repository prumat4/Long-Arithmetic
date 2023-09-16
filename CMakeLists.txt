cmake_minimum_required(VERSION 3.12)
project(LongArithmetic)

set(CMAKE_CXX_STANDARD 17)

add_library(LongArithmetic
    src/LongArithmetic.cpp
)

target_include_directories(LongArithmetic PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
