#include "max_det_finder.hpp"

Matrix::Matrix(const std::vector<std::vector<int>>& matrix) {
  matrix_ = matrix;
  size_ = matrix.size();
}

void Matrix::ReflectFromMain() {
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < i; ++j) {
      std::swap(matrix_[i][j], matrix_[j][i]);
    }
  }
}

void Matrix::ReflectFromSecondary() {
  for (int i = 0; i < size_; ++i) {
    for (int j = 0; j < i; ++j) {
      std::swap(matrix_[i][j], matrix_[size_ - 1 - j][size_ - 1 - i]);
    }
  }
}

bool Matrix::CanBeTransposed(const Matrix& other) const {
  if (other.size_ != size_)
    return false;
  for (int i = 0; i < size_; i++) {
    std::vector<int> v1, v2;
    int row = i;
    int col = 0;
    while (row >= 0 && col < size_) {
      v1.push_back(matrix_[row][col]);
      v2.push_back(other.matrix_[row][col]);
      row--;
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
    int row = size_ - 1;
    int col = j;

    while (row >= 0 && col < size_) {
      v1.push_back(matrix_[row][col]);
      v2.push_back(other.matrix_[row][col]);
      row--;
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
long long Matrix::Determinant() const {
  switch (size_) {
    case 1:return (matrix_[0][0]);
    case 2:return (matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0]);
    default: {
      int det = 0;
      for (int p = 0; p < matrix_[0].size(); p++) {
        std::vector<std::vector<int>> minor;
        for (int i = 1; i < size_; i++) {
          std::vector<int> row;
          for (int j = 0; j < matrix_[i].size(); j++) {
            if (j != p) {
              row.push_back(matrix_[i][j]);
            }
          }
          if (row.size() > 0)
            minor.push_back(row);
        }
        det = det + matrix_[0][p] * pow(-1, p) * Matrix(minor).Determinant();
      }
      return det;
    }
  }

}



