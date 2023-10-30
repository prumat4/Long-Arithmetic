#include "../include/LongArithmetic.hpp"

int main() {
    LongNumber num1("4");
    LongNumber num2("2");


    std::cout << num1.toHexString() << std::endl << std::endl << std::endl;
    std::cout << num2.toHexString() << std::endl << std::endl << std::endl;
    
    LongNumber num3 = num1 / num2;

    std::cout << num3.toHexString() << std::endl;

    return 0;
}