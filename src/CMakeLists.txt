add_library(LongArithmeticLib
    LongArithmetic.cpp
)

target_include_directories(LongArithmeticLib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
