#pragma once 

#include <iostream>
#include <array>
#include <algorithm>
#include <math.h>
#include <bitset>

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

public:
    LongNumber bitShiftToHigh(const int index) const;
    LongNumber();
    LongNumber(uint32_t someInt);
    LongNumber(std::array<uint32_t, ARRAY_SIZE> arr);
    LongNumber(const LongNumber& other);
    LongNumber(const std::string& hexString);

    LongNumber& operator = (const LongNumber& other);
    LongNumber operator + (const LongNumber& other);
    LongNumber operator * (const LongNumber& other);
    LongNumber operator - (const LongNumber& other);
    LongNumber operator / (const LongNumber& other);
    LongNumber operator % (const LongNumber& other);
    LongNumber operator << (int numBits) const; 
    LongNumber operator >> (int numBits) const;
    
    bool operator == (const LongNumber& other) const;
    bool operator != (const LongNumber& other) const;
    bool operator > (const LongNumber& other) const;
    bool operator >= (const LongNumber& other) const;
    bool operator < (const LongNumber& other) const;
    bool operator <= (const LongNumber& other) const;

    LongNumber toSquare();
    LongNumber toPowerOf(const LongNumber& power);

    std::string toBinaryString() const;
    void fromBinaryString(const std::string& binaryString);
    std::string toHexString() const;
    int firstSignificantBit() const;
};