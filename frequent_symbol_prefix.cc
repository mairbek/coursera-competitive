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

  std::string input;

  std::cin >> input;

  uint m = input.length();
  int** b = new int*[m+1];

  for (uint i = 0; i <= m; i++) {
    b[i] = new int[26];
    for (int j = 0; j < 26; j++) {
      b[i][j] = 0;
    }
  }

  for (uint i = 0; i < m; i++) {
    int idx = input[i] - 'a';
    for (int j = 0; j < 26; j++) {
      b[i+1][j] = b[i][j];
      if (j == idx) {
        b[i+1][j]++;
      }
    }
  }

  int n;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y;

    std::cin >> x >> y;

    int l = x - 1;
    int r = y - 1;

    int idx = 0;
    int max = 0;
    for (int i = 0; i < 26; i++) {
      int count = b[r + 1][i] - b[l][i];
      if (count >= max) {
        max = count;
        idx = i;
      }
    }

    char result = 'a' + idx;

    std::cout << result << std::endl;
  }
}
