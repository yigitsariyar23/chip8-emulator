#include "Display.h"
#include <GL/freeglut.h>

void Display::Init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(640, 320);
    glutCreateWindow("CHIP-8 Emulator");
}

void Display::Render(const std::array<uint8_t, 64 * 32>& displayBuffer) {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    for (int y = 0; y < 32; ++y) {
        for (int x = 0; x < 64; ++x) {
            if (displayBuffer[y * 64 + x] != 0) {
                glVertex2f(x / 32.0f - 1, y / 16.0f - 1);
                glVertex2f((x + 1) / 32.0f - 1, y / 16.0f - 1);
                glVertex2f((x + 1) / 32.0f - 1, (y + 1) / 16.0f - 1);
                glVertex2f(x / 32.0f - 1, (y + 1) / 16.0f - 1);
            }
        }
    }
    glEnd();

    glutSwapBuffers();
}
