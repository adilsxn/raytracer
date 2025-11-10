#include "ray.hpp"
#include "vec3.hpp"
#include <algorithm>
#include <print>

auto putPixelAt(const ray &r) -> void {
  // std::print("{} {} {}\n", r._dir._x, r._dir._y, 0.0);
  auto rc =
      static_cast<int>(255.0 * std::clamp((r._dir._x + 1.0) * 0.5, 0.0, 1.0));
  auto gc =
      static_cast<int>(255.0 * std::clamp((r._dir._y + 1.0) * 0.5, 0.0, 1.0));
  auto bc =
      static_cast<int>(255.0 * std::clamp((r._dir._z + 1.0) * 0.5, 0.0, 1.0));
  std::print("{} {} {}\n", rc, gc, bc);
}

// auto makeCirclePPM() -> void {
//   std::println("P3\n650 700\n255");
//   constexpr int radius = 250;
//   // constexpr double tolerance = 0.5;
//   for (int y = 0; y < 700; y++) {
//     for (int x = 0; x < 650; x++) {
//       double res = std::pow((x - 350), 2) + std::pow((y - 325), 2);
//       if (res <= std::pow(radius, 2)) {
//         std::print("255 255 255\n");
//       } else {
//         std::print("0 0 0\n");
//       }
//     }
//     // std::println("");
//   }
// }

auto main() -> int {
  constexpr auto width = 960;
  constexpr auto height = 720;
  auto top_left = vec3{-1, 0.75, 0};
  auto top_right = vec3{1, 0.75, 0};
  auto bot_left = vec3{-1, -0.75, 0};
  auto bot_right = vec3{1, -0.75, 0};
  auto camera = vec3{0, 0, -0.5};

  std::println("P3\n{} {}\n255", width, height);

  for (auto x = 0; x < width; x++) {
    for (auto y = 0; y < height; y++) {
      auto xx = (double)x / (width - 1);
      auto yy = 1.0 - (double)y / (height - 1);
      auto top = vec3::lerp(top_left, top_right, xx);
      auto bot = vec3::lerp(bot_left, bot_right, xx);
      auto point = vec3::lerp(bot, top, yy);
      auto dirdir = (point - camera);
      auto rr = ray(camera, dirdir.normalize());
      putPixelAt(rr);
    }
  }
}
