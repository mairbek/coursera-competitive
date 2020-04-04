#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int r, c;

  std::cin >> r >> c;

  float n = r;
  float m = c;

  float result = ceil(n / 3) * ceil (m / 3);

  int count = (r * c) - result;
  std::cout << count << std::endl;
}
