#include "LongArithmetic.hpp"

int main() {
    LongNumber num1 ("104D4A301BD70480050C46201F6AA95018228D200F5CA420252");
    num1.fromBinaryString("100000100110101001010001100000001101111010111000001001000000000000101000011000100011000100000000111110110101010101001010100000001100000100010100011010010000000001111010111001010010000100000001001010010");
    LongNumber num2(num1);
    LongNumber num3 = num2 * num2 * num2 * num2 *num2 * num2 *num2 * num2; 

    std::cout << num1.toBinaryString() << std::endl << std::endl << std::endl;
    std::cout << num3.toHexString() << std::endl << std::endl << std::endl;

    // LongNumber num4 = num3 / num1;

    // std::cout << num4.toHexString() << std::endl;


    return 0;
}