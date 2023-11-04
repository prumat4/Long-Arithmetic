#pragma once 

#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>

#define ARRAY_SIZE 64
// num lenght is fixed 2048 bits
// little endian (LSB is first)

class LongNumber {
private:
    std::array<uint32_t, ARRAY_SIZE> data;

private:
    std::string removeLeadingZeros(std::string& binaryString) const;
    void shiftDigitsToHigh(const int index);
    void multiplyOneDigit(const uint32_t& digit, LongNumber& res);
    int bitLength() const;
    uint32_t hexCharToDecimal(char c);
    LongNumber bitShiftToHigh(const int index) const;
    std::pair<LongNumber, LongNumber> LongDivMod(const LongNumber& divisor) const;

public:
    LongNumber();
    LongNumber(uint32_t someInt);
    LongNumber(std::array<uint32_t, ARRAY_SIZE> arr);
    LongNumber(const LongNumber& other);
    LongNumber(const std::string& hexString);

    LongNumber& operator = (const LongNumber& other);
    LongNumber operator + (const LongNumber& other);
    LongNumber operator * (const LongNumber& other);
    LongNumber operator - (const LongNumber& other);
    LongNumber operator / (const LongNumber& divisor);
    LongNumber operator % (const LongNumber& other);
    
    LongNumber toSquare();
    LongNumber toPowerOf(const LongNumber& power);
    int firstSignificantBit() const;

    bool operator == (const LongNumber& other) const;
    bool operator != (const LongNumber& other) const;
    bool operator > (const LongNumber& other) const;
    bool operator >= (const LongNumber& other) const;
    bool operator < (const LongNumber& other) const;
    bool operator <= (const LongNumber& other) const;

    std::string toBinaryString() const;
    void fromBinaryString(const std::string& binaryString);
    std::string toHexString() const;
};