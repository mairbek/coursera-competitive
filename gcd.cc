#include <iostream>
#include <bitset>

namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int64 a, b;

  std::cin >> a >> b;

  if (b > a) {
    int64 tmp = a;
    a = b;
    b = tmp;
  }

  while (b > 0) {
    int64 temp = a;
    a = b;
    b = temp % b;
  }
  std::cout << a << std::endl;
  return 0;
}
