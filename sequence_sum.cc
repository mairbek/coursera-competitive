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

int pow(int x, int n) {
  if (n == 0) {
    return 0;
  }
  int y = 1;
  while (n > 1) {
    if (n % 2 == 0) {
      n = n / 2;
    } else {
      y = x * y;
      n = (n - 1) / 2;
    }
    x = x * x;
  }
  return x * y;
}

int mod_div(int a, int b, int m) {
  a = a % m;
  int inv = mod_inv(b, m);
  return mod_mul(a, inv, m);
}

int mod_geosum(int a, int n, int m) {
  if (n == 0) {
    return 1;
  }
  int a1 = mod_sum(a, 1, m);
  if (n == 1) {
    return a1;
  }
  int aa = mod_mul(a, a, m);
  if (n % 2 == 1) {
    int rec = mod_geosum(aa, (n-1) / 2, m);
    return mod_mul(rec, a1, m);
  }
  int rec = mod_geosum(aa,  n/2 - 1, m);
  rec = mod_mul(rec, a, m);
  rec = mod_mul(rec, a1, m);
  return mod_sum(rec, 1, m);
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
    mm /= p;
  }

  std::vector<int> mods;
  std::vector<int> sums;
  for (auto const& pf : factors) {
    int p = pf.first;
    int k = pf.second;
    int pk = pow(p, k);
    int phi = pk - pk/p;
    mods.push_back(pk);
    int sum = 0;

    for (int i = 1; i <= std::min(pk, n); i++) {
      int ii = mod_pow(i, i, pk);
      int total_ii = (n-i) / pk + 1;
      int rings = total_ii / phi;
      int rem = total_ii % phi;

      if (i == 1) {
        int ssum = mod_mul(rings, phi, pk);
        ssum = mod_sum(ssum, rem, pk);
        sum = mod_sum(sum, ssum, pk);
        continue;
      }
      int ring_sum = mod_geosum(i, phi-1, pk);
      int rem_sum1 = 0;
      if (rem > 0) {
        rem_sum1 = mod_geosum(i, rem-1, pk);
      }

      int total_sum = mod_mul(ring_sum, rings, pk);
      total_sum = mod_sum(total_sum, rem_sum1, pk);
      total_sum = mod_mul(total_sum, ii, pk);
      sum = mod_sum(sum, total_sum, pk);
    }
    sums.push_back(sum);
    std::cout << pk << " " << sum << std::endl;
  }
  int r = crt(sums, mods);
  std::cout << r << std::endl;

  return 0;
}


// 1684520592 100000
//  64613 
// 100000