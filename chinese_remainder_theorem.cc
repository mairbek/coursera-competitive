#include <iostream>
#include <vector>
#include <unordered_map>

using int64 = long long;

namespace {

int mod_inv(int a, int m) {
  if (m == 1) {
    return 0;
  }
  int m0 = m;
  int y = 0, x = 1;
  while (a > 1) {
      // q is quotient
      int q = a / m;
      int t = m;

      // m is remainder now, process same as
      // Euclid's algo
      m = a % m, a = t;
      t = y;

      // Update y and x
      y = x - q * y;
      x = t;
  }
  // Make x positive
  if (x < 0) {
    x += m0;
  }
  return x;
}

int crt(const std::vector<int>& a, const std::vector<int>& m) {
    int k = m.size();
    int prod = 1;
    for (int i = 0; i < k; i++) {
      prod *= m[i];
    }
    int result = 0;
     for (int i = 0; i < k; i++) {
        int pp = prod / m[i];
        result += a[i] * mod_inv(pp, m[i]) * pp;
    }
    return result % prod;
}

} // namespace

int main(int argc, const char** argv) {
  std::vector<int> a = {4, 4};
  std::vector<int> m = {883, 79};
  int result = crt(a, m);
  std::cout << result << std::endl;

  return 0;
}
