#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "vec3.hpp"'
#include <doctest/doctest.h>

TEST_CASE("vec3 basic operations") {
  vec3 a{1, 2, 3};
  vec3 b{1, 2, 3};
  vec3 c{1, 4, 3};

  CHECK(a == b);
  CHECK(a != c);

  CHECK(a.x == doctest::Approx(1.0));
}
