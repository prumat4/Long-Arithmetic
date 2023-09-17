#include "LongArithmetic.hpp"

// temporary should be only line with fill(0)
LongNumber::LongNumber() {
    sign = false;
    number.fill(0);
    
    for(int i = 0; i < number.size(); i++) {
        number.at(i) = i * 100;
    }
}

LongNumber::LongNumber(std::array<uint64_t, ARRAY_SIZE> arr) : sign(false), number(arr) {}

LongNumber::LongNumber(const LongNumber &other) : sign(other.sign), number(other.number) {}

std::ostream& operator<<(std::ostream& os, const LongNumber& ln) {
    if(ln.sign)
        os << "-";

    for(const auto& element : ln.number) {
        for (int i = 63; i >= 0; i--) {
            os << ((element >> i) & 1);
        }
            os << " ";
    }
    
    return os;
}
