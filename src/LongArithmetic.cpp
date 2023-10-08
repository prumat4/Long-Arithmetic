#include "LongArithmetic.hpp"

LongNumber::LongNumber() {
    data.fill(0);
}

std::string LongNumber::removeLeadingZeros(std::string& binaryString) const {
    size_t startPos = binaryString.find_first_not_of('0');
    if (startPos != std::string::npos) 
        binaryString = binaryString.substr(startPos);
    else 
        binaryString = "0"; 

    return binaryString;
}

std::string LongNumber::toBinaryString() const {
    std::string binaryString;
    
    for (int i = data.size() - 1; i >= 0; i--) {
        uint32_t value = data[i];
        
        for (int j = 31; j >= 0; j--) {
            binaryString += (value & (1 << j)) ? '1' : '0';
        }
    }
    
    removeLeadingZeros(binaryString);

    return binaryString;
}

LongNumber::LongNumber(std::array<uint32_t, ARRAY_SIZE> arr) : data(arr) {}

LongNumber::LongNumber(const LongNumber& other) : data(other.data) {}

void LongNumber::shiftDigitsToHigh(const uint16_t index) {
    if (index >= ARRAY_SIZE) {
        data.fill(0);
        return;
    }

    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        if (i - index >= 0) {
            data[i] = data[i - index];
        } else {
            data[i] = 0;
        }
    }
}

void LongNumber::multiplyOneDigit(const uint32_t& digit, LongNumber& res) {
    uint32_t carry = 0;

    for(int i = 0; i < data.size(); i++) {
        uint64_t temp = static_cast<uint64_t>(data.at(i)) * static_cast<uint64_t>(digit) + carry;
        res.data.at(i) = static_cast<uint32_t>(temp & 0xFFFFFFFF);
        carry = static_cast<uint32_t>(temp >> 32);
    }

    res.data.at(ARRAY_SIZE - 1) = carry;
}

LongNumber LongNumber::operator * (const LongNumber& other) {
    LongNumber res;

    for (int i = 0; i < data.size(); i++) {
        LongNumber temp;
        multiplyOneDigit(other.data.at(i), temp);
        temp.shiftDigitsToHigh(i); 
        res = res + temp; 
    }

    return res;
}

// should be smth that makes sense, because we have toBinaryString and will have toDecimal & toHex
// probably this is useless and its should bit shift operation)
// but wotk on it later
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
        uint64_t temp = static_cast<uint64_t>(data.at(i)) - static_cast<uint64_t>(other.data.at(i)) - borrow;

        if(temp >= 0) {
            difference.data.at(i) = static_cast<uint32_t>(temp);
            borrow = 0;
        } else {
            // 1ULL = telling compiler that this 1 is unsigned long long type
            difference.data.at(i) = static_cast<uint32_t>(temp + (1ULL << 32));
            borrow = 1;
        }
    }

    return difference;
}

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

LongNumber LongNumber::toSquare() {
    return (*this) * (*this);
}

LongNumber LongNumber::toPowerOf(const LongNumber& power) {
    std::string binaryRepresentation = power.toBinaryString();
    LongNumber res;

    for(int i = 0; i <= binaryRepresentation.length(); i++) {
        if(binaryRepresentation.at(i) == '1')
            res = res * (*this);
        
        toSquare();
    }

    return res;
}