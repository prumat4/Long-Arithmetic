#include "LongArithmetic.hpp"
#include <array>

int main() {
    std::array<uint32_t, ARRAY_SIZE> a0 = {
        1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30, 31, 32,
        33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48,
        49, 50, 51, 52, 53, 54, 55, 56,
        57, 58, 59, 60, 61, 62, 63, 64
    };

    std::array<uint32_t, ARRAY_SIZE> a1 = {
        1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30, 31, 32,
        33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48,
        49, 50, 51, 52, 53, 54, 55, 56,
        57, 58, 59, 60, 61, 62, 4294967295, 64
    };
// 4294967295
    std::array<uint32_t, ARRAY_SIZE> a3 = {
        1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30, 31, 32,
        0, 0, 0, 0, 0, 0, 0, 0,  
        0, 0, 0, 0, 0, 0, 0, 0,  
        0, 0, 0, 0, 0, 0, 0, 0,  
        0, 0, 0, 0, 0, 0, 0, 0,  
    };
    
    std::array<uint32_t, ARRAY_SIZE> a4 = {
        1, 2, 3, 4, 5, 6, 7, 8,
        9, 10, 11, 12, 13, 14, 15, 16,
        17, 18, 19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30, 31, 32,
        0, 0, 0, 0, 0, 0, 0, 0,  
        0, 0, 0, 0, 0, 0, 0, 0,  
        0, 0, 0, 0, 0, 0, 0, 0,  
        0, 0, 0, 0, 0, 0, 0, 0,  
    };

    std::array<uint32_t, 64> a2 = {
        23360318, 20253581, 25021172, 28647940, 4154237, 34708518, 39387448, 385128,
        118430, 12752451, 6182186, 6341351, 26472536, 37697060, 14229011, 41615,
        7248121, 17945356, 39329201, 26190158, 5341197, 25650693, 6842432, 28036749,
        7353532, 9187920, 41231015, 10144286, 19548756, 3288086, 9516068, 41937968,
        4623354, 10096323, 19418228, 37014214, 9828430, 32265317, 27624423, 37797054,
        980990, 36112053, 34038738, 38378300, 24707883, 8054930, 36303350, 17348961,
        19095002, 32247792, 32168738, 7239689, 6275522, 22229482, 30524967, 9335526,
        7065090, 38941350, 16108098, 25307346, 32942741, 5293154, 29192264, 17093795
    };
    
    // LongNumber ln0(a0);
    // std::cout << ln0.toBinaryString() << std::endl << std::endl;

    // LongNumber ln1(a2);
    // std::cout << ln1.toBinaryString() << std::endl << std::endl;
    
    // std::cout << "ln0\n" << ln0 << std::endl;
    // std::cout << "ln1\n" << ln1 << std::endl;
    
    // LongNumber ln3 = ln0 + ln1;
    // LongNumber ln4 = ln1 - ln0;
    // LongNumber ln5 = ln1 * ln0;
    // std::cout << "ln3\n" << ln3 << std::endl;
    // std::cout << ln3.toBinaryString() << std::endl << std::endl;
    // std::cout << ln4.toBinaryString() << std::endl << std::endl;
    // std::cout << ln5.toBinaryString() << std::endl << std::endl;


    // LongNumber ln6(a3);
    // LongNumber ln7(a3);
    // LongNumber ln8 = ln7 / ln6;
    // std::cout << ln6.toBinaryString() << std::endl << std::endl;
    // std::cout << ln7.toBinaryString() << std::endl << std::endl;
    // std::cout << ln8.toBinaryString() << std::endl << std::endl;

    LongNumber ln1(1844674407370551615);
    std::cout << ln1.toBinaryString() << std::endl;
    ln1 = ln1 << 2;
    std::cout << ln1.toBinaryString() << std::endl;

    LongNumber ln0(1844674407370551615);
    std::cout << ln0.toBinaryString() << std::endl;
    ln0 = ln0 >> 2;
    std::cout << ln0.toBinaryString() << std::endl;

    return 0;
}