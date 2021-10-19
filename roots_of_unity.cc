#include <iostream>
#include <vector>
#include <unordered_map>
#include <tgmath.h>
#include <iomanip>

using int64 = long long;

#define PI 3.14159265

int main(int argc, const char** argv) {
  int n;
  std::cin >> n;

  for (int k = 0; k < n; k++) {
    double kk = (2.0 * k * M_PI) / n;
    std::cout << std::fixed << std::setw(11) << std::setprecision(10) << cos(kk) << " " << sin(kk) << std::endl;
  }

  return 0;
}
