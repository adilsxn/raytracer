#include "vec3.hpp"
#include <cmath>
#include <print>

// auto make_ppm(int r, int g, int b) -> void {
//   std::println("P3\n650 700\n255");
// for (int y = 0; y < 700; y++) {
//   for (int x = 0; x < 650; x++) {
//     std::print("{} {} {}\n", (x % 256), (y % 256), ((x * y) % 256));
//   }
// }
//   std::print("{} {} {}\n", r, g, b);
// }

auto makeCirclePPM() -> void {
  std::println("P3\n650 700\n255");
  constexpr int radius = 250;
  constexpr double tolerance = 0.5;
  for (int y = 0; y < 700; y++) {
    for (int x = 0; x < 650; x++) {
      double res = std::pow((x - 350), 2) + std::pow((y - 325), 2);
      if (res <= std::pow(radius, 2)) {
        std::print("255 255 255\n");
      } else {
        std::print("0 0 0\n");
      }
    }
    // std::println("");
  }
}

auto main(void) -> int {
  constexpr auto width = 64;
  constexpr auto height = 48;
  constexpr vec3 camera{0, 0, -20};
  constexpr vec3 view_dir{0, 0, 1};
  constexpr auto focal_dist = 10;

  auto screen_center = camera + scalarMult(focal_dist, view_dir);
  auto ray_dir = -camera;
  
  for (auto x = 0; x < width; ++x){
      for (auto y = 0; y < height; ++y){
          
      }
  }
}
