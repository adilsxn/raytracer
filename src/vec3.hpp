#ifndef VEC3
#define VEC3

class vec3 {
  double x;
  double y;
  double z;

  // TODO: Add all the missing operations dot prod, sum, subtration
public:
  vec3() = default;
  vec3(double x, double y, double z) : x{x}, y{y}, z{z} {};
  // auto operator<=>(const vec3 &) const = default;
  vec3 scalarMult(int scalar) {
    return vec3{x * scalar, y * scalar, z * scalar};
  }
  vec3 operator+(vec3 rhs) { return vec3{x + rhs.x, y + rhs.y, z - rhs.z}; }

  vec3 operator-(vec3 rhs) { return vec3{x - rhs.x, y - rhs.y, z - rhs.z}; }
  double operator*(vec3 rhs) {
    return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
  }
};

#endif // !VEC3
