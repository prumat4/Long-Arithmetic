#include "LongNum.hpp"
class LongNumberMod {
private:
    LongNumber number;
    static LongNumber modulus;
public:
    LongNumberMod();
    LongNumberMod(const LongNumber& _number);
    
    LongNumberMod& operator = (const LongNumberMod& other);
    LongNumberMod operator + (const LongNumberMod& other);
    LongNumberMod operator - (const LongNumberMod& other);
    LongNumberMod operator * (const LongNumberMod& other);
    
    LongNumberMod toSquare();
    LongNumberMod toPowerOf(const LongNumberMod& power);
    static void initializeModulus(const LongNumber& _modulo);
    static void setModulus(const LongNumber& _modulo);
    std::string getNumHex() const;
};