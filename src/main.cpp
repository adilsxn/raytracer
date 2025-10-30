#include "ray.hpp"
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
  // constexpr double tolerance = 0.5;
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

auto main() -> int {
  constexpr auto width = 960;
  constexpr auto height = 720;
  auto top_left = vec3{-1, 0.75, 0};
  auto top_right = vec3{1, 0.75, 0};
  auto bot_left = vec3{-1, -0.75, 0};
  auto bot_right = vec3{1, -0.75, 0};
  auto camera = vec3{0, 0, -1};

  for (auto x = 0; x < width; x++) {
    for (auto y = 0; y < height; y++) {
      auto xx = (double)x;
      auto yy = (double)(height - y - 1);
      auto top = vec3::lerp(top_left, top_right, xx);
      auto bot = vec3::lerp(bot_left, bot_right, xx);
      auto point = vec3::lerp(top, bot, yy);
      auto rr = ray(camera, (point - camera));
    }
  }

  std::print("");
}
