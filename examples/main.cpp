#include "../include/LongArithmetic.hpp"

int main() {
    LongNumber num1("fd420fb38925a8eb41111114fe54a344");
    LongNumber num2("a56a56a918723581976464dd");

    std::cout << num1.toHexString() << std::endl;
    std::cout << num2.toHexString() << std::endl;
    
    LongNumber num3 = num1 / num2;
    
    std::cout << num3.toHexString() << std::endl;

    return 0;
}