#ifndef CHIP8_H
#define CHIP8_H

#include <cstdint>
#include <array>
#include <string>

class Chip8 {
public:
    Chip8();
    void LoadROM(const std::string& filename);
    void EmulateCycle();
    std::array<uint8_t, 64 * 32> GetDisplayBuffer();
    void SetKeyState(int key, bool pressed);
    uint8_t GetKeyState(int key);

private:
    uint16_t opcode;
    std::array<uint8_t, 4096> memory;
    std::array<uint8_t, 16> V;
    uint16_t I;
    uint16_t pc;
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint16_t stack[16];
    uint16_t sp;
    std::array<uint8_t, 64 * 32> display;
    std::array<uint8_t, 16> keypad;
    bool drawFlag;  // Add this line

    void ExecuteOpcode();
};

#endif