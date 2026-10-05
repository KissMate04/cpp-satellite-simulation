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
        DrawCircle(sat.getX(), sat.getY(), sat.getRadius(), sat.getColor());
    }
}
void Simulation::update() {
    for (SpaceObject& sat : satellites) {
        sat.update(planet.getX(), planet.getY(), planet.getMass());
    }
}