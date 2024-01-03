/**
 * @file defines.h
 * @brief Defines ANSI escape sequences for styling text in terminal applications.
 *
 * This file includes macros for various ANSI escape sequences which are used
 * to format text output in terminal applications, such as changing colors, styles, 
 * and controlling cursor movements.
 * https://en.wikipedia.org/wiki/ANSI_escape_code
 *
 * @note This file doesn't cover all ANSI escape sequences, only those used in this project. 
 * Compatibility with all terminal types is not guaranteed.
 */

#ifndef __ansi_HPP
#define __ansi_HPP

    // Base ANSI escape sequence start
    #define ANSI_ESC "\033["

    // Resets any ANSI formatting to the terminal's default
    #define ANSI_NORMAL "\033[0m"

    // Foreground color definitions
    #define BLACK_FG ANSI_ESC "30m"           // Black foreground
    #define RED_FG ANSI_ESC "31m"             // Red foreground
    #define GREEN_FG ANSI_ESC "32m"           // Green foreground
    #define YELLOW_FG ANSI_ESC "33m"          // Yellow foreground
    #define BLUE_FG ANSI_ESC "34m"            // Blue foreground
    #define MAGENTA_FG ANSI_ESC "35m"         // Magenta foreground
    #define CYAN_FG ANSI_ESC "36m"            // Cyan foreground
    #define WHITE_FG ANSI_ESC "37m"           // White foreground
    #define GRAY_FG ANSI_ESC "90m"            // Gray foreground
    #define RED_FG_BRIGHT ANSI_ESC "91m"      // Bright red foreground
    #define GREEN_FG_BRIGHT ANSI_ESC "92m"    // Bright green foreground
    #define YELLOW_FG_BRIGHT ANSI_ESC "93m"   // Bright yellow foreground
    #define BLUE_FG_BRIGHT ANSI_ESC "94m"     // Bright blue foreground
    #define MAGENTA_FG_BRIGHT ANSI_ESC "95m"  // Bright magenta foreground
    #define CYAN_FG_BRIGHT ANSI_ESC "96m"     // Bright cyan foreground
    #define WHITE_FG_BRIGHT ANSI_ESC "97m"    // Bright white foreground

    // Background color definitions
    #define BLACK_BG ANSI_ESC "40m"           // Black background
    #define RED_BG ANSI_ESC "41m"             // Red background
    #define GREEN_BG ANSI_ESC "42m"           // Green background
    #define YELLOW_BG ANSI_ESC "43m"          // Yellow background
    #define BLUE_BG ANSI_ESC "44m"            // Blue background
    #define MAGENTA_BG ANSI_ESC "45m"         // Magenta background
    #define CYAN_BG ANSI_ESC "46m"            // Cyan background
    #define WHITE_BG ANSI_ESC "47m"           // White background
    #define GRAY_BG ANSI_ESC "100m"           // Gray background
    #define RED_BG_BRIGHT ANSI_ESC "101m"     // Bright red background
    #define GREEN_BG_BRIGHT ANSI_ESC "102m"   // Bright green background
    #define YELLOW_BG_BRIGHT ANSI_ESC "103m"  // Bright yellow background
    #define BLUE_BG_BRIGHT ANSI_ESC "104m"    // Bright blue background
    #define MAGENTA_BG_BRIGHT ANSI_ESC "105m" // Bright magenta background
    #define CYAN_BG_BRIGHT ANSI_ESC "106m"    // Bright cyan background
    #define WHITE_BG_BRIGHT ANSI_ESC "107m"   // Bright white background

    // Text style definitions
    #define NORMAL ANSI_ESC "0m"            // Normal style
    #define BOLD ANSI_ESC "1m"              // Bold style
    #define BRIGHT BOLD                       // Alias for bold
    #define FAINT ANSI_ESC "2m"             // Faint style
    #define ITALIC ANSI_ESC "3m"            // Italic style
    #define UNDERLINE ANSI_ESC "4m"         // Underlined text
    #define SLOW_BLINK ANSI_ESC "5m"        // Slow blink
    #define RAPID_BLINK ANSI_ESC "6m"       // Rapid blink
    #define STRIKETHROUGH ANSI_ESC "9m"     // Strikethrough
    #define FONT_DEFAULT ANSI_ESC "10m"     // Default font
    #define FRAKTUR ANSI_ESC "20m"          // Fraktur style

    // More text style options
    #define DOUBLE_UNDERLINE_or_unbold ANSI_ESC "21m"// Double underline or unbold
    #define NORMAL_INTENSITY ANSI_ESC "22m"          // Normal intensity
    #define NOT_ITALIC_or_NOT_FRAKTUR ANSI_ESC "23m" // Neither italic nor Fraktur
    #define UNDERLINE_OFF ANSI_ESC "24m"             // Turns off underline
    #define BLINK_OFF ANSI_ESC "25m"                 // Turns off blinking

    // Border styles
    #define FRAMED ANSI_ESC "51m"                    // Framed text
    #define ENCIRCLED ANSI_ESC "52m"                 // Encircled text
    #define OVERLINED ANSI_ESC "53m"                 // Overlined text
    #define NOT_FRAMED_or_ENCIRCLED ANSI_ESC "54m"   // Neither framed nor encircled
    #define NOT_OVERLINED ANSI_ESC "55m"             // Turns off overline


    #include <iostream>
    #include "str4.hpp"
    #include <map>

    // Cursor control sequences
    inline void cursor_up(int n) {
        std::cout<< ANSI_ESC << n << "A";
    }
    inline void cursor_down(int n) {
        std::cout<< ANSI_ESC << n << "B";
    }
    inline void cursor_forward(int n) {
        std::cout<< ANSI_ESC << n << "C";
    }
    inline void cursor_backward(int n) {
        std::cout<< ANSI_ESC << n << "D";
    }
    inline void cursor_next_line(int n) {
        std::cout<< ANSI_ESC << n << "E";
    }
    inline void cursor_previous_line(int n) {
        std::cout<< ANSI_ESC << n << "F";
    }
    inline void cursor_horizontal_absolute(int n) {
        std::cout<< ANSI_ESC << n << "G";
    }
    inline void cursor_to(int n, int m) {
        std::cout<< ANSI_ESC << n << ";" << m << "H";
    }
    inline void cursor_to_alt(int n, int m) {
        std::cout<< ANSI_ESC << n << ";" << m << "f";
    }   
    // Erase and scroll commands

    enum EraseMode {
        TO_END = 0, // Erase from the current cursor position to the end of the current line
        TO_BEGINNING = 1, // Erase from the current cursor position to the start of the current line
        ENTIRE = 2 // Erase the entire current line
    };

    inline void erase_display(EraseMode m) {
        std::cout<< ANSI_ESC << m << "J";
    }
    inline void erase_line(EraseMode m) {
        std::cout<< ANSI_ESC << m << "K";
    }
    inline void scroll_up(int n) {
        std::cout<< ANSI_ESC << n << "S";
    }
    inline void scroll_down(int n) {
        std::cout<< ANSI_ESC << n << "T";
    }



    static std::map<uint8_t, std::string> generated_8bit_fg_colors;
    static std::map<uint8_t, std::string> generated_8bit_bg_colors;
    static std::map<uint32_t, std::string> generated_24bit_colors;
    static std::map<uint32_t, std::string> generated_24bit_bg_colors;

    /**
     * @brief Returns the ANSI escape sequence for setting the foreground color to an 8-bit value.
     * 
     * @param n The 8-bit value representing the desired color.
     * @return The ANSI escape sequence for setting the foreground color.
     */
    std::string fg_color8bit(uint8_t n);

    /**
     * @brief Generates an ANSI escape sequence for setting the foreground color using 8-bit RGB values.
     * 
     * This function takes three 8-bit RGB values (r, g, b) and generates an ANSI escape sequence
     * that sets the foreground color to the corresponding color. It uses a 6x6x6 color cube to map
     * the RGB values to a 256-color palette.
     * 
     * @param r The red component of the RGB color (0-255).
     * @param g The green component of the RGB color (0-255).
     * @param b The blue component of the RGB color (0-255).
     * @return The ANSI escape sequence for setting the foreground color.
     */
    inline std::string fg_color8bit(uint8_t r, uint8_t g, uint8_t b) {
        //uses 6x6x6 color cube
        return fg_color8bit(16 + 36*(r/51) + 6*(g/51) + (b/51));
    }

    /**
     * @brief Returns a string representing the ANSI escape code for setting the background color to the specified 8-bit color.
     * 
     * @param n The 8-bit color value.
     * @return A string representing the ANSI escape code.
     */
    std::string bg_color8bit(uint8_t n);

    /**
     * @brief Generates an ANSI escape sequence for setting the background color using 8-bit RGB values.
     * 
     * This function takes three 8-bit RGB values (r, g, b) and generates an ANSI escape sequence
     * that sets the background color to the corresponding color in the 6x6x6 color cube.
     * 
     * @param r The red component of the RGB color (0-255).
     * @param g The green component of the RGB color (0-255).
     * @param b The blue component of the RGB color (0-255).
     * @return The ANSI escape sequence for setting the background color.
     */
    inline std::string bg_color8bit(uint8_t r, uint8_t g, uint8_t b) {
        //uses 6x6x6 color cube
        return bg_color8bit(16 + 36*(r/51) + 6*(g/51) + (b/51));
    }

    /**
     * @brief Returns a string representing a 24-bit forgront color in the RGB ansi escape format.
     * 
     * This function takes three parameters representing the red, green, and blue
     * color components and returns a string containing the ANSI escape sequence
     * for setting the background color to the specified RGB value.
     * 
     * @param r The red component of the color (0-255).
     * @param g The green component of the color (0-255).
     * @param b The blue component of the color (0-255).
     * @return std::string An ansi escape sequence in the color format "\e[38;2;r;g;bm".
     */
    std::string fg_color24bit(uint8_t r, uint8_t g, uint8_t b);

    /**
     * @brief Function to generate a 24-bit background color ANSI escape sequence.
     * 
     * This function takes three parameters representing the red, green, and blue
     * color components and returns a string containing the ANSI escape sequence
     * for setting the background color to the specified RGB value.
     * 
     * @param r The red color component (0-255).
     * @param g The green color component (0-255).
     * @param b The blue color component (0-255).
     * @return std::string An ansi escape sequence in the color format "\e[38;2;r;g;bm".
     */
    std::string bg_color24bit(uint8_t r, uint8_t g, uint8_t b);

#endif


