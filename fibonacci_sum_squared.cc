#include <math.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace {

using int64 = long long;

std::vector<std::vector<int>>  matrix_mul(std::vector<std::vector<int>>& a, std::vector<std::vector<int>>& b, int m) {
  std::vector<std::vector<int>> result = {{0, 0}, {0, 0}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        int64 temp = a[i][k];
        temp *= b[k][j];
        temp = temp % m;
        temp += result[i][j];
        temp = temp % m;
        result[i][j] = temp;
      }
    }
  }
  return result;
}

std::vector<std::vector<int>> fib(int64 n, int m) {
  std::vector<std::vector<int>> f = {{1, 1}, {1, 0}};
  std::vector<std::vector<int>> result = {{1, 0}, {0, 1}};

  while (n > 0) {
    if (n % 2 == 1) {
      result = matrix_mul(result, f, m);
    }
    f = matrix_mul(f, f, m);
    n /= 2;
  }

  return result;
}

}  // namespace

int main(int argc, const char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int64 n;
  int m;

  std::cin >> n >> m;

  auto f = fib(n, m);
  int64 result = f[0][0];
  result = result * f[0][1];
  result = result % m;
  // std::cout << f[0][0] << " " << f[0][1]<< std::endl;
  std::cout << result << std::endl;


  return 0;
}
