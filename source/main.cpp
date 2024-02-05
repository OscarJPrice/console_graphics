#include "RenderImage.hpp"
#include <iostream>

int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        renderImageToConsole(ImageBuffer<100, 40>(argv[i]));
    }
}
