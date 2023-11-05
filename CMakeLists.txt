cmake_minimum_required(VERSION 3.12)
project(LongArithmeticLib)

set(CMAKE_CXX_STANDARD 14)

# Build the source file of a library 
add_subdirectory(src)

# Build the tests
enable_testing()
add_subdirectory(tests)

# Build the example
add_subdirectory(examples)

# Build the measurments file
add_subdirectory(report)
