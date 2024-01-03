#include "RenderImage.hpp"

int main() {
    auto buffer = ImageBuffer<1920, 1080>("mandelbrot.bmp");
    ImageBuffer<50, 20> buffer2 = buffer;
    renderImageToConsole(buffer2, color24bit);
}