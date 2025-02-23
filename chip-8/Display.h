#ifndef DISPLAY_H
#define DISPLAY_H

#include "Chip8.h"

class Display {
public:
    static void Init(int argc, char** argv);
    static void Render(const std::array<uint8_t, 64 * 32>& displayBuffer);
};

#endif
