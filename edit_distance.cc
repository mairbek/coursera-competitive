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

  int n, m;

  std::cin >> n >> m;

  std::string a, b;

  std::cin >> a >> b;

  int ic, dc, sc;

  std::cin >> ic >> dc >> sc;

  int dp[n+1][m+1];

  for (int i = 0; i <= n; i++) {
    dp[i][0] = i * dc;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = i * ic;
  }

  /*
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      std::cout << dp[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "Hello!" << std::endl;
  */

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int ii = dp[i+1][j] + ic;
      int d = dp[i][j+1] + dc;
      int s = dp[i][j];
      if (a[i] != b[j]) {
        s += sc;
      }
      dp[i+1][j+1] = std::min(ii, std::min(d, s));
    }
  }


  std::cout << "\t\t";
  for (int i = 0; i < m; i++ ) {
    std::cout << b[i] << "\t";
  }
  std::cout << std::endl;
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      std::cout << "\t";
    } else {
      std::cout << a[i-1] << "\t";
    }
    for (int j = 0; j <= m; j++) {
      std::cout << dp[i][j] << "\t";
    }
    std::cout << std::endl;
  }

  std::cout << dp[n][m] << std::endl;

  return 0;
}
