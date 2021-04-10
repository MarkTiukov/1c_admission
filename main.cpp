#include <iostream>
#include "max_det_finder.hpp"

bool check(int n, int a[n][n], int b[n][n]) {
  for (int i = 0; i < n; i++) {
    std::vector<int> v1, v2;
    int r = i;
    int col = 0;
    while (r >= 0 && col < n) {
      v1.push_back(a[r][col]);
      v2.push_back(b[r][col]);
      r--;
      col++;
    }
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++) {
      if (v1[i] != v2[i])
        return false;
    }
  }
  for (int j = 1; j < n; j++) {
    std::vector<int> v1, v2;
    int r = n - 1;
    int col = j;

    while (r >= 0 && col < n) {
      v1.push_back(a[r][col]);
      v2.push_back(b[r][col]);
      r--;
      col++;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++) {
      if (v1[i] != v2[i])
        return false;
    }
  }
  return true;
}

int main() {
  std::vector<std::vector<int>> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> m2 = {{1, 4, 7}, {2, 5, 6}, {3, 8, 9}};
  Matrix mat1(m1);
  Matrix mat2(m2);
  std::cout << mat1.CanBeTransformed(mat2) << std::endl;
}
