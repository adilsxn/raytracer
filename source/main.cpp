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

auto main(void) -> int { makeCirclePPM(); }
