#pragma once

#include <vector>

class Matrix {
 public:
  Matrix() = delete;
  Matrix(const std::vector<std::vector<int>>& matrix);
  Matrix(const Matrix& matrix) = default;

  bool CanBeTransposed(const Matrix& other) const;
  long long Determinant() const;
  size_t AbsDeterminant() const;

  size_t FindMaxDeterminant();

 private:
  void ReflectFromMain();
  void ReflectFromSecondary();

  size_t LookThroughBlack();


 private:
  std::vector<std::vector<int>> matrix_;
  size_t size_;
};
