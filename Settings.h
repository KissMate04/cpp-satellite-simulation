#ifndef CPP_SETALLITE_SIMULATION_SETTINGS_H
#define CPP_SETALLITE_SIMULATION_SETTINGS_H
#include <raylib.h>
#pragma once

struct Settings {
    const double G = 1.0;
    const int WIDTH = 1000, HEIGHT = 1000;
    const float TIME_STEP = 0.4f;
    const float REF_HEIGHT = 1080.0f;
};
extern Settings settings;

#endif //CPP_SETALLITE_SIMULATION_SETTINGS_H