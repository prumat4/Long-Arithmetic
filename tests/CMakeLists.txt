find_package(GTest REQUIRED)

add_executable(LongArithmeticTests
    LongNumTests.cpp
    LongNumModTests.cpp
)

target_link_libraries(LongArithmeticTests
    LongArithmeticLib
    GTest::Main  
)

include(GoogleTest)
gtest_discover_tests(LongArithmeticTests)
