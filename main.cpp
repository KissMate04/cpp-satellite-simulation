#include "main.h"
#include <raylib.h>
#include <iostream>

int main() {
    InitWindow(1000,1000, "Satellite Simulation");
    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Satellite Simulation", 10, 10, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}