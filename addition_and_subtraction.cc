#include <iostream>

namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int64 x, y, z;

  std::cin >> x >> y >> z;

  int64 zy = z - y;
  int64 xy = x - y;

  if (z == 0) {
    std::cout << 0 << std::endl;
    return 0;
  }
  if (xy == 0) {
    if (x == z) {
      std::cout << 1 << std::endl;
    } else {
      std::cout << -1 << std::endl;
    }
    return 0;
  }

  if (zy % xy == 0) {
    int64 i = zy / xy;
    if (i > 0) {
      std::cout << (2 * i - 1) << std::endl;
      return 0;
    }
  }
  if (z % xy == 0) {
    int64 i = z / xy;
    if (i > 0) {
      std::cout << 2 * i << std::endl;
      return 0;
    }
  }
  std::cout << -1 << std::endl;

  return 0;
}
