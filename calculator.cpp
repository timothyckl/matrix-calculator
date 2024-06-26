#include <iostream>
#include <string>
#include "matrix.h"
#include "calculator.h"

Calculator::Calculator(std::string mode_i) {
  mode = mode_i;
}

bool Calculator::is_conformable(Matrix &matA, Matrix &matB) {
  auto [rowsA, colsA] = matA.get_shape(); 
  auto [rowsB, colsB] = matB.get_shape();

  if (rowsA == rowsB && colsA == colsB) { return true; }
  else { return false; }
}

Matrix Calculator::addition(Matrix &matA, Matrix &matB) { 
  auto [rowsA, colsA] = matA.get_shape();
  auto [rowsB, colsB] = matB.get_shape();
  Matrix result(rowsA, colsB);
  
  if (Calculator::is_conformable(matA, matB)) {
    for (int i = 0; i < rowsA; i++) {
      for (int j = 0; j < colsA; j++) {
        result.get_data()[i * colsA + j] = 
          matA.get_data()[i * colsA + j] + matB.get_data()[i * colsB + j];
      }
    }
    result.is_empty = false;
    return result;
  }
  else {
    result.is_empty = true;
    std::cout << "Matrices are not conformable for addition." << std::endl; 
  }
  return result;
}

Matrix Calculator::subtraction(Matrix &matA, Matrix &matB) {
  auto [rowsA, colsA] = matA.get_shape();
  auto [rowsB, colsB] = matB.get_shape();
  Matrix result(rowsA, colsB);
  
  if (Calculator::is_conformable(matA, matB)) {
    for (int i = 0; i < rowsA; i++) {
      for (int j = 0; j < colsA; j++) {
        result.get_data()[i * colsA + j] = 
          matA.get_data()[i * colsA + j] - matB.get_data()[i * colsB + j];
      }
    }
    result.is_empty = false;
  }
  else { 
    result.is_empty = true;
    std::cout << "Matrices are not conformable for subtraction." << std::endl;  
  }  
  return result;
}
