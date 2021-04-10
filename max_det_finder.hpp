#pragma once

#include <vector>

class Matrix {
 public:
  Matrix() = delete;
  Matrix(const std::vector<std::vector<int>>& matrix);

  bool CanBeTransformed(const Matrix& other) const;

 private:
  void Determinant() const;
  void ReflectFromMain();
  void ReflectFromSecondary();


 private:
  std::vector<std::vector<int>> matrix_;
  size_t size_;
};
