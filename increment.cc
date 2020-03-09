#include <iostream>

namespace {

} // namespace

int main(int argc, const char** argv) {
  std::string x;
  std::cin >> x;
  int n = x.length();
  bool all_nines = true;
  for (int i = 0; i < n; i++) {
    if (x[i] != '9') {
      all_nines = false;
      break;
    }
  }
  if (n > 0 && all_nines) {
    n++;
  }
  std::cout << n << std::endl;
  return 0;
}
