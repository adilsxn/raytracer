#ifndef VEC3_H
#define VEC3_H

#include <cmath>

class vec3 {
  double x;
  double y;
  double z;

public:
  explicit constexpr vec3(double val) : x{val}, y{val}, z{val} {};
  explicit constexpr vec3(double x, double y, double z) : x{x}, y{y}, z{z} {};
  vec3 operator+(vec3 rhs) const {
    return vec3{x + rhs.x, y + rhs.y, z - rhs.z};
  }
  vec3 operator-(vec3 rhs) const {
    return vec3{x - rhs.x, y - rhs.y, z - rhs.z};
  }
  vec3 operator-=(vec3 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }
  vec3 operator+=(vec3 &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }
  auto length() -> int { return std::sqrt(x * x + y * y + z * z); }
  friend constexpr auto dot(vec3 a, vec3 b) -> double {
    return a.x * b.x + a.y * b.y + a.z * b.z;
  }
  constexpr friend auto scalarMult(int scalar, vec3 vec) -> vec3 {
    return vec3{vec.x * scalar, vec.y * scalar, vec.z * scalar};
  }
};

#endif // !VEC3_H
