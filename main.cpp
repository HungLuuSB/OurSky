#include "galaxy_generator.hpp"
#include "planet.hpp"
#include "values.hpp"
#include <iostream>
#include <ostream>

int main() {
  StarSystem sys = GalaxyGenerator::generateStarSystem(Vector3{100, 50, -200});
  std::cout << "System " << sys.name << " has " << sys.planets.size()
            << " planets.\n";

  for (int i = 0; i < sys.planets.size(); i++) {
    Planet p = sys.planets[i];
    std::cout << "[^]" << p.name << std::endl;
    std::cout << "\tTYPE: " << p.convertPlanetTypeToString() << std::endl;
  }
  return 0;
}
