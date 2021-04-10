#pragma once

#include <vector>

class Matrix {
 public:
  Matrix() = delete;
  Matrix(const std::vector<std::vector<int>>& matrix);

  bool CanBeTransposed(const Matrix& other) const;
  long long Determinant() const;

 private:
  void ReflectFromMain();
  void ReflectFromSecondary();

 private:
  std::vector<std::vector<int>> matrix_;
  size_t size_;
};
