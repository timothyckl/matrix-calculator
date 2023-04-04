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

void Calculator::addition(Matrix &matA, Matrix &matB, Matrix &matResult) {
  if (Calculator::is_conformable(matA, matB)) {
    auto [rowsA, colsA] = matA.get_shape();
    auto [rowsB, colsB] = matB.get_shape();

    for (int i = 0; i < rowsA; i++) {
      for (int j = 0; j < colsA; j++) {
        matResult.get_data()[i * colsA + j] = 
          matA.get_data()[i * colsA + j] + matB.get_data()[i * colsB + j];
      }
    }
  }
  else { 
    std::cout << "Matrices are not conformable for addition." << std::endl; 
  }  
}

void Calculator::subtraction(Matrix &matA, Matrix &matB, Matrix &matResult) {
  if (Calculator::is_conformable(matA, matB)) {
    auto [rowsA, colsA] = matA.get_shape();
    auto [rowsB, colsB] = matB.get_shape();

    for (int i = 0; i < rowsA; i++) {
      for (int j = 0; j < colsA; j++) {
        matResult.get_data()[i * colsA + j] = 
          matA.get_data()[i * colsA + j] - matB.get_data()[i * colsB + j];
      }
    }
  }
  else { 
    std::cout << "Matrices are not conformable for subtraction." << std::endl; 
  }  
}
