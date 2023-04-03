#include <iostream>
#include <tuple>
#include <string>
#include "matrix.h"

Matrix::Matrix(double* data_i, int rows_i, int cols_i) {
  rows = rows_i;
  cols = cols_i;
  data = new double[rows * cols];

  for (int i = 0; i < rows * cols; i++) {
    data[i] = data_i[i];
  }
}; 

std::string Matrix::print_data() {
  /* double* result = Matrix::get_data(); */
  auto [rows, cols] = Matrix::get_shape();
  std::string data_str = "";

  for (int i = 0; i < rows; i++) {
    data_str += "[";
    for (int j = 0; j < cols; j++) {
      data_str += std::to_string(data[i * cols + j]);
      if (j < cols - 1) {
        data_str += ", ";
      }
    }
    data_str += "]\n";
  }
  return data_str;
};

double* Matrix::get_data() {
  return data;
};      

std::tuple<int, int> Matrix::get_shape() {
  return std::make_tuple(rows, cols);
};
