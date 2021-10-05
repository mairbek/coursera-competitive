#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using int64 = long long;

int mod_mul(int a, int b, int m) {
  int64 t = ((int64) a) * b;
  return t % m;
} 

int mod_sum(int a, int b, int m) {
  int64 t = ((int64) a) + b;
  return t % m;
} 

int mod_geosum(int a, int n, int m) {
  std::cout << "a="<< a << " n=" << n << " m=" << m << std::endl;
  if (n == 0) {
    std::cout << "result=" << 1 << std::endl;
    return 1;
  }
  int a1 = mod_sum(a, 1, m);
  if (n == 1) {
    std::cout << "result=" << a1 << std::endl;
    return a1;
  }
  int aa = mod_mul(a, a, m);
  if (n % 2 == 1) {
    int rec = mod_geosum(aa, (n-1) / 2, m);
    std::cout << a1 << " * " << rec << std::endl;
    return mod_mul(rec, a1, m);
  }
  int rec = mod_geosum(aa,  n/2 - 1, m);
  std::cout << "1 + " << a1 << " * " << a << " * " << rec<< std::endl;
  rec = mod_mul(rec, a, m);
  rec = mod_mul(rec, a1, m);
  return mod_sum(rec, 1, m);
}

int main(int argc, const char** argv) {
  // std::cout <<  mod_geosum(5, 1, 7) << std::endl;
  // std::cout <<  mod_geosum(5, 2, 7) << std::endl;
  // std::cout <<  mod_geosum(5, 3, 7) << std::endl;
  // std::cout <<  mod_geosum(5, 4, 7) << std::endl;
  // std::cout <<  mod_geosum(5, 5, 7) << std::endl;
  // std::cout <<  mod_geosum(5, 6, 7) << std::endl;
  std::cout <<  mod_geosum(5, 881, 883) << std::endl;
  return 0;
}


// 1684520592 100000
//  64613 
// 100000