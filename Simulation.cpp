#include "Simulation.h"

Simulation::Simulation() :
planet(settings.WIDTH/2, settings.HEIGHT/2, 0, 0, 60000, 200, BLUE),
satellites(std::list<SpaceObject>()) {
    double orbitRadius = planet.getRadius() + 50;
    for (int i = 0; i < 5; i++) {
        satellites.emplace_back(planet.getX() + orbitRadius, planet.getY() + i * 10, 0,
                                sqrt(settings.G * planet.getMass() / orbitRadius), 0.6, 5, GRAY);
    }
}
void Simulation::paint() {
    DrawCircle(planet.getX(), planet.getY(), planet.getRadius(), planet.getColor());
    for (SpaceObject sat : satellites) {
        paintTrail(sat.getTrailPoints());
        DrawCircle(sat.getX(), sat.getY(), sat.getRadius(), sat.getColor());
    }
}
void Simulation::update(float dt) {
    for (SpaceObject& sat : satellites) {
        sat.update(planet.getX(), planet.getY(), planet.getMass(), dt);
    }
}

void Simulation::paintTrail(const std::vector<Vector2>& trailPoints) {
    for (auto p : trailPoints) {
        DrawPixel(p.x, p.y, LIGHTGRAY);
    }
}

void Simulation::addTrailPoints() {
    for (SpaceObject& sat : satellites) {
        sat.addTrailPoint();
    }
}
