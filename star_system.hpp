#pragma once
#include "planet.hpp"
#include "values.hpp"
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
};
