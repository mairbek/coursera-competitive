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

  int a[n];

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  int dp[n];

  for (int i = 0; i < n; i++) {
    dp[i] = 1;

    for (int j = 0; j < i; j++) {
      int dpj = dp[j] + 1;
      if (a[j] < a[i] && dp[i] < dpj) {
        dp[i] = dpj;
      }
    }
  }

  int result = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] > result) {
      result = dp[i];
    }
  }

  std::cout << result << std::endl;

  return 0;
}
