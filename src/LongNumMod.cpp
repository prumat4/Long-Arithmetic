#include "LongNumMod.hpp"

LongNumber LongNumberMod::modulus;

void LongNumberMod::initializeModulus(const LongNumber& _modulus) {
    modulus = _modulus;
}

void LongNumberMod::setModulus(const LongNumber& _modulus) {
    modulus = _modulus;
}

LongNumberMod::LongNumberMod() {
    number = LongNumber(1);
}

LongNumberMod::LongNumberMod(const LongNumber& _number) {
    number = _number;
}

LongNumberMod& LongNumberMod::operator = (const LongNumberMod& other) {
    this->number = other.number;
    return *this;
}

LongNumberMod LongNumberMod::operator + (const LongNumberMod& other) {
    int k = number.DigitCount();
    LongNumber coefficient = calculateСoefficient(k, other.number);

    LongNumber temp = this->number + other.number;
    LongNumber sum = BarretReduction(temp, modulus, coefficient);
    
    LongNumberMod res(sum);
    return res;
}

LongNumberMod LongNumberMod::operator - (const LongNumberMod& other) {
    int k = number.DigitCount();
    LongNumber coefficient = calculateСoefficient(k, other.number);

    LongNumber temp = this->number - other.number;
    LongNumber diff = BarretReduction(temp, modulus, coefficient);
    LongNumberMod res(diff);
    return res;
}

LongNumberMod LongNumberMod::operator * (const LongNumberMod& other) {
    int k = number.DigitCount();
    LongNumber coefficient = calculateСoefficient(k, other.number);

    LongNumber temp = this->number * other.number;
    LongNumber mul = BarretReduction(temp, modulus, coefficient);

    LongNumberMod res(mul);
    return res;
}

bool LongNumberMod::operator == (const LongNumberMod &other) const {
    return number == other.number;
}

LongNumberMod LongNumberMod::toSquare () {
    int k = number.DigitCount();
    LongNumber coefficient = calculateСoefficient(k, number);

    LongNumber temp = number.toSquare();
    LongNumber square = BarretReduction(temp, modulus, coefficient);

    LongNumberMod res(square);
    return res;
}

LongNumberMod LongNumberMod::toPowerOf(const LongNumberMod& power) {
    LongNumber temp(1);
    int k = number.DigitCount();
    LongNumber coefficient = calculateСoefficient(k, number);
    std::string powerInBinary = power.number.toBinaryString();

    for(int i = powerInBinary.size() - 1; i >= 0; i--) {
        if(powerInBinary.at(i) == '1') {
            temp = BarretReduction(temp * number, modulus, coefficient);
        }

        if(i > 0)
            number = BarretReduction(number.toSquare(), modulus, coefficient);
    }

    LongNumberMod res(number);
    return res;
}

void LongNumberMod::generateRandomNumber(int size) {
    number.generateRandomNumber(size);
}

std::string LongNumberMod::getNumHex() const {
    return number.toHexString();
}