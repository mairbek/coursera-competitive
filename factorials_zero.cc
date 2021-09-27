#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <unordered_map>

namespace {

} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int n, b;

  std::cin >> n >> b;

  int mindiv[b+1];
  for (int i = 0; i <=b; i++) {
    mindiv[i] = 0;
  }
  std::vector<int> primes;

  for (int i = 2; i <= b; i++) {
    if (mindiv[i] == 0) {
      primes.push_back(i);
      mindiv[i] = i;
    }
    for (int j = 0; j < primes.size(); j++) {
      int q = primes[j];
      if (q > mindiv[i] || q * i > b) {
        break;
      }
      mindiv[q * i] = q;
    }
  }
  std::unordered_map<int, int> factors;
  int m = b;
  while (m > 1) {
    int p = mindiv[m];
    if (factors.count(p) == 0) {
      factors[p] = 0;
    }
    factors[p] += 1;
    // std::cout << "factor " << p << std::endl; 
    m /= p;
  }
  int max_pb = -1;
  int mb = 0;
  for (auto const& pf : factors) {
    int pb = pf.first;
    if (pb > max_pb) {
      max_pb = pb;
      mb = pf.second;
    }
  }
  int vb = 0;
  int pb = max_pb;
  int pi = pb;
  while (n/pi > 0) {
    // std::cout << "fefe " << pi << " " << b << std::endl; 
    vb += n/pi;
    pi *= pb;
  }

  vb /= mb;

  std::cout << vb << std::endl;

}
