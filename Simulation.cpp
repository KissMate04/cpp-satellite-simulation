#include "Simulation.h"

#include <iostream>



Simulation::Simulation() :
camera{},
planet(0,0, 0, 0, 60000, 200, BLUE),
satellites(std::list<SpaceObject>())
{
    camera.zoom = 1.0f;
    double orbitRadius = planet.getRadius() + 50;
    /*for (int i = 0; i < 5; i++) {
        satellites.emplace_back(planet.getX() + orbitRadius, planet.getY() + i * 10, 0,
                                sqrt(settings.G * planet.getMass() / orbitRadius), 0.6, 5, GRAY);
    }*/
    satellites.emplace_back(planet.getX() + orbitRadius, planet.getY(), 0,
                            sqrt(settings.G * planet.getMass() / orbitRadius), 0.6, 5, GRAY);
}
void Simulation::updateCamera() {
    camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
    camera.target = {static_cast<float>(planet.getX()), static_cast<float>(planet.getY())};
    camera.zoom = GetScreenHeight() / settings.REF_HEIGHT;
}
void Simulation::paint() {
    BeginMode2D(camera);
    DrawCircle(planet.getX(), planet.getY(), planet.getRadius(), planet.getColor());
    for (SpaceObject sat : satellites) {
        paintTrail(sat.getTrailPoints());
        DrawCircle(sat.getX(), sat.getY(), sat.getRadius(), sat.getColor());
    }
    EndMode2D();
    // Draw UI
}
void Simulation::update(float dt) {
    for (SpaceObject& sat : satellites) {
        sat.update(planet.getX(), planet.getY(), planet.getMass(), dt);
    }
}

void Simulation::paintTrail(const std::vector<Vector2>& trailPoints) {
    const float px = 1.0f / camera.zoom; // Adjust pixel size based on zoom level
    for (const Vector2& p : trailPoints) {
        DrawRectangleV(p, {px,px}, LIGHTGRAY);
    }
}

void Simulation::addTrailPoints() {
    for (SpaceObject& sat : satellites) {
        sat.addTrailPoint();
    }
}
