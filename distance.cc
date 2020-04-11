#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

namespace {

using int64 = long long;

} // namespace

int main(int argc, const char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;

  std::cin >> n;

  int input[n];

  for (int i = 0; i < n; i++) {
    std::cin >> input[i];
  }

  int maxx = 1, minx = 1;
  int max = input[0], min = input[0];

  for (int i = 0; i < n; i++) {
    if (max > input[i]) {
      max = input[i];
      maxx = i + 1;
    }
    if (min < input[i]) {
      min = input[i];
      minx = i + 1;
    }
    if (minx > maxx) {
      std::cout << maxx << " " << minx << std::endl;
    } else {
      std::cout << minx << " " << maxx << std::endl;
    }
  }
  return 0;
}
