#pragma once
#include <string>

struct Vector2 {
  int X;
  int Y;
};

struct Vector3 {
  int X;
  int Y;
  int Z;

  std::string toString() {
    return "(" + std::to_string(X) + "," + std::to_string(Y) + "," +
           std::to_string(Z) + ")";
  }
};
