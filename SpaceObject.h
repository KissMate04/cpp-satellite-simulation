#ifndef CPP_SETALLITE_SIMULATION_SPACEOBJECT_H
#define CPP_SETALLITE_SIMULATION_SPACEOBJECT_H
#include <raylib.h>
#pragma once


class SpaceObject {
    double x, y;
    double vx, vy;
    double mass;
    double radius;
    Color color{};
    //list<Point2D.Double> trailPoints;
public:
    SpaceObject(double x, double y, double vx, double vy, double mass, double radius, Color color);
    void paint();
    void uUpdate(double px, double py, double pmass);
    void addTrailPoint();
    void paintTrailPoints();
};


#endif //CPP_SETALLITE_SIMULATION_SPACEOBJECT_H