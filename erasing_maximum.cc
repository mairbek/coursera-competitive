#include <iostream>

namespace {

} // namespace

int main(int argc, const char** argv) {
  int n;
  std::cin >> n;

  int* arr = new int[n];

  int max = 0;
  int max_count = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];

    if (arr[i] == max) {
      max_count++;
    }
    if (arr[i] > max) {
      max = arr[i];
      max_count = 1;
    }
  }

  int k = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == max) {
      k++;
      if (max_count == 1) {
        continue;
      }
      if (max_count > 1 && k == 3) {
        continue;
      }
    }
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
  

  return 0;
}
