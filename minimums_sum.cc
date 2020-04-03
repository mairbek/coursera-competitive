#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int n;
  std::cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  int64 sum = 0;
  for (int l = 0; l < n; l++) {
    int min = arr[l];
    for (int r = l; r < n; r++) {
      if (min > arr[r]) {
        min = arr[r];
      }
      sum += min;
    }
  }
  std::cout << sum << std::endl;

}
