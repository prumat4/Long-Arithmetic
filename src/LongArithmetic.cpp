#include "LongArithmetic.hpp"

LongNumber::LongNumber() {
    data.fill(0);
}

std::string LongNumber::toBinaryString() const {
    std::string binaryString;
    
    for (int i = data.size() - 1; i >= 0; i--) {
        uint32_t value = data[i];
        
        
        for (int j = 31; j >= 0; j--) {
            binaryString += (value & (1 << j)) ? '1' : '0';
        }
    }
    
    return binaryString;
}

LongNumber::LongNumber(std::array<uint32_t, ARRAY_SIZE> arr) : data(arr) {}

LongNumber::LongNumber(const LongNumber& other) : data(other.data) {}

// uint32_t LongNumber::multiplyOneDigit(const LongNumber& num, const uint32_t& digit, uint32_t& answer) {
//     uint32_t carry = 0;

//     for(int i = 0; i < num.data.size(); i++) {
//         uint64_t temp = (num.data.at(i) * digit) + carry;
//         answer.data.at(i) = temp & uint64_t(pow(2, 32) - 1);
//         carry = temp >> 32;
//     }
//     // mb should ne size() - 1
//     num.data.at(data.size()) = carry;
// }

std::ostream& operator << (std::ostream& os, const LongNumber& ln) {
    // for(const auto& element : ln.data) {
    //     for (int i = 31; i >= 0; i--) {
    //         os << ((element >> i) & 1);
    //     }
    // }
    for(int i = 0; i < ln.data.size(); i++) {
        os << (ln.data.at(i)) << " ";
    }
    os << std::endl;

    return os;
}

LongNumber& LongNumber::operator = (const LongNumber &other){
    data = other.data;

    return *this;
}

LongNumber LongNumber::operator + (const LongNumber& other) {
    uint32_t carry = 0;
    LongNumber sum;

    for(int i = 0; i < data.size(); i++) {
        uint64_t temp = static_cast<uint64_t>(data.at(i)) + static_cast<uint64_t>(other.data.at(i)) + carry;
        sum.data.at(i) = static_cast<uint32_t>(temp & 0xFFFFFFFF);
        carry = static_cast<uint32_t>(temp >> 32); 
    }

    return sum;
}

LongNumber LongNumber::operator - (const LongNumber& other) {
    uint32_t borrow = 0;
    LongNumber difference;
    
    for(int i = 0; i < data.size(); i++) {
        uint64_t temp = data.at(i) - other.data.at(i);

        if(temp >= 0) {
            difference.data.at(i) = temp;
            borrow = 0;
        } else {
            difference.data.at(i) = pow(2, 32) + temp;
            borrow = 1;
        }
    }

    return difference;
}

// LongNumber LongNumber::operator * (const LongNumber& other) {
//     LongNumber result;

//     for(int i = 0; i < data.size(); i++) {
//         uint64_t temp = multiplyOneDigit();
//     }
// }

bool LongNumber::operator == (const LongNumber& other) {
    int i = data.size() - 1;
    
    while(data.at(i) == other.data.at(i))
        i--;

    return i == -1;
}

bool LongNumber::operator != (const LongNumber& other) {
    return !(*this == other);
}

bool LongNumber::operator > (const LongNumber& other) {
    int i = data.size() - 1;
    
    while(data.at(i) == other.data.at(i))
        i--;

    return data.at(i) > other.data.at(i);
}

bool LongNumber::operator < (const LongNumber& other) {
    return !(*this > other);
}

