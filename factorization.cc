#include <iostream>
#include <vector>
namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int64 n;

  std::cin >> n;

  int mindiv[n+1];
  for (int i = 0; i <=n; i++) {
    mindiv[i] = 0;
  }
  std::vector<int> primes;

  for (int i = 2; i <= n; i++) {
    if (mindiv[i] == 0) {
      primes.push_back(i);
      mindiv[i] = i;
    }
    for (int j = 0; j < primes.size(); j++) {
      int q = primes[j];
      if (q > mindiv[i] || q * i > n) {
        break;
      }
      mindiv[q * i] = q;
    }
  }
  int m = n;
  while (m > 1) {
    int p = mindiv[m];
    std::cout << p << " ";
    m /= p;
  }
  std::cout << std::endl;
  return 0;
}
