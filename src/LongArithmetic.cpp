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
    int index = 0;
    int shift = 0;

    for (int i = len - 1; i >= 0; i--) {
        char c = hexString.at(i);
        uint32_t temp = hexCharToDecimal(c);

        data.at(index) |= (temp << shift);

        if (shift == 28) {
            index++;
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
        uint32_t value = data.at(i);
        
        for (int j = 31; j >= 0; j--) 
            binaryString += (value & (1 << j)) ? '1' : '0';
    }
    
    removeLeadingZeros(binaryString);

    return binaryString;
}

void LongNumber::fromBinaryString(const std::string& binaryString) {
    data.fill(0);

    int len = binaryString.length();
    int index = 0;
    uint32_t currentWord = 0;
    int shift = 0;

    for (int i = len - 1; i >= 0; i--) {
        char c = binaryString.at(i);

        if (c == '1') 
            currentWord |= (1 << shift);

        shift++;

        if (shift == 32) {
            data.at(index) = currentWord;
            currentWord = 0;
            shift = 0;
            index++;
        }
    }

    if (shift > 0)
        data.at(index) = currentWord;
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

LongNumber& LongNumber::operator = (const LongNumber& other){
    data = other.data;
    return *this;
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
    if(other > *this) {
        std::cerr << "Error: Bigger number is substracted from the smaller, returning smaller one...\n";
        return *this;
    }

    uint32_t borrow = 0;
    LongNumber difference;

    for(int i = 0; i < data.size(); i++) {
        uint64_t temp = static_cast<uint64_t>(data.at(i)) - static_cast<uint64_t>(other.data.at(i)) - borrow;

        if(temp >> 32 == 0) {
            difference.data.at(i) = static_cast<uint32_t>(temp);
            borrow = 0;
        } else {
            difference.data.at(i) = static_cast<uint32_t>(temp + (1ULL << 32));
            borrow = 1;
        }
    }

    return difference;
}

LongNumber LongNumber::bitShiftToHigh(const int index) const {
    if(index <= 0 || index >= ARRAY_SIZE)
        return *this;
    
    int numberOfWords = index / 32;
    int shifts = index % 32;
    uint32_t carry = 0;
    LongNumber C, res;

    if(shifts != 0) {
        for(int i = 0; i < ARRAY_SIZE; i++) {
            C.data.at(i) = (data.at(i) << shifts) + carry;
            carry = data.at(i) >> (32 - shifts);
        }

        for(int i = numberOfWords; i < ARRAY_SIZE; ++i)
            res.data.at(i) = C.data.at(i - numberOfWords);
        return res;
    } else {
        for (int i = 0; i < ARRAY_SIZE; i++)
            C.data.at(i) = data.at(i);

        for (int i = numberOfWords; i < ARRAY_SIZE; ++i)
            res.data.at(i) = C.data.at(i - numberOfWords);
        
        return res;
    }
}

std::pair<LongNumber, LongNumber> LongNumber::LongDivMod(const LongNumber& divisor) const {
    if (divisor == LongNumber()) 
        return std::make_pair(LongNumber(0), LongNumber(0));

    if (*this == divisor)
        return std::make_pair(LongNumber(1), LongNumber(0));

    int divisorBitLength = divisor.bitLength();
    LongNumber remainder = *this;
    LongNumber quotient(0);

    while (remainder >= divisor) {
        int remainderBitLength = remainder.bitLength();
        LongNumber shiftedDivisor = divisor.bitShiftToHigh(remainderBitLength - divisorBitLength);
        if (remainder < shiftedDivisor) {
            remainderBitLength--;
            shiftedDivisor = divisor.bitShiftToHigh(remainderBitLength - divisorBitLength);
        }
       
        remainder = remainder - shiftedDivisor;
        LongNumber one(1);
        quotient = quotient + one.bitShiftToHigh(remainderBitLength - divisorBitLength);
    }

    return std::make_pair(quotient, remainder);
}

LongNumber LongNumber::operator / (const LongNumber& divisor) {
    auto ans = LongDivMod(divisor);
    return ans.first;
}

LongNumber LongNumber::operator % (const LongNumber& divisor) {
    auto ans = LongDivMod(divisor);
    return ans.second;
}

bool LongNumber::operator == (const LongNumber& other) const {
    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        if (data.at(i) != other.data.at(i)) 
            return false;
    }
    return true;
}

bool LongNumber::operator != (const LongNumber& other) const {
    return !(*this == other);
}

bool LongNumber::operator > (const LongNumber& other) const {
    int i = ARRAY_SIZE - 1;
    for(i; i > -1; i--) {
        if(data.at(i) != other.data.at(i))
            break;
    } 

    if (i == -1) 
        return false;
    else 
        return data.at(i) > other.data.at(i); 
}

bool LongNumber::operator < (const LongNumber& other) const {
    int i = ARRAY_SIZE - 1;
    for(i; i > -1; i--) {
        if(data.at(i) != other.data.at(i))
            break;
    } 

    if (i == -1) 
        return false;
    else 
        return data.at(i) < other.data.at(i); 
}

bool LongNumber::operator <= (const LongNumber &other) const {
    return (*this == other) || (*this < other);
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