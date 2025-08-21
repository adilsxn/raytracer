#include <cmath>
#include <print>

auto make_ppm(int height, int width) -> void {
  std::println("P3");
  std::println("{} {}", height, width);
  std
}

auto main(void) -> int {

  int radius = 20;
  double tolerance = 0.5;
  for (int x = 0; x < 64; x++) {
    for (int y = 0; y < 48; y++) {
      double res = std::pow((x - 32), 2) + std::pow((y - 24), 2);
      if (res > std::pow(radius, 2) - tolerance &&
          res < std::pow(radius, 2) + tolerance) {
        std::print("o");
      } else {
        std::print(" ");
      }
    }
    std::println("");
  }
}
