#include "ansi.hpp"

std::string fg_color8bit(uint8_t n) {
    auto it = generated_8bit_fg_colors.find(n); // Find the color in the map
    if (it != generated_8bit_fg_colors.end()) { // If the color is in the map
        return it->second;
    }
    else {
        std::string s = std::string(ANSI_ESC "38;5;") + Str4(n).data() + "m"; // Generate the color
        generated_8bit_fg_colors[n] = s; // Add the color to the map
        return s;
    }
}

std::string bg_color8bit(uint8_t n) { //same as above
    auto it = generated_8bit_bg_colors.find(n);
    if (it != generated_8bit_bg_colors.end()) {
        return it->second;
    }
    else {
        std::string s = std::string(ANSI_ESC "48;5;") + Str4(n).data() + "m";
        generated_8bit_bg_colors[n] = s;
        return s;
    }
}

// Same as above, but with 24 bit colors
std::string fg_color24bit(uint8_t r, uint8_t g, uint8_t b) {
    auto it = generated_24bit_colors.find((uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b);
    if (it != generated_24bit_colors.end()) {
        return it->second;
    }
    else {
        std::string s = std::string(ANSI_ESC "38;2;") + Str4(r).data() + ";" + Str4(g).data() + ";" + Str4(b).data() + "m";
        generated_24bit_colors[(uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b] = s;
        return s;
    }
}

// same as above
std::string bg_color24bit(uint8_t r, uint8_t g, uint8_t b) {
    auto it = generated_24bit_bg_colors.find((uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b);
    if (it != generated_24bit_bg_colors.end()) {
        return it->second;
    }
    else {
        std::string s = std::string(ANSI_ESC "48;2;") + Str4(r).data() + ";" + Str4(g).data() + ";" + Str4(b).data() + "m";
        generated_24bit_bg_colors[(uint32_t)r << 16 | (uint32_t)g << 8 | (uint32_t)b] = s;
        return s;
    }
}