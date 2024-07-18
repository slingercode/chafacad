#include "raylib.h"

#define CHAFACAD "ChafaCAD"

int main(void) {
    InitWindow(800, 450, CHAFACAD);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
