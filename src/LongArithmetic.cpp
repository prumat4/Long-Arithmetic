#include "LongArithmetic.hpp"

LongNumber::LongNumber() {
    data.fill(0);
}

LongNumber::LongNumber(uint64_t someInt) {
    data.fill(0);

    data.at(0) = static_cast<uint32_t>(someInt & 0xFFFFFFFF);

    if (someInt > 0xFFFFFFFF)
        data.at(1) = static_cast<uint32_t>((someInt >> 32) & 0xFFFFFFFF);
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

        // Combine the nibble into the appropriate uint32_t value within the data array
        data[dataIndex] |= (nibble << shift);

        // Move to the next uint32_t value when necessary
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
    std::string ans = toBinaryString();
    return ans.size();
}

void LongNumber::shiftDigitsToHigh(const uint16_t index) {
    if (index >= ARRAY_SIZE) {
        data.fill(0);
        return;
    }

    for (int i = ARRAY_SIZE - 1; i >= 0; i--) {
        if (i - index >= 0) 
            data[i] = data[i - index];
        else 
            data[i] = 0;
        
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

std::string getStr(int n) {
    std::string num = "1";

    for(int i = 0; i < n; i++)
        num += "0";

    return num;
}

LongNumber LongNumber::operator / (const LongNumber& other) {
    LongNumber divisor = other;
    int divisorBitLength = divisor.bitLength();

    LongNumber residue = *this;
    LongNumber fraction;

    while(residue >= divisor) {
        LongNumber temp;
        int residueBitLength = residue.bitLength();
        divisor.shiftDigitsToHigh(residueBitLength - divisorBitLength);
        temp = divisor;

        if(residue < temp) {
            residueBitLength--;
            divisor.shiftDigitsToHigh(residueBitLength - divisorBitLength);
            temp = divisor;
        }

        residue = residue - temp;
        
        LongNumber power(getStr(residueBitLength - divisorBitLength));
        fraction = fraction + power;
    }

    return fraction;
}

bool LongNumber::operator == (const LongNumber& other) const {
    for (int i = data.size() - 1; i >= 0; i--) {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}

bool LongNumber::operator != (const LongNumber& other) const {
    return !(*this == other);
}

bool LongNumber::operator > (const LongNumber& other) const {
    for (int i = data.size() - 1; i >= 0; i--) {
        if (data[i] > other.data[i])
            return true;
        else if (data[i] < other.data[i])
            return false;
    }
    return false;
}

bool LongNumber::operator < (const LongNumber& other) const {
    for (int i = data.size() - 1; i >= 0; i--) {
        if (data[i] < other.data[i])
            return true;
        else if (data[i] > other.data[i])
            return false;
    }
    return false;
}

bool LongNumber::operator <= (const LongNumber &other) const {
    return (*this < other) || (*this == other);
}

bool LongNumber::operator >= (const LongNumber &other) const {
    return (*this > other) || (*this == other);
}

LongNumber LongNumber::operator >> (const int shiftCount) {
    LongNumber result = *this;
    
    for (int i = 0; i < shiftCount; i++) {
        uint32_t carry = 0;
        for (int j = 0; j < ARRAY_SIZE; j++) {
            uint32_t temp = result.data[j];
            result.data[j] = (temp >> 1) | (carry << 31);
        }
    }
    
    return result;
}

LongNumber LongNumber::operator << (const int shiftCount) {
    LongNumber result = *this;
    
    for (int i = 0; i < shiftCount; i++) {
        uint32_t carry = 0;
        for (int j = ARRAY_SIZE - 1; j >= 0; j--) {
            uint32_t temp = result.data[j];
            result.data[j] = (temp << 1) | carry;
            carry = (temp >> 31) & 1;
        }
    }
    
    return result;
}

LongNumber LongNumber::toSquare() {
    return (*this) * (*this);
}

LongNumber LongNumber::toPowerOf(const LongNumber& power) {
    std::string binaryRepresentation = power.toBinaryString();
    LongNumber res;

    for(int i = 0; i <= binaryRepresentation.size(); i++) {
        if(binaryRepresentation.at(i) == '1')
            res = res * (*this);
        
        toSquare();
    }

    return res;
}