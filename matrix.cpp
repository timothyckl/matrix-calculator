#include <iostream>
#include <tuple>
#include <string>
#include "matrix.h"

Matrix::Matrix(int rows_i, int cols_i) {
  rows = rows_i;
  cols = cols_i;
  data = new double[rows * cols];
 
  // matrix is always initialized to zero
  for (int i = 0; i < rows * cols; i++) {
    data[i] = 0;
  }

  Matrix::is_empty = true;  // matrix is considered empty if it is a zero matrix
}; 

std::string Matrix::print_data() { 
  auto [rows, cols] = Matrix::get_shape();
  std::string data_str = "";

  for (int i = 0; i < rows; i++) {
    data_str += "[\t";
    for (int j = 0; j < cols; j++) {
      data_str += std::to_string(data[i * cols + j]) + "\t";
    }
    data_str += "\t]\n";
  }
  return data_str;
};

double* Matrix::get_data() {
  return data;
};      

void Matrix::set_data(double* data_i) {
  data = data_i;
  Matrix::is_empty = false;
};

std::tuple<int, int> Matrix::get_shape() {
  return std::make_tuple(rows, cols);
};
