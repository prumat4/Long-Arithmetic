#include "../include/LongNumMod.hpp"

int main() {
    LongNumber num1("104D4A301BD70480050C46201F6AA95018228D200F5CA420252");
    LongNumber num2("8");
    LongNumber modulus("104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252104D4A301BD70480050C46201F6AA95018228D200F5CA420252");

    LongNumberMod ln1(num1);
    const LongNumberMod ln2(num2);
    ln1.initializeModulus(modulus);

    LongNumberMod ans = ln1.toPowerOf(ln2);

    std::cout << ans.getNumHex() << std::endl;    

    // std::cout << num1.toHexString() << std::endl;
    // std::cout << num2.toHexString() << std::endl;
    
    // LongNumber num3 = gcd(num1, num2);
    
    // std::cout << num3.toHexString() << std::endl;

    return 0;
}