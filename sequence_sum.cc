#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

namespace {
} // namespace

using int64 = long long;
int mod_inv(int a, int m) {
  if (m == 1) {
    return 0;
  }
  int m0 = m;
  int y = 0, x = 1;
  while (a > 1) {
    // q is quotient
    int q = a / m;
    int t = m;

    // m is remainder now, process same as
    // Euclid's algo
    m = a % m, a = t;
    t = y;

    // Update y and x
    y = x - q * y;
    x = t;
  }
  // Make x positive
  if (x < 0) {
    x += m0;
  }
  return x;
}

int crt(const std::vector<int>& a, const std::vector<int>& m) {
  int k = m.size();
  int prod = 1;
  for (int i = 0; i < k; i++) {
    prod *= m[i];
  }
  int result = 0;
    for (int i = 0; i < k; i++) {
      int pp = prod / m[i];
      result += a[i] * mod_inv(pp, m[i]) * pp;
  }
  return result % prod;
}

int mod_mul(int a, int b, int m) {
  int64 t = ((int64) a) * b;
  return t % m;
} 

int mod_sum(int a, int b, int m) {
  int64 t = ((int64) a) + b;
  return t % m;
} 

int mod_pow(int x, int n, int p) {
  if (n == 0) {
    return 1;
  }
  int y = 1;
  x = x % p;
  while (n > 1) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      y = mod_mul(x, y, p);
      n = (n - 1) / 2;
    }
    x = mod_mul(x, x, p);
  }
  return mod_mul(x, y, p);
}

int main(int argc, const char** argv) {
  int n, m;

  std::cin >> n >> m;

  int mindiv[m+1];
  for (int i = 0; i <=m; i++) {
    mindiv[i] = 0;
  }
  std::vector<int> primes;
  for (int i = 2; i <= m; i++) {
    if (mindiv[i] == 0) {
      primes.push_back(i);
      mindiv[i] = i;
    }
    for (int j = 0; j < primes.size(); j++) {
      int q = primes[j];
      if (q > mindiv[i] || q * i > m) {
        break;
      }
      mindiv[q * i] = q;
    }
  }
  std::unordered_map<int, int> factors;
  int mm = m;
  while (mm > 1) {
    int p = mindiv[mm];
    if (factors.count(p) == 0) {
      factors[p] = 0;
    }
    factors[p] += 1;
    // std::cout << "factor " << p << std::endl; 
    mm /= p;
  }

  std::vector<int> mods;
  std::vector<int> sum;
  int j = 0;
  for (auto const& pf : factors) {
    int p = pf.first;
    int k = pf.second;
    int pk = pow(p, k);
    int phi = pk - pk/p;
    mods.push_back(pk);
    sum.push_back(0);

    // int upp = std::min(n, pk + phi);
    // for (int i = 1; i <= upp; i++) {
    //   int pw = mod_pow(i, i % phi, pk);
    //   int nn = (n - i) / phi + 1;
    //   std::cout << "i=" << i << " n= " << n << " pk=" << pk << " phi=" << phi << " nn=" << nn << std::endl;
    //   pw = mod_mul(pw, nn, pk);
    //   sum[j] = mod_sum(sum[j], pw, pk);
    // }
    // j++;
    for (int i = 0; i <= pk; i++) {
      int pw = mod_pow(i, i % phi, pk);
      sum[j] = mod_sum(sum[j], pw, pk);
      for (int j = 0; j < n/pk; j++) {
        pw = mod_mul(pw, i, pk);
        sum[j] = mod_sum(sum[j], pw, pk);
      }
    }
  }
  std::cout << crt(sum, mods) << std::endl;

  // int sum = 0;
  // for (int i = 1; i <= n; i++) {
  //   int t = mod_pow(i, i, m);
  //   sum = mod_sum(sum, t, m);
  // }

  // std::cout << sum << std::endl;

  return 0;
}
