#include <math.h>

#include <cstdlib>
#include <iostream>
#include <string>

namespace {

using int64 = long long;

}  // namespace

int main(int argc, const char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;

  std::cin >> n >> k;

  int a[n][n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> a[i][j];
    }
  }

  int64 dp[n+1][n+1];

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= n; j++) {
    dp[0][j] = 0;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + a[i][j];
    }
  }
  // for (int i = 0; i <= n; i++) {
  //   for (int j = 0; j <= n; j++) {
  //     std::cout << dp[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
  int64 result = 0;
  for (int i = k-1; i < n; i++) {
    for (int j = k-1; j <n; j++) {
      int a = i - k;
      int b = j - k;

      int64 value = dp[i+1][j+1] - dp[a+1][j+1] - dp[i+1][b+1] + dp[a+1][b+1];

      result = std::max(result, value);
    }
  }

  std::cout << result << std::endl;

  return 0;
}
