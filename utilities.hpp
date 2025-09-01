#pragma once
#include <cstdint>
#include <string>
static std::string toHex(uint64_t n) {
  char buf[17];
  snprintf(buf, sizeof(buf), "%016llX", (unsigned long long)n);
  return std::string(buf);
}
