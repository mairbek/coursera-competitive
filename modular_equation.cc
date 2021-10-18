#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cmath>
namespace
{

} // namespace

using int64 = long long;

int64 gcd(int64 a, int64 b, int64& x, int64& y) {
  x = 1, y = 0;
  int64 x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int64 q = a1 / b1;
    // std::cout << "yy " << y << "-" << q << "*" << y1 << std::endl;
    std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
    std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
    std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
  }
  return a1;
}

bool find_any_solution(int64 a, int64 b, int64 c, int64 &x0, int64 &y0, int64 &g) {
  g = gcd(abs(a), abs(b), x0, y0);
  // std::cout << "gg " << g << " " << x0 << " " << y0 << std::endl;
  if (c % g) {
      return false;
  }

  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  
  return true;
}

int64 lcm(int64 a, int64 b) {
  int64 x, y;
  int64 g = gcd(a, b, x, y);
  return (a / g) * b;
}


int mod(int a, int b) {
  int r = a % b;
  return r < 0 ? r + b : r;
}

int64 mod_mul(int64 a, int64 b, int64 m) {
  int64 t = a * b;
  return t % m;
} 

int main(int argc, const char **argv) {
  int64 a1, b1, m1, a2, b2, m2;

  std::cin >> a1 >> b1 >> m1 >> a2 >> b2 >> m2;

  if (a1 == b1 && a1 == 0) {
    std::cout << "-1" << std::endl;
    return 0;
  }
  if (a2 == b2 && a2 == 0) {
    std::cout << "-1" << std::endl;
    return 0;
  }

  if (m1 == m2) {
    int64 x1 = 0;
    {
      int64 x, y;
      int64 g = gcd(a1, m1, x, y);
      if (g != 1) {
        std::cout << "-1" << std::endl;
        return 0;
      }
      int64 a1inv = (x % m1 + m1) % m1;
      x1 = mod_mul(a1inv, b1, m1);
    }

    int64 x2 = 0;
    {
      int64 x, y;
      int64 g = gcd(a2, m2, x, y);
      if (g != 1) {
        std::cout << "-1" << std::endl;
        return 0;
      }
      int64 a2inv = (x % m2 + m2) % m2;
      x2 = mod_mul(a2inv, b2, m2);
    }
    std::cout << lcm(x1, x2) << std::endl;
    return 0;
  }

  int64 x1, y1;

  int64 k = gcd(m1, m2, x1, y1);
  int64 mm = k * m1 * m2;

  int64 aa = m1*a2 + m2*a1;
  int64 bb = b1*m2 + b2*m1;


  // std::cout << "aa " << aa << " " << " " << mm << " " << bb << std::endl;
  int64 x, y, g;
  bool result = find_any_solution(aa, mm, bb, x, y, g);
  if (!result) {
    std::cout << "-1" << std::endl;
    return 0;
  }

  // std::cout << "x " << x << " " << y << std::endl;
  int diff = mm / g;
  int xx = mod(x, diff);

  std::cout << xx << std::endl;

  return 0;
}


// >>> a1, b1, m1 = 12, 10, 14
// >>> a2, b2, m2 = 6, 4, 10