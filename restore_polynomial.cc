#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
namespace
{

void poly_sum(const std::vector<int>& x, const std::vector<int>&y, std::vector<int>* z) {
  int n = std::max(x.size(), y.size());
  for (int i = 0; i < n; i++) {
    int xi = 0;
    if (i < x.size()) {
      xi = x[i];
    }
    int yi = 0;
    if (i < y.size()) {
      yi = y[i];
    }
    z->push_back(xi+yi);
  }
}

void poly_multi(const std::vector<int>& x, const std::vector<int>&y, std::vector<int>* z) {
  int n = x.size();
  int m = y.size();
  for (int k = 0; k < n + m - 1; k++) {
    int zk = 0;
    for (int i = 0; i <= k; i++) {
      int xi = 0;
      if (i < n) {
        xi = x[i];
      }
      int yki = 0;
      if ((k-i) < m) {
        yki = y[k-i];
      }
      // std::cout << "k=" << k << " i=" << i << " xi=" << xi << " yki=" << yki <<std::endl;
      zk += xi * yki;
    }
    z->push_back(zk);
  }
}

} // namespace

int main(int argc, const char **argv) {
  int n = 10;
  std::vector<int> x(n, 0);
  std::vector<int> y(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }

  std::vector<int> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = y[i];
  }
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
      c[j] = (c[j] - c[i])/(x[j] - x[i]);
    }
  }

  std::vector<int> f;
  f.push_back(c[0]);
  std::vector<int> poly;
  poly.push_back(1);
  
  for (int k = 0; k<6; k++) {
    std::vector<int> xx;
    xx.push_back(-x[k]);
    xx.push_back(1);
    std::vector<int> temp_poly;
    poly_multi(poly, xx, &temp_poly);
    std::swap(poly, temp_poly);

    std::vector<int> cpoly;
    for (int i = 0; i < poly.size(); i++) {
      cpoly.push_back(c[k+1] * poly[i]);
    }
    std::vector<int>tempf;
    poly_sum(f, cpoly, &tempf);
    std::swap(f, tempf);
  }

  for (int i = f.size() - 2; i >= 0; i--) {
    std::cout << f[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
