#include "../include/LongArithmetic.hpp"

int main() {
    LongNumber num1("E775FA3C0F3E1CDD13C963C64166D0DE107E98E1523DD70C9");
    LongNumber num2("E775FA3C0F3E1CDD13C963C64166D0DE10719246781672487");
    LongNumber modulo("E1CDD13C963C64166D0DE107E98E1523DD70C9E3AE314");

    LongNumberMod ln1(num1, modulo);
    LongNumberMod ln2(num2, modulo);

    ln1 + ln2;
    ln1 - ln2;
    

    // std::cout << num1.toHexString() << std::endl;
    // std::cout << num2.toHexString() << std::endl;
    
    // LongNumber num3 = gcd(num1, num2);
    
    // std::cout << num3.toHexString() << std::endl;

    return 0;
}