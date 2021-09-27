#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
namespace
{

} // namespace

using int64 = long long;

int mulmod(int a, int b, int mod)
{
    int res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        // Multiply 'a' with 2
        a = (a * 2) % mod;
 
        // Divide b by 2
        b /= 2;
    }
 
    // Return result
    return res % mod;
}


int pow(int x, int n, int p) {
  if (n == 0) {
    return 1;
  }
  int y = 1;
  x = x % p;
  while (n > 1) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      y = mulmod(x, y, p);
      n = (n - 1) / 2;
    }
    x = mulmod(x, x, p);
  }
  return mulmod(x, y, p);
}

int main(int argc, const char **argv) {
  // std::cout << pow(2, 6, 535252)

  int n, m, p;

  std::cin >> n >> m >> p;

  int maxFactor = n;
  std::vector<bool> factorPrime(maxFactor + 1, false);
  std::vector<int> primes;
  for (int i = 2; i <= maxFactor; ++i) {
      if (!factorPrime[i]) {
          primes.push_back(i);
          for (int j = i * i; j <= maxFactor; j += i) {
              factorPrime[j] = true;
          }
      }
  }

  int result = 1;

  for (int i = 0; i < primes.size(); i++) {
    int vp = 0;
    int pp = primes[i];
    int pi = pp;
    while (n/pi > 0) {
      vp = (vp + (n/pi) % p) % p;
      vp = (vp - (m/pi) % p) % p;
      vp = (vp - ((n-m)/pi) % p) % p;
      pi *= pp;
    }
    // std::cout << "primus " << pp << " " << vp << std::endl;
    if (vp == 0) {
      continue;
    }
    // std::cout << "pepe " << pow(pp, vp, p) << "-" << pow(pp, vp - 1, p) << " " << result << std::endl;
    int vpnk = (pow(pp, vp, p) - pow(pp, vp - 1, p)) % p;
    result = mulmod(result, vpnk, p);
    if (result == 0) {
      // std::cout << "wtf";
      return 0;
    }
  }
  // 9 3 340020391
  // 14 5 507889607
  // 728 371 535252009

  std::cout << result << std::endl;

  return 0;
}
