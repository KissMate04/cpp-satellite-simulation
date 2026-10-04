#ifndef CPP_SETALLITE_SIMULATION_SPACEOBJECT_H
#define CPP_SETALLITE_SIMULATION_SPACEOBJECT_H
#include <raylib.h>

class SpaceObject {
public:
    SpaceObject(double x, double y, double vx, double vy, double mass, double radius, Color color) {};

    void Paint() {};

    void Update(double px, double py, double pmass) {};

    void AddTrailPoint();

    void PaintTrailPoints();
};


#endif //CPP_SETALLITE_SIMULATION_SPACEOBJECT_H