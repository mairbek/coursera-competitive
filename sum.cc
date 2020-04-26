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

  int s, l;

  std::cin >> s >> l;

  if (s == 0 ) {
    if (l == 1) {
      std::cout << "1" << std::endl;
    } else {
      std::cout << "0" << std::endl;
    }
    return 0;
  }

  if (l == 0) {
    std::cout << "0" << std::endl;
    return 0;
  }


  int64 dp[l][s];

  for (int j = 0; j < s; j++) {
    if (j < 9) {
      dp[0][j] = 1;
    } else {
      dp[0][j] = 0;
    }
  }

  for (int i = 1; i < l; i++) {
    for (int j = 0; j < s; j++) {
      int64 sum = 0;
      for (int k = 0; k <= std::min(j, 9); k++) {
        sum += dp[i-1][j-k];
      }
      dp[i][j] = sum;
    }
  }

  std::cout << dp[l-1][s-1] << std::endl;

  return 0;
}
