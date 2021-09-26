#include <iostream>
#include <vector>
#include <unordered_map>

namespace {
} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int64 a, b;

  std::cin >> a >> b;

  std::vector<int> q;

  q.push_back(a / b);
  int c = 10 * (a % b);
  int k = 1;
  std::unordered_map<int, int> visited;
  int period = -1;
  while (true) {
    if (visited.count(c) > 0) {
      if (c == 0) {
        k = k - 1;
      } else {
        period = visited[c];
      }
      break;
    }
    int d = c / b;
    q.push_back(d);
    visited[c] = k;
    c = 10 * (c % b);
    k++;
  }

  std::cout << q[0];
  if (k == 1) {    
   std::cout << std::endl;
   return 0;
  }
  std::cout << ".";
  if (period < 0) {
    for (int i = 1; i < k; i++) {
      std::cout << q[i];
    }
  } else {
    for (int i = 1; i < period; i++) {
      std::cout << q[i];
    }
    std::cout << "(";
    for (int i = period; i < k; i++) {
      std::cout << q[i];
    }
    std::cout << ")";
  }
  std::cout << std::endl;
  
  return 0;
}
