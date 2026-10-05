#include "SpaceObject.h"

SpaceObject::SpaceObject(double x, double y, double vx, double vy, double mass, double radius, Color color)
    : x(x), y(y), vx(vx), vy(vy), mass(mass), radius(radius), color(color)
{
    trailPoints = std::vector<Vector2>();
}
void SpaceObject::update(double px, double py, double pmass, float dt) {
    double dx = px -x;
    double dy = py -y;
    double dist = sqrt(dx * dx + dy * dy);
    double acceleration = settings.G * pmass / (dist * dist);
    vx += acceleration * dx / dist * dt;
    vy += acceleration * dy / dist * dt;

    x += vx * dt;
    y += vy * dt;
}
void SpaceObject::addTrailPoint() {
    trailPoints.emplace_back(Vector2{static_cast<float>(x), static_cast<float>(y)});
}


