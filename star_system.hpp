#pragma once
#include "planet.hpp"
#include "utilities.hpp"
#include "values.hpp"
#include <cstdint>
#include <random>
#include <string>
#include <sys/types.h>
#include <vector>

enum class STAR_SYSTEM_TYPE { YELLOW, RED, BLUE };

struct StarSystem {
  u_int64_t id;
  STAR_SYSTEM_TYPE type;
  std::string name;
  Vector3 coordinate;
  std::vector<Planet> planets;

  static std::string convertStarSystemTypeToString(STAR_SYSTEM_TYPE type) {
    switch (type) {
    case STAR_SYSTEM_TYPE::BLUE:
      return "Blue";
    case STAR_SYSTEM_TYPE::RED:
      return "Red";
    case STAR_SYSTEM_TYPE::YELLOW:
      return "Yellow";
    default:
      return "Unknown";
    }
  }

  std::string convertStarSystemTypeToString() {
    switch (type) {
    case STAR_SYSTEM_TYPE::BLUE:
      return "Blue";
    case STAR_SYSTEM_TYPE::RED:
      return "Red";
    case STAR_SYSTEM_TYPE::YELLOW:
      return "Yellow";
    default:
      return "Unknown";
    }
  }

  void generatePlanets(const int numPlanets, uint64_t sysId,
                       std::mt19937_64 rng) {
    for (int i = 0; i < numPlanets; i++) {
      Planet p;
      p.id = sysId ^ (i * 0x9e3779b97f4a7c15ull);
      p.name = toHex(p.id);
      p.type = planetType(rng() % 5);
      planets.push_back(p);
    }
  }

  static PLANET_TYPE planetType(int t) {
    switch (t) {
    case 0:
      return PLANET_TYPE::LUSH;
    case 1:
      return PLANET_TYPE::FROZEN;
    case 2:
      return PLANET_TYPE::BARREN;
    case 3:
      return PLANET_TYPE::TOXIC;
    default:
      return PLANET_TYPE::EXOTIC;
    }
  }
};
