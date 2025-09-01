#pragma once
#include <cstdint>
#include <iostream>
#include <string>

enum class PLANET_TYPE { LUSH, FROZEN, TOXIC, EXOTIC, BARREN };

struct Planet {
  uint64_t id;
  PLANET_TYPE type;
  std::string name;

  static std::string convertPlanetTypeToString(PLANET_TYPE type) {
    switch (type) {
    case PLANET_TYPE::LUSH:
      return "Habitable";
    case PLANET_TYPE::FROZEN:
      return "Frozen";
    case PLANET_TYPE::TOXIC:
      return "Radioactive";
    case PLANET_TYPE::BARREN:
      return "Charred";
    case PLANET_TYPE::EXOTIC:
      return "Exotic";
    }
  }
  std::string convertPlanetTypeToString() {
    switch (type) {
    case PLANET_TYPE::LUSH:
      return "Habitable";
    case PLANET_TYPE::FROZEN:
      return "Frozen";
    case PLANET_TYPE::TOXIC:
      return "Radioactive";
    case PLANET_TYPE::BARREN:
      return "Charred";
    case PLANET_TYPE::EXOTIC:
      return "Exotic";
    default:
      return "Unknown";
    }
  }
};
