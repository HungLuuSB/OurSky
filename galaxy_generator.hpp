#pragma once
#include "planet.hpp"
#include "star_system.hpp"
#include "values.hpp"
#include <cstdint>
#include <cstdio>
#include <random>

class GalaxyGenerator {
public:
  static uint64_t hashCoords(Vector3 coords) {
    uint64_t seed = 1469598103934665603ull;
    seed ^= coords.X;
    seed += 12345678;
    seed ^= coords.Y;
    seed += 12345678;
    seed ^= coords.Z;
    seed += 12345678;
    return seed;
  }

  static StarSystem generateStarSystem(Vector3 coords) {
    uint64_t sysId = hashCoords(coords);
    std::mt19937_64 rng(sysId);
    StarSystem sys{sysId, STAR_SYSTEM_TYPE::RED, toHex(sysId),
                   Vector3{coords.X, coords.Y, coords.Z}};

    int numPlanets = rng() % 10 + 1;
    for (int i = 0; i < numPlanets; i++) {
      Planet p;
      p.id = sysId ^ (i * 0x9e3779b97f4a7c15ull);
      p.name = "PLANET-" + toHex(p.id);
      p.type = planetType(rng() % 5);
      sys.planets.push_back(p);
    }
    return sys;
  }

private:
  static std::string toHex(uint64_t n) {
    char buf[17];
    snprintf(buf, sizeof(buf), "%016llX", (unsigned long long)n);
    return std::string(buf);
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
