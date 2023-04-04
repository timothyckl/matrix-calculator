#include <iostream>
#include <string>
#include "matrix.h"

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
  public:
    Calculator(std::string mode_i="matrix");
    bool is_conformable(Matrix &matA, Matrix &matB);
    void addition(Matrix &matA, Matrix &matB, Matrix &matResult);
    void subtraction(Matrix &matA, Matrix &matB, Matrix &matResult);

  private:
    std::string mode;
};

#endif // CALCULATOR_H
