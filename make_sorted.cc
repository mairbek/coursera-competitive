#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>

namespace {

  using int64 = long long;

} // namespace

int main(int argc, const char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n;

  std::cin >> n;

  int a[n];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int maxa = 1;

  for (int i = 0; i < n; i++) {
    if (a[i] > maxa) {
      maxa = a[i];
    }
  }

  int dp[maxa+1][n+1];

  for (int j = 0; j <= n; j++) {
    dp[0][j] = 0;
  }

  for (int i = 0; i <= maxa; i++) {
    dp[i][0] = 0;
  }

  for (int i = 1; i <= maxa; i++) {
    for (int j = 0; j < n; j++) {
      int min = 1e9;
      for (int k = 0; k < i; k++) {
        int val = dp[k][j+1];
        if (val < min) {
          min = val;
        }
      }
      // abs(a[j] - k) +
      dp[i][j+1] = abs(a[j] - i) + min;
    }
  }

  for (int i = 0; i <= maxa; i++) {
    for (int j = 0; j <=n; j++) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << dp[maxa][n] << std::endl;

  return 0;
}
