#include <iostream>
#include "max_det_finder.hpp"

int main() {
  size_t size;
  std::cout << "Введите размер:" << std::endl;
  std::cin >> size;
  std::cout << "Введите матрицу:" << std::endl;
  std::vector<std::vector<int>> matrix(size, std::vector<int>(size));
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      std::cin >> matrix[i][j];
    }
  }
  std::cout << "Максимальный модуль определителя равен " << Matrix(matrix).FindMaxDeterminant() << std::endl;
}
