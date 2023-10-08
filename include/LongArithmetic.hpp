#pragma once 

#include <iostream>
#include <array>
#include <algorithm>
#include <math.h>

#define ARRAY_SIZE 64
// num lenght is fixed 2048 bits
// little endian (LSB is first)

class LongNumber {
private:
    /// 64*32 = 2048 btis 
    std::array<uint32_t, ARRAY_SIZE> data;
private:
    std::string removeLeadingZeros(std::string& binaryString) const;
    void shiftDigitsToHigh(const uint16_t index);
    void multiplyOneDigit(const uint32_t& digit, LongNumber& res);
    uint16_t bitLength() const;
public:
    
    LongNumber();
    LongNumber(uint64_t someInt);
    LongNumber(std::array<uint32_t, ARRAY_SIZE> arr);
    LongNumber(const LongNumber& other);

    LongNumber& operator = (const LongNumber& other);
    LongNumber operator + (const LongNumber& other);
    LongNumber operator * (const LongNumber& other);
    LongNumber operator - (const LongNumber& other);
    LongNumber operator / (const LongNumber& other);

    bool operator == (const LongNumber& other);
    bool operator != (const LongNumber& other);
    bool operator > (const LongNumber& other);
    bool operator >= (const LongNumber& other);
    bool operator < (const LongNumber& other);
    bool operator <= (const LongNumber& other);

    LongNumber toSquare();
    LongNumber toPowerOf(const LongNumber& power);

    std::string toBinaryString() const;
    std::string toHexString() const;

    int firstSignificantBit() const;

    friend std::ostream& operator << (std::ostream& os, const LongNumber& ln);
};