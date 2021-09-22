#include <iostream>
#include <bitset>

namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int64 n;

  std::cin >> n;

  std::bitset<10000> primes;
  primes[1] = false;
  for (int i = 2; i <=n; i++) {
    primes[i] = true;
  }

  int i = 2;
  while (i * i <= n) {
    if (primes[i]) {
      for (int j = i * i; j <=n; j+=i) {
        primes[j] = false;
      }
    }
    i++;
  }

  for (int i = 1; i <= n; i++) {
    if (primes[i]) {
      std::cout << "Prime " << i << "\n";
    }
  }

  return 0;
}
