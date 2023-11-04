#include "../include/LongArithmetic.hpp"

int main() {
    // LongNumber num1("23A6F9B50D34A7E071EC59F90C128E775FA3C0F3E1CDD13C963C64166D0DE107E98E1523DD70C92724A35E429E741E036655F4E4FA267D08079F4ABFB2D2F286AA6BCA5BFC1B135B0C3D6F4E53F5ED5381815");
    // LongNumber num2("7FD6C21CC86C06C7219C96A88141C47FEBEDD1B1742A9A2D9F4A15A8F9913088360E7313C8AA5DFA0009DFFCFB52B1C6EDBD39213D8E3F25FD40098F1CC5226D4AB6ED52FDADB34D7E4B85888C9422D");

    // std::cout << num1.toHexString() << std::endl;
    // std::cout << num2.toHexString() << std::endl;
    
    // LongNumber num3 = num1 % num2;
    
    // std::cout << num3.toHexString() << std::endl;

    LongNumber num1("182736182763817263192736812763");

    std::cout << num1.toBinaryString() << std::endl;
    
    LongNumber num2 = num1 >> 34;
    
    std::cout << num2.toBinaryString() << std::endl;

    return 0;
}