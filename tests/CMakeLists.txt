# could be issues in this file (do not run tests yet)

enable_testing()

include(GoogleTest)

add_executable(test_LongNumber
    test_LongNumber.cpp
)

target_link_libraries(test_LongNumber
    MyLongArithmeticLib
    gtest
    gtest_main
)

gtest_discover_tests(test_LongNumber)
