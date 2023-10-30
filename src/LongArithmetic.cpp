#include "LongArithmetic.hpp"

LongNumber::LongNumber() {
    data.fill(0);
}

LongNumber::LongNumber(uint32_t someInt) {
    data.fill(0);
    data.at(0) = someInt;
}

LongNumber::LongNumber(std::array<uint32_t, ARRAY_SIZE> arr) : data(arr) {}

LongNumber::LongNumber(const LongNumber& other) : data(other.data) {}

LongNumber::LongNumber(const std::string& hexString) {
    data.fill(0);

    int len = hexString.length();
    int dataIndex = 0;
    int shift = 0;

    for (int i = len - 1; i >= 0; i--) {
        char c = hexString[i];
        uint32_t nibble = hexCharToDecimal(c);

        data[dataIndex] |= (nibble << shift);

        if (shift == 28) {
            dataIndex++;
            shift = 0;
        } else {
            shift += 4;
        }
    }
}

uint32_t LongNumber::hexCharToDecimal(char c) {
    if (c >= '0' && c <= '9')
        return static_cast<uint32_t>(c - '0');
    else if (c >= 'a' && c <= 'f')
        return static_cast<uint32_t>(c - 'a' + 10);
    else if (c >= 'A' && c <= 'F') 
        return static_cast<uint32_t>(c - 'A' + 10);
    
    return 0;
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
        
        for (int j = 31; j >= 0; j--) 
            binaryString += (value & (1 << j)) ? '1' : '0';
    }
    
    removeLeadingZeros(binaryString);

    return binaryString;
}

void LongNumber::fromBinaryString(const std::string& binaryString) {
    data.fill(0);

    int len = binaryString.length();
    int dataIndex = 0;
    uint32_t currentWord = 0;
    int shift = 0;

    for (int i = len - 1; i >= 0; i--) {
        char c = binaryString[i];

        if (c == '1') 
            currentWord |= (1 << shift);

        shift++;

        if (shift == 32) {
            data[dataIndex] = currentWord;
            currentWord = 0;
            shift = 0;
            dataIndex++;
        }
    }

    if (shift > 0)
        data[dataIndex] = currentWord;
}

std::string LongNumber::toHexString() const {
    std::string hexString;
    hexString.reserve(8 * ARRAY_SIZE);

    for (int i = data.size() - 1; i >= 0; i--) {
        uint32_t value = data[i];

        for (int j = 7; j >= 0; j--) {
            char hexDigit = static_cast<char>((value >> (j * 4)) & 0xF);
            
            if (hexDigit < 10) 
                hexString += '0' + hexDigit;
            else 
                hexString += 'A' + (hexDigit - 10);
            
        }
    }

    removeLeadingZeros(hexString);

    return hexString;
}

int LongNumber::firstSignificantBit() const {
    auto binaryString = this->toBinaryString();

    int index = binaryString.rfind("1");

    if(index != binaryString.size())
        return index;
    
    return -1;
}

int LongNumber::bitLength() const {
    std::string ans = this->toBinaryString();
    return ans.size();
}

void LongNumber::shiftDigitsToHigh(const int index) {
    if (index >= ARRAY_SIZE) {
        data.fill(0);
        return;
    }

    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        if (i - index >= 0) 
            data.at(i) = data.at(i - index);
        else 
            data.at(i) = 0;
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

LongNumber LongNumber::operator << (int numBits) {
    if (numBits <= 0) 
        return *this;

    LongNumber result(*this);

    int shiftWords = numBits / 32;
    int shiftBits = numBits % 32;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i + shiftWords < ARRAY_SIZE) 
            result.data.at(i) = data.at(i + shiftWords);
        else 
            result.data.at(i) = 0;
    }

    if (shiftBits > 0) {
        uint32_t carry = 0;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            uint32_t temp = result.data.at(i) << shiftBits;
            result.data.at(i) = (temp | carry) & 0xFFFFFFFF;
            carry = temp >> 32;
        }
    }

    return result;
}

LongNumber LongNumber::operator >> (int numBits) {
    if (numBits <= 0) 
        return *this;

    LongNumber result(*this);

    int shiftWords = numBits / 32;
    int shiftBits = numBits % 32;

    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        if (i - shiftWords >= 0) 
            result.data.at(i) = data.at(i - shiftWords);
        else 
            result.data.at(i) = 0;
    }

    if (shiftBits > 0) {
        uint32_t carry = 0;
        for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
            uint32_t temp = result.data.at(i) >> shiftBits;
            result.data.at(i) = (temp | carry) & 0xFFFFFFFF;
            carry = (data.at(i) << (32 - shiftBits)) & 0xFFFFFFFF;
        }
    }

    return result;
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

LongNumber& LongNumber::operator = (const LongNumber& other){
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

LongNumber LongNumber::operator / (const LongNumber& other) {
    std::cout << "Entering operator /" << std::endl;

    if (other == LongNumber()) 
        return LongNumber(0);

    if(*this == other)
        return LongNumber(1);

    int k = other.bitLength();
    std::cout << "k = " << k << std::endl;

    LongNumber B = other;
    std::cout << "B = " << B.toHexString() << std::endl;

    LongNumber R = *this;
    std::cout << "R = " << R.toHexString() << std::endl;

    LongNumber Q(0);
    std::cout << "Q = " << Q.toHexString() << std::endl;

    while (R >= B) {
        int t = R.bitLength();
        std::cout << "t = " << t << std::endl;

        LongNumber C = B >> (t - k);
        std::cout << "C = " << C.toHexString() << std::endl;

        if (R < C) {
            t = t - 1;
            C = B >> (t - k);
        }

        std::cout << "C (after R < C check) = " << C.toHexString() << std::endl;

        R = R - C;
        std::cout << "R (after R = R - C) = " << R.toHexString() << std::endl;

        LongNumber two(2);
        Q = Q + two.toPowerOf(t - k);
        std::cout << "Q = " << Q.toHexString() << std::endl;
    }

    return R;
}

// LongNumber LongNumber::operator % (const LongNumber& other) {
//     LongNumber quotient = (*this) / other;
//     LongNumber remainder = (*this) - (quotient * other);
//     return remainder;
// }

bool LongNumber::operator == (const LongNumber& other) const {
    for (int i = data.size() - 1; i >= 0; i--) {
        if (data.at(i) != other.data.at(i))
            return false;
    }
    return true;
}

bool LongNumber::operator != (const LongNumber& other) const {
    return !(*this == other);
}

bool LongNumber::operator > (const LongNumber& other) const {
    int i = data.size() - 1;
    while(data.at(i) == other.data.at(i))
        i--;

    if(i < 0)
        return false;

    return data.at(i) > other.data.at(i);
}

bool LongNumber::operator < (const LongNumber& other) const {
    int i = data.size() - 1;
    while(data.at(i) == other.data.at(i))
        i--;

    if(i < 0)
        return false;
    
    return data.at(i) < other.data.at(i);
}

bool LongNumber::operator <= (const LongNumber &other) const {
    return (*this < other) || (*this == other);
}

bool LongNumber::operator >= (const LongNumber &other) const {
    return (*this > other) || (*this == other);
}

LongNumber LongNumber::toSquare() {
    return (*this) * (*this);
}

LongNumber LongNumber::toPowerOf(const LongNumber& power) {
    std::string binaryRepresentation = power.toBinaryString();
    LongNumber res(1);

    for (int i = binaryRepresentation.size() - 1; i >= 0; i--) {
        if (binaryRepresentation.at(i) == '1')
            res = res * (*this);

        if (i > 0)
            *this = this->toSquare();
    }

    return res;
}