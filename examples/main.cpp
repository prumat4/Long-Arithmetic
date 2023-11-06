#include "../include/LongNumMod.hpp"

int main() {
    LongNumber num1("a9694988354c96530b1a58f8ad59569af0d402ab53d275ddb5cb393f47c6b098977f181ab889d3c5ceb96b9f3c0702c947856481d654c691d0f736fa2ef7aa0fbec62224e467f741e53edf8c8fe82c13fb90ac66eee37a975f16dd9faafd213c538711bbea34fbfd8b4330e17409d5c35313743d5dea5a82d34d99a10ac9223b");
    LongNumber num2("cbe75e23d145c3dc78d76739b63d337cc33268e08ce4ea7319c38b7d057b1747d59010759f3b015858dc5a9d05ddbbd3ef41a368ba1ca6d8a6d967f2fed6b7033e7f56d46beae7c259cce870e0879f49849c956b6b6810be90d0c50c54daaef41b2b1c6e3c7b2ed35da549a7c95fd551841ea90e4196e8272b42ea3dba7cdcef");
    LongNumber mod("d0a166bef0f8cd687a755ce64c4736e2621fe749af3c4170354c55a2728037612cf3b134550036e2de888e049ee782ab82ab99ba3442a3b4b8eb21c9f79778cff4ce0c2109a02fd18163e5155146d156b92176c03ba2b87ee53ba78217529616eea6e8432b0f736b09e30e89f3ceeaea11fb94dacd994e1fd8a6059cc14a58b2");

    LongNumber num3 = num1 - num2;
    std::cout << num3.toHexString() << std::endl;

    LongNumberMod ln1(num1);
    LongNumberMod ln2(num2);
    ln1.initializeModulus(mod);

    // std::cout << ln1.getNumHex() << std::endl;
    // std::cout << ln2.getNumHex() << std::endl;
    
    // LongNumberMod ln3 = ln1 + ln2;
    // std::cout << ln3.getNumHex() << std::endl;
    
    // ln3 = ln1 - ln2;
    // std::cout << ln3.getNumHex() << std::endl;
    
    auto ln3 = ln1 * ln2;
    std::cout << ln3.getNumHex() << std::endl;

    // ln3 = ln1.toPowerOf(ln2);
    // std::cout << ln3.getNumHex() << std::endl;

    // auto n = gcd(num1, num2);
    // std::cout << n.toHexString() << std::endl;

    return 0;
}