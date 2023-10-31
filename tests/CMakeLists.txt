find_package(GTest REQUIRED)

add_executable(LongArithmeticLibTests
    LongArithmeticTests.cpp
)

target_link_libraries(LongArithmeticLibTests
    LongArithmeticLib
    GTest::Main  
)

include(GoogleTest)
gtest_discover_tests(LongArithmeticLibTests)
