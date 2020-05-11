#include <math.h>

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace {

using int64 = long long;

}  // namespace

int main(int argc, const char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;

  std::cin >> n;

  int a[n], b[n];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  int dp[n + 1][n + 1];

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
    dp[0][i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int val = std::max(dp[i][j + 1], dp[i + 1][j]);
      if (a[i] == b[j]) {
        val = std::max(1 + dp[i][j], val);
      }
      dp[i + 1][j + 1] = val;
    }
  }

  int result = dp[n][n];
  std::cout << result << std::endl;
  // backtrace
  int i = n;
  int j = n;
  std::vector<int> as;
  std::vector<int> bs;
  while (result > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else if (dp[i][j] == dp[i - 1][j - 1]) {
      i--;
      j--;
    } else {
      as.push_back(--i);
      bs.push_back(--j);
      result--;
    }
  }

  for (int i = as.size() - 1; i >= 0; i--) {
    std::cout << as[i] << " ";
  }
  std::cout << std::endl;
  for (int i = bs.size() - 1; i >= 0; i--) {
    std::cout << bs[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
