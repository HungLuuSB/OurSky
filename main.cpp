#include "galaxy.hpp"
#include "galaxy_generator.hpp"
#include "values.hpp"

int main() {
  Galaxy g = GalaxyGenerator::generateGalaxy(Vector3{100, 50, -200}, 5);
  g.displayGalaxy();
  return 0;
}
