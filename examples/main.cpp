#include "LongArithmetic.hpp"
#include <array>

int main() {
    LongNumber num1 ("104D4A301BD70480050C46201F6AA95018228D200F5CA420252");
    LongNumber num2(num1);
    LongNumber num3 = num2 * num2 * num2 * num2 *num2 * num2 *num2 * num2; 

    std::cout << num1.toHexString() << std::endl;

    LongNumber power("8");
    LongNumber res = num1.toPowerOf(power);


    std::cout << res.toHexString() << std::endl << std::endl << std::endl;
    std::cout << num3.toHexString() << std::endl;


    return 0;
}