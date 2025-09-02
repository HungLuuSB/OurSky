#pragma once
#include "galaxy.hpp"
#include "star_system.hpp"
#include "values.hpp"
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <random>

constexpr uint64_t galaxySeed = 1469598103934665603ull;

class GalaxyGenerator {
public:
  static uint64_t hashCoords(Vector3 coords) {
    uint64_t seed = galaxySeed;
    seed ^= coords.X;
    seed += 12345678922331ull;
    seed ^= coords.Y;
    seed += 12345678922331ull;
    seed ^= coords.Z;
    seed += 12345678922331ull;
    std::cout << "Seed: " << seed << std::endl;
    return seed;
  };

  static Galaxy generateGalaxy(Vector3 coords, int numStarSystems) {
    Galaxy g;
    g.id = galaxySeed;
    g.coords = coords;

    std::mt19937_64 rng(g.id);
    std::uniform_int_distribution<int> offsetDistance(-100, 100);

    for (int i = 0; i < numStarSystems; i++) {
      Vector3 sysCoords{
          coords.X + offsetDistance(rng),
          coords.Y + offsetDistance(rng),
          coords.Z + offsetDistance(rng),
      };
      g.systems.push_back(generateStarSystem(sysCoords));
    }
    return g;
  }

  static StarSystem generateStarSystem(Vector3 coords) {
    uint64_t sysId = hashCoords(coords);
    std::mt19937_64 rng(sysId);
    int numPlanets = rng() % 10 + 1;
    StarSystem sys{sysId, static_cast<STAR_SYSTEM_TYPE>(rng() % 3),
                   toHex(sysId), Vector3{coords.X, coords.Y, coords.Z}};

    sys.generatePlanets(numPlanets, sysId, rng);
    return sys;
  }
};
