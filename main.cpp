#include "main.h"
#include <raylib.h>
#include <iostream>
#include <list>
#include <Settings.h>
#include <Simulation.h>

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_UNDECORATED);
    InitWindow(1280, 720, "Satellite Simulation");
    MaximizeWindow();
    SetTargetFPS(60);

    Simulation simulation = Simulation();
    double lastTrailTime = GetTime();
    while (WindowShouldClose() == false) {
        simulation.updateCamera();
        const float stepDt = GetFrameTime() / settings.TIME_STEP;
        for (int i = 0; i < 4; i++) {
            simulation.update(stepDt);
        }

        if (GetTime() - lastTrailTime > settings.TIME_STEP) {
            simulation.addTrailPoints();
            lastTrailTime = GetTime();
        }

        BeginDrawing();
        ClearBackground(BLACK);
        simulation.paint();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}