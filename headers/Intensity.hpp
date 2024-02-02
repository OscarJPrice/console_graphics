#include "ansi.hpp"
#include "Pixel.h"
#include <iostream>
namespace Intensity {
    // This is a grading of ascii intensity levels
    static constexpr const char* levels[] = {
        " ",  
        ".",
        ":", 
        "-", 
        "=", 
        "#", 
        "%", 
        "@",
        //WHITE_BG_BRIGHT " " ANSI_NORMAL
    };
    //obvious
    static constexpr int levels_size = sizeof(levels)/sizeof(const char*);

    /**
     * @brief Retrieves the corresponding character representation for a given intensity level.
     * 
     * @param intensity The intensity level. Must be between 0 and 1.
     * @return The character representation of the intensity level.
     */
    static inline const char* get(double intensity) {
        return levels[(int)(intensity*levels_size) *(intensity > 0) * (intensity < 1) + (intensity >= 1) * (levels_size - 1)];
    }

    /**
     * @brief Retrieves the corresponding character representation for a given pixel.
     * 
     * @param pixel The pixel to get the intensity of.
     * @return The character representation of the intensity of the pixel.
     */
    static inline const char* get(const Pixel& pixel) {
        return get((pixel.r + pixel.g + pixel.b)/3.0/255.0);
    }
};