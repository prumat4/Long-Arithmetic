#include "../include/LongNumMod.hpp"
#include <chrono>
#include <thread>

int main() {
    std::vector<int> DigitSizes = {2, 4, 8, 16, 31};

    for (const auto size : DigitSizes) {
        double TotalAdditionTime = 0.0;
        double TotalSubtractionTime = 0.0;
        double TotalMultiplicationTime = 0.0;
        double TotalDivisionTime = 0.0;

        for (int i = 0; i < 100; i++) {
            LongNumber ln1, ln2;
            ln1.generateRandomNumber(size);
            ln2.generateRandomNumber(size);

            auto AdditionStartTime = std::chrono::high_resolution_clock::now();
            LongNumber resultAdd = ln1 + ln2;
            auto AdditionEndTime = std::chrono::high_resolution_clock::now();
            TotalAdditionTime += std::chrono::duration_cast<std::chrono::nanoseconds>(AdditionEndTime - AdditionStartTime).count();

            auto SubtractionStartTime = std::chrono::high_resolution_clock::now();
            LongNumber resultSub = ln1 - ln2;
            auto SubtractionEndTime = std::chrono::high_resolution_clock::now();
            TotalSubtractionTime += std::chrono::duration_cast<std::chrono::nanoseconds>(SubtractionEndTime - SubtractionStartTime).count();

            auto MultiplicationStartTime = std::chrono::high_resolution_clock::now();
            LongNumber resultMul = ln1 * ln2;
            auto MultiplicationEndTime = std::chrono::high_resolution_clock::now();
            TotalMultiplicationTime += std::chrono::duration_cast<std::chrono::nanoseconds>(MultiplicationEndTime - MultiplicationStartTime).count();

            auto DivisionStartTime = std::chrono::high_resolution_clock::now();
            LongNumber resultDiv = ln1 / ln2;
            auto DivisionEndTime = std::chrono::high_resolution_clock::now();
            TotalDivisionTime += std::chrono::duration_cast<std::chrono::nanoseconds>(DivisionEndTime - DivisionStartTime).count();
        }

        double AverageAdditionTime = TotalAdditionTime / 100.0;
        double AverageSubtractionTime = TotalSubtractionTime / 100.0;
        double AverageMultiplicationTime = TotalMultiplicationTime / 100.0;
        double AverageDivisionTime = TotalDivisionTime / 100.0;

        std::cout << "Size " << size << std::endl;
        std::cout << "Average Addition Time: " << AverageAdditionTime << " nanoseconds" << std::endl;
        std::cout << "Average Subtraction Time: " << AverageSubtractionTime << " nanoseconds" << std::endl;
        std::cout << "Average Multiplication Time: " << AverageMultiplicationTime << " nanoseconds" << std::endl;
        std::cout << "Average Division Time: " << AverageDivisionTime << " nanoseconds" << std::endl;
        std::cout << std::endl;
    }

    for (const auto size : DigitSizes) {
        double TotalAdditionTime = 0.0;
        double TotalSubtractionTime = 0.0;
        double TotalMultiplicationTime = 0.0;

        for (int i = 0; i < 100; i++) {
            LongNumber num1, num2; 
            LongNumber modulus1;
            LongNumber modulus2;

            if(size == 2) {
                modulus1 = LongNumber("26feacecdb0dd453");
                modulus2 = LongNumber("fbaad0cb11097295d5b9f1410376f288");
            }

            if(size == 4) {
                modulus1 = LongNumber("fbaad0cb11097295d5b9f1410376f288");
                modulus2 = LongNumber("d0be1bfb748f65bb6c585b40eb159651aa5f85f18cd0f40b1fbc8054dbb00676");
            }

            if(size == 8) {
                modulus1 = LongNumber("2131d9b518bf53244c1f2545e600ea7be576eb154f420d1805d5cf330989768b");
                modulus2 = LongNumber("9372b6d6266db42f488c2a2830654b0ea1868e3be51555b9d742895eacb9dfac78e9980f5133257a6df609432abd5403e6f836e5296ebf512db550cd68cba49a");
            }

            if(size == 16) {
                modulus1 = LongNumber("795238d1435b94214cd159d03c1e0483b46f8896695f4d5499b084d819d634f0d5f34302a4531cc0b026df502d499b7dbd2db3c008b54f638ac0872400b72975");
                modulus2 = LongNumber("d69a89f0d27e48f418309973566063a0f8677392e5982e176e9925becf1122ec96090ab283f823e2fb0f033ef7f222a194a0855ce928b03c14d6cf5ad362356188e4ba3f83fa9386af782e13dfb81d292b6783c0959d9f097828b8aa27b54914c1636855b35194ab0b9b8149f30703edb9ad97e3d7a152e07b168f77cd0c2e87");
            }

            if(size == 31) 
                modulus1 = LongNumber("406b260a7f4f8997fb744018e9c880ec1ec71886e6e1e971249dc9902e477a0db2b3422f32318121ce4fcdd806524b6afb0a0a15b7f7bd7ac98c2df1967c3f2ff16c57739c854f4535dca04b10b79bd6b228ced3fa2a8c4d3d1af3b00da380d5c4a550f71dfc1124261d53931b827af49ed1340f258efc49e155937838e9b4628bc7dc0ec3e5054b37a6cdc6cda7d5733405b14b3f74e3fd94f6667406981b8517e30db4edaa763c05f4eeff1831b81d52bf954470061f5f4e4b9f90ecc924ad5839faca81f71c35ea340794b4a1081e7325329a0a4137af311d8beedaadc3c44fbcab5e228af6cb4c756f2d11ecbe7b");

            num1.generateRandomNumber(size);
            num2.generateRandomNumber(size);

            LongNumberMod ln1(num1);
            LongNumberMod ln2(num2);
            ln1.initializeModulus(modulus1); 

            auto AdditionStartTime = std::chrono::high_resolution_clock::now();
            LongNumberMod resultAdd = ln1 + ln2;
            auto AdditionEndTime = std::chrono::high_resolution_clock::now();
            TotalAdditionTime += std::chrono::duration_cast<std::chrono::nanoseconds>(AdditionEndTime - AdditionStartTime).count();

            auto SubtractionStartTime = std::chrono::high_resolution_clock::now();
            LongNumberMod resultSub = ln1 - ln2;
            auto SubtractionEndTime = std::chrono::high_resolution_clock::now();
            TotalSubtractionTime += std::chrono::duration_cast<std::chrono::nanoseconds>(SubtractionEndTime - SubtractionStartTime).count();
            
            if(size != 31) {
                ln1.initializeModulus(modulus2); 
                auto MultiplicationStartTime = std::chrono::high_resolution_clock::now();
                LongNumberMod resultMul = ln1 * ln2;
                auto MultiplicationEndTime = std::chrono::high_resolution_clock::now();
                TotalMultiplicationTime += std::chrono::duration_cast<std::chrono::nanoseconds>(MultiplicationEndTime - MultiplicationStartTime).count();
            }
        }

        double AverageAdditionTime = TotalAdditionTime / 100.0;
        double AverageSubtractionTime = TotalSubtractionTime / 100.0;
        double AverageMultiplicationTime = TotalMultiplicationTime / 100.0;

        std::cout << "Size " << size << std::endl;
        std::cout << "Average Addition Time: " << AverageAdditionTime << " milliseconds" << std::endl;
        std::cout << "Average Subtraction Time: " << AverageSubtractionTime << " milliseconds" << std::endl;
        std::cout << "Average Multiplication Time: " << AverageMultiplicationTime << " milliseconds" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}