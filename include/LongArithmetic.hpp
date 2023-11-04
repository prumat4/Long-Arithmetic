#pragma once 

#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
#include <random>

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
    LongNumber operator << (const int index) const;
    LongNumber operator >> (const int index) const;

    bool operator == (const LongNumber& other) const;
    bool operator != (const LongNumber& other) const;
    bool operator > (const LongNumber& other) const;
    bool operator >= (const LongNumber& other) const;
    bool operator < (const LongNumber& other) const;
    bool operator <= (const LongNumber& other) const;
    
    LongNumber toSquare();
    LongNumber toPowerOf(const LongNumber& power);
    int firstSignificantBit() const;

    std::string toBinaryString() const;
    void fromBinaryString(const std::string& binaryString);
    std::string toHexString() const;
    LongNumber killLastDigits(int index);
    int DigitCount() const;
    LongNumber generateRandomNumber(const int numberOfDigits);
};

LongNumber gcd(LongNumber num1, LongNumber num2);
LongNumber lcm(LongNumber num1, LongNumber num2);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                    // move in separate file 

class LongNumberMod {
private:
    LongNumber number;
    LongNumber modulo;
public:
    LongNumberMod();
    LongNumberMod(const LongNumber& _number, const LongNumber& _modulo);
    
    LongNumberMod operator = (const LongNumberMod& other);
    LongNumberMod operator + (const LongNumberMod& other);
    LongNumberMod operator - (const LongNumberMod& other);
};