#include "../include/LongNumMod.hpp"

int main() {
    LongNumber num1("23a6f9b50d34a7e071ec59f90c123a6f9b50d34a7e071ec59f90c123a6f9b50d34a7e071ec59f90c123a6f9b50d34a7e071ec59f90c1");
    LongNumber num2("d52fdadb34d7e4b85888c9422dd52fdadb34d7e4b85888c9422dd52fdadb34d7e4b85888c9422dd52fdadb34d7e4b85888c9422d");
    LongNumber mod("746fc08325b7cb4f4140a64fc439e91d627b30b6bb9df2bfe86624c1029be0478880efc574fac609281697a6cdb6781cc5b13f68");

    // LongNumber num3 = num2 / num1;
    // std::cout << num3.toHexString() << std::endl;

    LongNumberMod ln1(num1);
    LongNumberMod ln2(num2);
    ln1.initializeModulus(mod);

    // std::cout << ln1.getNumHex() << std::endl;
    // std::cout << ln2.getNumHex() << std::endl;
    
    // LongNumberMod ln3 = ln1 + ln2;
    // std::cout << ln3.getNumHex() << std::endl;
    
    // ln3 = ln1 - ln2;
    // std::cout << ln3.getNumHex() << std::endl;
    
    auto ln3 = ln1.toPowerOf(ln2);
    std::cout << ln3.getNumHex() << std::endl;

    // ln3 = ln1.toPowerOf(ln2);
    // std::cout << ln3.getNumHex() << std::endl;

    // auto n = gcd(num1, num2);
    // std::cout << n.toHexString() << std::endl;

    return 0;
}