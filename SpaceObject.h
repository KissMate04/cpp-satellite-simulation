#ifndef CPP_SETALLITE_SIMULATION_SPACEOBJECT_H
#define CPP_SETALLITE_SIMULATION_SPACEOBJECT_H
#include <raylib.h> //Needed for color. Fix later
#include <cmath>
#include <Settings.h>
#include <vector>
#pragma once


class SpaceObject {
    double x, y;
    double vx, vy;
    double mass;
    double radius;
    Color color{};
    std::vector<Vector2> trailPoints;
public:
    SpaceObject(double x, double y, double vx, double vy, double mass, double radius, Color color);
    void update(double px, double py, double pmass, float dt);
    void addTrailPoint();
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getVx() const {
        return vx;
    }

    double getVy() const {
        return vy;
    }

    double getMass() const {
        return mass;
    }

    double getRadius() const {
        return radius;
    }
    Color getColor() const {
        return color;
    }
    std::vector<Vector2> getTrailPoints() const {
        return trailPoints;
    }
};


#endif //CPP_SETALLITE_SIMULATION_SPACEOBJECT_H