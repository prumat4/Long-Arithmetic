add_executable(LongArithmeticLibTests
    LongArithmeticTests.cpp
)

target_link_libraries(LongArithmeticLibTests
    LongArithmeticLib
)

add_test(LongArithmeticLibTests LongArithmeticLibTests)
