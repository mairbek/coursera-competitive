#include <iostream>
#include <string>
#include <cstdlib>

namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  std::string in;

  std::cin >> in;

  int64 sum = 0;
  int multi = 1;
  int64 val = 0;
  for (size_t i = 0; i < in.length(); i++) {
    if (in[i] == '+') {
      sum += multi * val;
      val = 0;
      multi = 1;
    } else if (in[i] == '-') {
      sum += multi * val;
      val = 0;
      multi = -1;
    } else {
      val *= 10;
      val += (in[i] - '0');
    }
  }
  sum += multi * val;

  std::cout << sum << std::endl;
}
