#include "RenderImage.hpp"

int main() {
    auto buffer = ImageBuffer<112, 112>("clueless.bmp");
    ImageBuffer<50, 20> buffer2 = buffer;
    renderImageToConsole(buffer2, asciiGrayScale);

    // auto buffer3 = buffer.downscaleAVG<50, 20>();
    // renderImageToConsole(buffer3, color24bit);
}
