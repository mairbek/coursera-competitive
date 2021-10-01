#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
#include <vector>
#include <unordered_map>

namespace {
class Bignum {
 public:
  Bignum() : negative_(false) {
    nvec_.push_back(1);
  }

 void mul(int m) {
  int msize = ((double) m) / 10. + 1;
  std::vector<int> z(nvec_.size() + msize, 0);
  for (int ii = 0; ii < nvec_.size(); ii++) {
    int carry = 0;
    int mi = m;
    int jj = 0;
    for (jj = 0; jj < msize; jj++) {
      int yy = mi % 10; 
      int t = nvec_[ii] * yy + z[ii+jj] + carry;
      z[ii+jj] = t % 10;
      carry = t / 10; 
      mi /= 10;
    }
    if (carry > 0) {
      z[ii+jj] = carry;
    }
  }
  nvec_ = z;
  // print();
  int i = z.size() - 1;
  while (i >= 0 && z[i] == 0) {
    z.pop_back();
    i--;
  }
  nvec_ = z;
 }

 void mul(Bignum m) {
  int msize = m.nvec_.size();
  std::vector<int> z(nvec_.size() + msize, 0);
  for (int ii = 0; ii < nvec_.size(); ii++) {
    int carry = 0;
    int jj = 0;
    for (jj = 0; jj < msize; jj++) {
      int yy = m.nvec_[jj]; 
      int t = nvec_[ii] * yy + z[ii+jj] + carry;
      z[ii+jj] = t % 10;
      carry = t / 10; 
    }
    if (carry > 0) {
      z[ii+jj] = carry;
    }
  }
  nvec_ = z;
  // print();
  int i = z.size() - 1;
  while (i >= 1 && z[i] == 0) {
    z.pop_back();
    i--;
  }
  nvec_ = z;
 }

 void dec() {
  int carry = 0;
  for (int i = 0; i < nvec_.size(); i++) {
    int k = i == 0 ? 1 : 0;
    int t = nvec_[i] - k + carry;
    if (t < 0) {
      nvec_[i] = t + 10;
      carry = - 1;
    } else {
      nvec_[i] = t;
      carry = 0;
      break;
    }
  }
 }

 void neg() {
   negative_ = -1;
 }

 void print() {
  bool zero = nvec_.size() == 1 && nvec_[0] == 0;
  if (negative_ && !zero) {
    std::cout << "-";
  }
  for (int i = nvec_.size() - 1; i >= 0; i--) {
    std::cout << nvec_[i];
  }
  std::cout << std::endl;
 }

 private:
  std::vector<int> nvec_;
  bool negative_;
};
} // namespace

using int64 = long long;

int main(int argc, const char** argv) {
  int n, m;

  std::cin >> n >> m;

  // n! - m! = n*b-b = (n-1)*b
  Bignum b;
  Bignum bn;
  for (int i = 2; i <= std::max(n, m); i++) {
    if (i <= n && i <= m) {
      b.mul(i);
      continue;
    }
    bn.mul(i);
  }
  bn.dec();
  bn.mul(b);
  if (m > n) {
    bn.neg();
  }
  bn.print();
}
