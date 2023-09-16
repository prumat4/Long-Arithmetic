#pragma once 

#include <iostream>
#include <vector>

class LongNumber {
private:
    // 255 cells max and each cell is 64 bits => 255*64=16320 bits number 
    // uint64_t* data;
    // uint8_t size;
    // bool sign;

    // 
    // uint64_t data[64];
    // bool sign;


    ///
    // uint64_t* data;
    // const uint8_t size = 64;

public:
    void print();

};