#include "LongArithmetic.hpp"

int main() {
    LongNumber l1(8282821), l2(71257361), l3(0);
    l3 = l1 + l2;
    std::cout << l3;
    return 0;
}