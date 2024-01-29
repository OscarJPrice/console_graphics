# Console Graphics
## Description
This is a simple library for drawing in the console. It is written in C++ and uses Ansi escape codes to draw in the console. It is reasonably fast. 

## Usage
For now, the most involved thing you can do is render an image as specially colors space characters into the console. The image must be of the 24-bit BMP format. The image is scaled to fit the console window. 

```cpp
#include "RenderImage.hpp"

int main() {
    auto buffer = ImageBuffer<1920, 1080>("mandelbrot.bmp");
    ImageBuffer<50, 20> buffer2 = buffer;
    renderImageToConsole(buffer2, color24bit);
}
```

The `ImageBuffer` class is a template class that takes the width and height of the image. The `renderImageToConsole` function takes an `ImageBuffer` and a `ColorMode` enum. The `ColorMode` enum is used to determine how the image is rendered. The `color24bit` enum renders the image as 24-bit color space characters. The `color8bit` enum renders the image as 8-bit color space characters. The 8-bit color scheme is more prevalent.

This projects also includes helpers for controlling the console, such as setting cursor position and clearing the console.
