#include <iostream>
#include <tuple>
#include <string>
#include "matrix.h"
#include "calculator.h"

using namespace std;

int main() {
  Matrix matA(2, 2);
  Matrix matB(2, 2);
  Matrix matResult(2, 2);

  double matA_data[2][2] = {{1, 2}, {3, 4}};
  double matB_data[2][2] = {{5, 6}, {7, 8}};

  matA.set_data(&matA_data[0][0]);
  matB.set_data(&matB_data[0][0]);

  Calculator calc;
  cout << "Matrices are conformable: " << calc.is_conformable(matA, matB) << endl;

  cout << "Matrix A:\n" << matA.print_data() << endl;
  cout << "Matrix B:\n" << matB.print_data() << endl;

  calc.addition(matA, matB, matResult);
  cout << "Result:\n"<< matResult.print_data() << endl;


  return 0;
}
