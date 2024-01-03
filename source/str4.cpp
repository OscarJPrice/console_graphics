#include "str4.hpp"
#include <iostream>

/**
 * @brief A class that converts an 8bit number to a hex string.
 * @param num The number to convert.
*/
using std::string;
Str4::Str4(uint8_t num)  {
    bytes[0] = num/100 + '0';
    bytes[1] = (num/10)%10 + '0';
    bytes[2] = num%10 + '0';
    bytes[3] = 0;
}

std::ostream& operator<<(std::ostream& os, Str4 str) {
    return os<<str.bytes;
}

