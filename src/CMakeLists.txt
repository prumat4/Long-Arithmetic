add_library(LongArithmeticLib
    LongNum.cpp
    LongNumMod.cpp
)

target_include_directories(LongArithmeticLib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
