#include "../include/LongArithmetic.hpp"

int main() {
    LongNumber num1("f8914126124689d123441220fb3819253221355a12358a12a53aaeb411118114fee54a344");
    LongNumber num2("a56a56a918723581a56a56a918723581976464dda56a56a918723581976464dd976464dd");

    std::cout << num1.toHexString() << std::endl;
    std::cout << num2.toHexString() << std::endl;
    
    LongNumber num3 = num1 / num2;
    
    std::cout << num3.toHexString() << std::endl;

    return 0;
}