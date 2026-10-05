cmake_minimum_required(VERSION 3.28)
project(cpp_setallite_simulation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)
include_directories(.)

add_executable(cpp_setallite_simulation
        main.cpp
        main.h
        SpaceObject.cpp
        SpaceObject.h
        Simulation.cpp
        Simulation.h
        Settings.cpp
        Settings.h)

target_link_libraries(cpp_setallite_simulation PRIVATE raylib)
