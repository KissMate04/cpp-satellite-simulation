#include "SpaceObject.h"
#include <iostream>

SpaceObject::SpaceObject(double x, double y, double vx, double vy, double mass, double radius, Color color)
    : x(x), y(y), vx(vx), vy(vy), mass(mass), radius(radius), color(color)
{
}
void SpaceObject::update(double px, double py, double pmass) {
    double dx = px -x;
    double dy = py -y;
    double dist = sqrt(dx * dx + dy * dy);
    double acceleration = settings.G * pmass / (dist * dist);
    vx += acceleration * dx / dist;
    vy += acceleration * dy / dist;

    x += vx;
    y += vy;
}


