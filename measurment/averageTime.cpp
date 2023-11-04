#include "../include/LongNumMod.hpp"
#include <chrono>
#include <thread>

int main() {
    std::vector<int> DigitSizes = {2, 4, 8, 16, 32};

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

    return 0;
}