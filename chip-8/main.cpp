#include <GL/freeglut.h>
#include <iostream>
#include "Chip8.h"
#include "Display.h"
#include "Input.h"

Chip8 chip8;

void render() {
    Display::Render(chip8.GetDisplayBuffer());
}

void update(int value) {
    chip8.EmulateCycle();
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    std::cout << "Starting CHIP-8 Emulator..." << std::endl;

    chip8.LoadROM("roms/pong2.c8");
    Display::Init(argc, argv);
    Input::Init(chip8);
    glutDisplayFunc(render);
    glutTimerFunc(16, update, 0);
    glutMainLoop();

    return 0;
}
