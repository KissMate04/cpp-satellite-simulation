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
    double lastTrailTime = GetTime();
    while (WindowShouldClose() == false) {
        const float stepDt = GetFrameTime() / 4.0f;
        for (int i = 0; i < 4; i++) {
            simulation.update(stepDt);
        }

        if (GetTime() - lastTrailTime > 0.4) {
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