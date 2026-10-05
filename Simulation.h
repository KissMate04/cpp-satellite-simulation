#ifndef CPP_SETALLITE_SIMULATION_SIMULATION_H
#define CPP_SETALLITE_SIMULATION_SIMULATION_H
#include <raylib.h>
#include "SpaceObject.h"
#include <list>
#include <Settings.h>
#include <cmath>
#pragma once

class Simulation {
    SpaceObject planet;
    std::list<SpaceObject> satellites;
public:
    Simulation();
    void paint();
    void paintSO(SpaceObject so);
    void update();
    void paintUI();
    void addTrailPoints();
};


#endif //CPP_SETALLITE_SIMULATION_SIMULATION_H