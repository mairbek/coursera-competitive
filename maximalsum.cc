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

  int64 a[n];
  int64 bp[n+1];
  int64 bs[n+1];

  bp[0] = 0;
  bs[n] = 0;

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    bp[i + 1] = bp[i] + a[i];
    bs[i] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    bs[i] = bs[i+1] + a[i];
  }

  /*
  std::cout << "bp" << std::endl;
  for (int i = 0; i <= n; i++) {
    std::cout << bp[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "bs" << std::endl;
  for (int i = 0; i <= n; i++) {
    std::cout << bs[i] << " ";
  }
  std::cout << std::endl;
  */

  int64 minbp[n+1];
  minbp[0] = 0;
  for (int i = 1; i <=n; i++) {
    minbp[i] = std::min(minbp[i-1], bp[i-1]);
  }
  int64 minbs[n+1];
  minbs[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    minbs[i] = std::min(minbs[i+1], bs[i]);
  }

  /*
  std::cout << "minbp" << std::endl;
  for (int i = 0; i <= n; i++) {
    std::cout << minbp[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "minbs" << std::endl;
  for (int i = 0; i <= n; i++) {
    std::cout << minbs[i] << " ";
  }
  std::cout << std::endl;
  */

  for (int i = 0; i < n; i++) {
    int64 value = bp[n] - minbp[i+1] - minbs[i+1];
    std::cout << value << " ";
  }
  std::cout << std::endl;

  return 0;

}
