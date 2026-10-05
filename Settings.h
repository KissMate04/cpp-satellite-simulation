#ifndef CPP_SETALLITE_SIMULATION_SETTINGS_H
#define CPP_SETALLITE_SIMULATION_SETTINGS_H
#pragma once

struct Settings {
    const double G = 1.0;
    const int WIDTH = 1000, HEIGHT = 1000;
};
extern Settings settings;

#endif //CPP_SETALLITE_SIMULATION_SETTINGS_H