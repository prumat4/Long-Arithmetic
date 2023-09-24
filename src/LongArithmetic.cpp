#include "LongArithmetic.hpp"

LongNumber::LongNumber() {
    data.fill(0);
}

LongNumber::LongNumber(std::array<uint32_t, ARRAY_SIZE> arr) : data(arr) {}

LongNumber::LongNumber(const LongNumber& other) : data(other.data) {}

std::ostream& operator << (std::ostream& os, const LongNumber& ln) {
    // for(const auto& element : ln.data) {
    //     for (int i = 31; i >= 0; i--) {
    //         os << ((element >> i) & 1);
    //     }
    // }
    for(int i = 0; i < ln.data.size(); i++) {
        os << i << ": ";
        os << (ln.data.at(i)) << std::endl;
    }

    return os;
}


LongNumber& LongNumber::operator = (const LongNumber &other){
    data = other.data;

    return *this;
}

LongNumber& LongNumber::operator + (const LongNumber& other) {
    uint32_t carry = 0;

    for(int i = 0; i < data.size(); i++) {
        uint64_t temp = data.at(i) + other.data.at(i) + carry;
        data.at(i) = temp & uint64_t(pow(2, 32) - 1);
        carry = temp >> 32;
    }

    return *this;
}