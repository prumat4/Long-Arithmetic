#include "LongArithmetic.hpp"

// temporary should be only line with fill(0)
LongNumber::LongNumber() {
    sign = false;
    number.fill(0);
}

LongNumber::LongNumber(std::array<uint64_t, ARRAY_SIZE> arr) : sign(false), number(arr) {}

LongNumber::LongNumber(const LongNumber& other) : sign(other.sign), number(other.number) {}

LongNumber::LongNumber(int val) {
    if(val < 0)
        sign = true;
    else 
        sign = false;

    number.at(0) = val;
}

LongNumber LongNumber::operator+(const LongNumber& other) {
    uint64_t carry = 0;
    LongNumber answer(0);

    for(int i = 0; i < ARRAY_SIZE; i++) {
        uint64_t temp = number.at(i) + other.number.at(i) + carry;
        answer.number.at(i) = temp & uint64_t(1);
        carry = temp >> 2;
    } 

    return *this;
}

LongNumber& LongNumber::operator=(const LongNumber &other){
    number = other.number;
    sign = other.sign;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const LongNumber& ln) {
    if(ln.sign)
        os << "-";

    for(const auto& element : ln.number) {
        // for (int i = 63; i >= 0; i--) {
        //     os << ((element >> i) & 1);
        // }
            // os << " ";
        os << element;
    }
    
    return os;
}
