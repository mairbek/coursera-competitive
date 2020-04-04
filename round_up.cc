#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int x, y;

  std::cin >> x >> y;

  double dx = x;
  double dy = y;

  double dz = dx / dy;

  int64 z = (int64) ceil(dz);

  std::cout << z << std::endl;

}
