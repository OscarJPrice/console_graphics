#include "ansi.hpp"
#include "Pixel.h"
#include <iostream>
namespace Intensity {
    // This is a grading of ascii intensity levels
    static constexpr const char* levels[] = {
        " ",  
        FAINT ".",
        FAINT ":", 
        ":", 
        "-", 
        "=", 
        BOLD "#", 
        BOLD "%", 
        BOLD "@",
        WHITE_BG_BRIGHT " "
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
        std::cout<<intensity<<std::endl;
        return levels[(int)(intensity*levels_size)];
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