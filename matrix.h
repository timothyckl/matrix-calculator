#include <iostream>
#include <tuple>
#include <string>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
  public:
    Matrix(double* data_i, int rows_i = 1, int cols_i = 1); 
    std::string print_data();
    double* get_data();    
    std::tuple<int, int> get_shape();
  private:
    int rows;
    int cols;
    double* data;
};

#endif // MATRIX_H

