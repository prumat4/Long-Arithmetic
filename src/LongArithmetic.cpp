#include "LongArithmetic.hpp"

// temporary should be only line with fill(0)
LongNumber::LongNumber() {
    data.fill(0);
}

LongNumber::LongNumber(std::array<uint64_t, ARRAY_SIZE> arr) : data(arr) {}

LongNumber::LongNumber(const LongNumber& other) : data(other.data) {}

LongNumber::LongNumber(int some_int) {
    data.at(0) = some_int;
}

LongNumber LongNumber::operator+(const LongNumber& other) {
    uint64_t carry = 0;
    LongNumber answer(0);

    for(int i = 0; i < ARRAY_SIZE - 1; i++) {
        uint64_t  temp = data.at(i) + other.data.at(i) + carry;
        answer.data.at(i) = temp & uint64_t(pow(2, 64) - 1);
        carry = temp >> 64;
    }

    std::cout << answer;

    return *this;
}

LongNumber& LongNumber::operator=(const LongNumber &other){
    data = other.data;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const LongNumber& ln) {
    // for(const auto& element : ln.data) {
        // for (int i = 63; i >= 0; i--) {
        //     os << ((element >> i) & 1);
        // }
            // os << " ";
        // os << element;
    // }
    for(int i = ARRAY_SIZE - 1; i >= 0; i--) {
        // os << ln.data.at(i) << " ";
        os << ln.data.at(i);
    
    }
    
    return os;
}
