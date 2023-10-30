#include "../include/LongArithmetic.hpp"

int main() {
    LongNumber num1("7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
    LongNumber num2("80000000000000000000000000000000800000000000000000000000000000008000000000000000000000000000000");


    std::cout << num1.toHexString() << std::endl << std::endl << std::endl;
    std::cout << num2.toHexString() << std::endl << std::endl << std::endl;
    
    LongNumber num3 = num1 / num2;

    std::cout << num3.toHexString() << std::endl;

    return 0;
}