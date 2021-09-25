#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
namespace
{

} // namespace

using int64 = long long;

int main(int argc, const char **argv)
{
  int64 m;

  std::cin >> m;

  if (m == 1)
  {
    std::cout << "2" << std::endl;
    return 0;
  }

  // Since n can be large, up to n**9. We use a segmented approach:
  // Find a prime in range [m - sqrt(m), m + sqrt(m)]
  // Pregenerate all prime numbers up to sqrt(r).
  // Use those factors to mark composites in [l, r].
  // Then find closest prime to m in [l, r].
  int shft = sqrt(m);
  int right = m + shft;
  if (right > 1000000008 || right < 0) {
    right = 1000000008;
  }
  int left = m - shft;

  int maxFactor = sqrt(right);
  std::vector<bool> factorPrime(maxFactor + 1, false);
  std::vector<int> factors;
  for (int i = 2; i <= maxFactor; ++i) {
      if (!factorPrime[i]) {
          factors.push_back(i);
          for (int j = i * i; j <= maxFactor; j += i) {
              factorPrime[j] = true;
          }
      }
  }

  std::vector<bool> primes(right - left + 1, true);
  for (int i : factors) {
    for (int j = std::max(i * i, (left + i - 1) / i * i); j <= right; j += i) {
        primes[j - left] = false;
    }
  }
  if (left == 1) {
      primes[0] = false;
  }

  if (primes[m - left]) {
    std::cout << m << std::endl;
    return 0;
  }
  int i = 1;
  while (true) {
    if (primes[m - left-i]) {
      std::cout << (m - i) << std::endl;
      break;
    }
    if ((m + i) <= right && primes[m - left + i]) {
      std::cout << (m+ i) << std::endl;
      break;
    }
    i++;
  }

  return 0;
}
