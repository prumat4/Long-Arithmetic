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
    LongNumber temp = this->number + other.number;
    LongNumber sum = temp % modulus;
    
    LongNumberMod res(sum);
    return res;
}

LongNumberMod LongNumberMod::operator - (const LongNumberMod& other) {
    LongNumber temp = this->number - other.number;
    LongNumber sub = temp % modulus;
    
    LongNumberMod res(sub);
    return res;
}

LongNumberMod LongNumberMod::operator * (const LongNumberMod& other) {
    LongNumber temp = this->number * other.number;
    LongNumber mul = temp % modulus;
    
    LongNumberMod res(mul);
    return res;
}

bool LongNumberMod::operator == (const LongNumberMod &other) const {
    return number == other.number;
}

LongNumberMod LongNumberMod::toSquare () {
    LongNumber temp = number.toSquare();
    LongNumber square = temp % modulus;
    
    LongNumberMod res(square);
    return res;
}

LongNumberMod LongNumberMod::toPowerOf(const LongNumberMod& power) {
    int k = modulus.DigitCount();
    LongNumber C(1);
    LongNumber mult = number % modulus;

    LongNumber mu = precalculations(modulus);

    std::string binaryRepresentation = power.number.toBinaryString();
    for (int i = binaryRepresentation.size() - 1; i >= 0; i--) {
        if(binaryRepresentation.at(i) == '1')
            C = reduciton(C * mult, modulus, mu);
        
        mult = reduciton(mult.toSquare(), modulus, mu);
    }
    
    return LongNumberMod(C);
}

void LongNumberMod::generateRandomNumber(int size) {
    number.generateRandomNumber(size);
}

std::string LongNumberMod::getNumHex() const {
    return number.toHexString();
}