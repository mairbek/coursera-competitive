#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int n;

  std::cin >> n;

  int64 a[n];
  int64 b[n];

  for (int i = 0; i < n; i++) {
    double temp;
    std::cin >> temp;
    a[i] = (int64) round(temp * 1000);
  }
  for (int i = 0; i < n; i++) {
    double temp;
    std::cin >> temp;
    b[i] = (int64) round(temp * 1000);
  }

  int64 suma = 0;
  int64 sumb = 0;

  for (int i = 0; i < n; i++) {
    suma += a[i];
    sumb += b[i];
  }

  std::cout << "SUM(A)";
  if (suma == sumb) {
    std::cout << "=";
  } else if (suma < sumb) {
    std::cout << "<";
  } else {
    std::cout << ">";
  }
  std::cout << "SUM(B)" << std::endl;
}
