#include "main.h"
#include <raylib.h>
#include <iostream>
#include <list>
#include <Settings.h>
#include <Simulation.h>

int main() {
    InitWindow(settings.WIDTH,settings.HEIGHT, "Satellite Simulation");
    SetTargetFPS(60);
    Simulation simulation = Simulation();
    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(BLACK);

        simulation.update();
        simulation.paint();

        EndDrawing();
    }
    CloseWindow();
    return 0;
}