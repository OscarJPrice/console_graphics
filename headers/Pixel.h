#include <stdint.h>

#ifndef PIXEL_H
#define PIXEL_H
/**
 * @brief Represents a pixel with three bytes as RGB color values.
 */
struct Pixel {
    uint8_t r; /**< The red component of the pixel color. */
    uint8_t g; /**< The green component of the pixel color. */
    uint8_t b; /**< The blue component of the pixel color. */
};

/**
 * Converts a Pixel object to an 8-bit color value.
 * This formula is taken from https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit.
 *
 * @param pixel The Pixel object to convert.
 * @return The 8-bit color value.
 */
inline uint8_t pixelTo8bitColor(const Pixel& pixel) {
    return 16 + (uint8_t)(5.0*pixel.r/255.0)*36 + (uint8_t)(5.0*pixel.g/255.0)*6 + (uint8_t)(5.0*pixel.b/255);
}

#endif