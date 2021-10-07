#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

namespace {
} // namespace

using int64 = long long;

int gcd(int a, int b) {
  if (b > a) {
    int tmp = a;
    a = b;
    b = tmp;
  }

  while (b > 0) {
    int temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}

int phifun(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
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

  int pk = m;
  int phi = phifun(pk);
  int shift_pow = pk - phi;
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

    int igcd = mod_pow(i, shift_pow, pk);
    int ring_sum = mod_geosum(igcd, phi-1, pk);
    int rem_sum = 0;
    if (rem > 0) {
      rem_sum = mod_geosum(igcd, rem-1, pk);
    }

    int total_sum = mod_mul(ring_sum, rings, pk);
    total_sum = mod_sum(total_sum, rem_sum, pk);
    total_sum = mod_mul(total_sum, ii, pk);
    sum = mod_sum(sum, total_sum, pk);
  }
  std::cout << sum << std::endl;
  return 0;
}


// 1684520592 100000
//  64613 
// 100000