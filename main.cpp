#include <iostream>
#include <tuple>
#include <string>
#include "matrix.h"
#include "calculator.h"

using namespace std;

int main() {
  Matrix matA(3, 3);
  Matrix matB(3, 3);
  Matrix matResult(3, 3);

  double matA_data[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
  double matB_data[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  matA.set_data(&matA_data[0][0]);
  matB.set_data(&matB_data[0][0]);

  Calculator calc;
  cout << "Matrices are conformable: " << calc.is_conformable(matA, matB) << endl;

  cout << "Matrix A:\n" << matA.print_data() << endl;
  cout << "Matrix B:\n" << matB.print_data() << endl;

  calc.addition(matA, matB, matResult);
  /* calc.subtraction(matB, matA, matResult); */
  cout << "Result:\n"<< matResult.print_data() << endl;

  return 0;
}
