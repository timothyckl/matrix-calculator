#include <iostream>
#include <tuple>
#include <string>

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
  public:
    Matrix(int rows_i = 1, int cols_i = 1); 
    bool is_empty;
    std::string print_data();
    double* get_data();    
    void set_data(double* data_i);
    std::tuple<int, int> get_shape();
  
  private:
    int rows;
    int cols;
    double* data;
};

#endif // MATRIX_H
