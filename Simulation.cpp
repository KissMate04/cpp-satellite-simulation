#include "Simulation.h"

Simulation::Simulation() :
planet(settings.WIDTH, settings.HEIGHT, 0, 0, 60000, 200, BLUE),
satellites(std::list<SpaceObject>()) {
    double orbitRadius = planet.getRadius() + 50;
    for (int i = 0; i < 5; i++) {
        satellites.emplace_back(planet.getX() + orbitRadius, planet.getY() + i * 10, 0,
                                sqrt(settings.G * planet.getMass() / orbitRadius), 0.6, 5, GRAY);
    }
}

};