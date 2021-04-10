#include "max_det_finder.hpp"

Matrix::Matrix(const std::vector<std::vector<int>>& matrix) {
  matrix_ = matrix;
  size_ = matrix.size();
}

void Matrix::ReflectFromMain() {
  for (int i = 0; i < matrix_.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      std::swap(matrix_[i][j], matrix_[j][i]);
    }
  }
}

void Matrix::ReflectFromSecondary() {
  for (int i = 0; i < matrix_.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      std::swap(matrix_[i][j], matrix_[matrix_.size() - 1 - j][matrix_.size() - 1 - i]);
    }
  }
}

bool Matrix::CanBeTransformed(const Matrix& other) const {
  if (other.size_ != size_)
    return false;
  for (int i = 0; i < size_; i++) {
    std::vector<int> v1, v2;
    int r = i;
    int col = 0;
    while (r >= 0 && col < size_) {
      v1.push_back(matrix_[r][col]);
      v2.push_back(other.matrix_[r][col]);
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
  for (int j = 1; j < size_; j++) {
    std::vector<int> v1, v2;
    int r = size_ - 1;
    int col = j;

    while (r >= 0 && col < size_) {
      v1.push_back(matrix_[r][col]);
      v2.push_back(other.matrix_[r][col]);
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



