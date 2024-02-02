#include "ImageBuffer.hpp"
#include "Intensity.hpp"
#include <iostream>
#include "ansi.hpp"

enum ColorMode {
    color8bit,
    color24bit, 
    asciiGrayScale
};

/**
 * Renders the image buffer to the console.
 * 
 * @tparam N The width of the image buffer.
 * @tparam M The height of the image buffer.
 * @param buffer The image buffer to render.
 * @param mode The color mode to use (default is color8bit).
 */
template<int N, int M>
void renderImageToConsole(const ImageBuffer<N, M>& buffer, const ColorMode mode = color8bit) {
    // Iterate over the rows of the image buffer.
    for (int i = 0; i < M; i++) {
        // The last color that was printed to the console. 
        // If the next pixel has the same color, we don't need to print the color again.
        int last_color = -1; 
        // Iterate over the columns of the image buffer.
        for(int k = 0; k < N; k++) {
            int color; 
            if (mode == asciiGrayScale) {
                // Print the intensity to the console.
                std::cout << Intensity::get(buffer(k, i));
            }
            else if (mode == color24bit) {
                // Convert the pixel to a 24 bit integer
                color = (int)(buffer(k, i).r) << 16 | (int)(buffer(k, i).g) << 8 | (int)(buffer(k, i)).b;
                if (color != last_color) {
                    std::cout << bg_color24bit(buffer(k, i).r, buffer(k, i).g, buffer(k, i).b);
                }
                last_color = color;
                std::cout << ' ';

            } 
            else {
                // Convert the pixel to an 8 bit integer. See Pixel.h for more details.
                color = Pixel::pixelTo8bitColor(buffer(k, i));
                if (color != last_color) {
                    std::cout << bg_color8bit(color);
                }
                last_color = color;
                std::cout << ' ';

            }
            // We just want to print a space character, the background is what matters.
        }
        // Reset the background color.
        std::cout << ANSI_NORMAL << '\n';
    }
    // Force the console to flush the output buffer.
    std::flush(std::cout);
}