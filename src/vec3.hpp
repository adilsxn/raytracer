#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <compare>

class vec3 {
  double _x;
  double _y;
  double _z;

public:
  explicit constexpr vec3(double val) : _x{val}, _y{val}, _z{val} {};
  explicit constexpr vec3(double x, double y, double z)
      : _x{x}, _y{y}, _z{z} {};
  vec3 operator+(vec3 rhs) const {
    return vec3{_x + rhs._x, _y + rhs._y, _z + rhs._z};
  }

  auto operator<=>(const vec3 &) const = default;

  constexpr vec3 operator-(vec3 rhs) const {
    return vec3{_x - rhs._x, _y - rhs._y, _z - rhs._z};
  }
  constexpr vec3 operator-=(vec3 &rhs) {
    _x -= rhs._x;
    _y -= rhs._y;
    _z -= rhs._z;
    return *this;
  }
  constexpr vec3 operator+=(vec3 &rhs) {
    _x += rhs._x;
    _y += rhs._y;
    _z += rhs._z;
    return *this;
  }
  constexpr auto length() -> int {
    return std::sqrt(_x * _x + _y * _y + _z * _z);
  }

  constexpr auto dot(vec3 b) -> double {
    return _x * b._x + _y * b._y + _z * b._z;
  }

  constexpr auto scalar(int scalar) const -> vec3 {
    return vec3{_x * scalar, _y * scalar, _z * scalar};
  }
  constexpr auto normalize() -> vec3 {
    return vec3{_x / length(), _y / length(), _z / length()};
  }
};

#endif // !VEC3_H
