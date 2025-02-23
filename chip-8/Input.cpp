#include "Input.h"
#include <GL/freeglut.h>
#include <map>

static Chip8* chip8Instance; // Pointer to CHIP-8 instance

// CHIP-8 key mapping to PC keyboard
std::map<unsigned char, int> keyMap = {
    {'1', 0x1}, {'2', 0x2}, {'3', 0x3}, {'4', 0xC},
    {'Q', 0x4}, {'W', 0x5}, {'E', 0x6}, {'R', 0xD},
    {'A', 0x7}, {'S', 0x8}, {'D', 0x9}, {'F', 0xE},
    {'Z', 0xA}, {'X', 0x0}, {'C', 0xB}, {'V', 0xF}
};

// GLUT key press callback
void keyDown(unsigned char key, int x, int y) {
    key = toupper(key);
    if (chip8Instance && keyMap.find(key) != keyMap.end()) {
        chip8Instance->SetKeyState(keyMap[key], true);
    }
}

// GLUT key release callback
void keyUp(unsigned char key, int x, int y) {
    key = toupper(key);
    if (chip8Instance && keyMap.find(key) != keyMap.end()) {
        chip8Instance->SetKeyState(keyMap[key], false);
    }
}

// Initialize input handling
void Input::Init(Chip8& chip8) {
    chip8Instance = &chip8; // Store reference to CHIP-8 instance
    glutKeyboardFunc(keyDown);
    glutKeyboardUpFunc(keyUp);
}

// Poll is now unnecessary, remove it from Input.cpp
