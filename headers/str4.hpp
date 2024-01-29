#include <stdint.h>
#include <string>

#pragma once

/**
 * @brief A class that represents a max four character string.
*/
#include <iostream>
class Str4 {   

    char bytes[4];

public:
    friend std::ostream& operator << (std::ostream& os, Str4 str);

    /**
     * @brief Constructs a Str4 object from a string literal.
     * 
     * @param str The string literal to construct the Str4 object from.
     */
    inline const char* data() {
        return bytes;
    }

    /**
     * @brief Constructs a Str4 object with the specified number.
     *
     * @param num The number to be stored in the Str4 object.
     */
    Str4(uint8_t num);
};
/**
 * @brief Overloads the << operator to allow printing Str4 objects.
 * 
 * @param os The output stream to write to.
 * @param str The Str4 object to be printed.
 * @return std::ostream& The output stream after writing the Str4 object.
 */
std::ostream& operator << (std::ostream& os, Str4 str);