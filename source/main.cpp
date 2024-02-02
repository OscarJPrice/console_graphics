#include "RenderImage.hpp"
#include <iostream>

int main() {
    auto buffer = ImageBuffer<50, 28>("clueless.bmp");
    renderImageToConsole(buffer, color24bit);
    std::cout << "..." << std::endl;
    ImageBuffer<50, 30> buffer2 = buffer;

    renderImageToConsole(buffer2, asciiGrayScale);


    // auto buffer3 = buffer.downscaleAVG<50, 20>();
    // renderImageToConsole(buffer3, color24bit);
}
