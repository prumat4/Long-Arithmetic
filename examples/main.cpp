#include "../include/LongNumMod.hpp"

int main() {
    LongNumber num1("8349C1D0A8B38D63B809DEB8B2A8A3");
    LongNumber num2("E9A855F40E9D13ABE9D192F99B123C");
    LongNumber modulus("746fc08325b7cb4f4140a64fc439e91d627b30b6bb9df2bfe86624c1029be0478880efc574fac609281697a6cdb6781cc5b13f68");
    
    LongNumber a = gcd(num1, num2);
    std::cout << a.toHexString() << std::endl;

    LongNumber f("C9");
    LongNumberMod ln1(num1);
    LongNumberMod ln3(num1);
    LongNumberMod ln4(f);
    const LongNumberMod ln2(num2);
    ln1.initializeModulus(modulus);

    LongNumberMod ans = ln1 + ln1 + ln1 + ln1 + ln1 + ln1 + ln1 + ln1 + ln1 + ln1 + ln1 + ln1 + ln1 + ln1 + ln1 ;
    std::cout << ans.getNumHex() << std::endl;    
    
    ans = ln1 * ln4;
    std::cout << ans.getNumHex() << std::endl;    


    // std::cout << num1.toHexString() << std::endl;
    // std::cout << num2.toHexString() << std::endl;
    
    // LongNumber num3 = gcd(num1, num2);
    
    // std::cout << num3.toHexString() << std::endl;

    return 0;
}