#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

struct ray {
  vec3 _orig;
  vec3 _dir;

  explicit constexpr ray(vec3 orig, vec3 dir)
      : _orig{orig}, _dir{dir} {

        };
};

#endif // !RAY_HPP
