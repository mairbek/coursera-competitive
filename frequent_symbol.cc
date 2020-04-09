#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

namespace {


using int64 = long long;
using uint = unsigned int;

uint nextPowerOf2(uint n) {
  n--;
  n |= n >> 1;
  n |= n >> 2;
  n |= n >> 4;
  n |= n >> 8;
  n |= n >> 16;
  n++;
  return n;
}

char solve(int** b, int x, int y, int len) {
  int s[26];
  for (int i = 0; i < 26; i++) {
    s[i] = 0;
  }

  int l = len - 2 + x;
  int r = len - 2 + y;

  while (l <= r) {
    if (l > r) {
      break;
    }
    if (l == r) {
      for (int j = 0; j < 26; j++) {
        s[j] += b[l][j];
      }
      break;
    }
    if (l % 2 == 0) {
      for (int j = 0; j < 26; j++) {
        s[j] += b[l][j];
      }
      l += 1;
    }
    if (r % 2 != 0) {
      for (int j = 0; j < 26; j++) {
        s[j] -= b[r+1][j];
      }
    }
    l = (l - 1) / 2;
    r = (r - 1) / 2;
  }

  int max = 0;
  int result = 0;

  for (int i = 0; i < 26; i++) {
    if (s[i] >= max) {
      result = i;
      max = s[i];
    }
  }

  // std::cout << result << std::endl;

  return 'a' + result;
}
} // namespace

int main(int argc, const char** argv) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::string input;

  std::cin >> input;

  // todo find close 2**n
  uint m = input.length();
  uint len = nextPowerOf2(m);
  int** b = new int*[2 * len];

  for (uint i = 0; i < 2 * len - 1; i++) {
    b[i] = new int[26];
    for (int j = 0; j < 26; j++) {
      b[i][j] = 0;
    }
  }

  for (uint i = 0; i < m; i++) {
    int k = len - 1 + i;
    int idx = input[i] - 'a';
    for (int j = 0; j < 26; j++) {
      if (idx == j) {
        b[k][j] = 1;
      }
    }
  }

  for (int i = len - 2; i >= 0; i--) {
    int c1 = 2 * (i + 1) - 1;
    int c2 = 2 * (i + 1);
    for (int j = 0; j < 26; j++) {
      b[i][j] = b[c1][j] + b[c2][j];
    }
  }

  int n;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int l, r;

    std::cin >> l >> r;

    std::cout << solve(b, l, r, len) << std::endl;
  }
}
