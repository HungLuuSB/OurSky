#pragma once
#include "planet.hpp"
#include "star_system.hpp"
#include "values.hpp"
#include <cstdint>
#include <string>
#include <vector>

struct Galaxy {
  uint64_t id;
  std::string name;
  std::vector<StarSystem> systems;
  Vector3 coords;

  void displayGalaxy() {
    for (auto &sys : systems) {
      std::cout << "[*] Star System - " << sys.name << ": \n"
                << "\tTYPE: " << sys.convertStarSystemTypeToString() << "\n"
                << "\tCOORDINATE: " << sys.coordinate.toString() << "\n"
                << "\tPLANETS: " << sys.planets.size() << std::endl;

      for (int i = 0; i < sys.planets.size(); i++) {
        Planet p = sys.planets[i];
        std::cout << "\t[O] Planet - " << p.name << std::endl;
        std::cout << "\t\tTYPE: " << p.convertPlanetTypeToString() << std::endl;
      }
    }
  }
};
