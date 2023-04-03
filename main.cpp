#include <iostream>
#include <tuple>
#include <string>
#include "matrix.h"
#include "calculator.h"

using namespace std;

int main() {

  double matA_data[2][2] = {{1, 2}, {3, 4}};
  double matB_data[2][2] = {{5, 6}, {7, 8}};
  double matResult_data[2][2] = {{0, 0}, {0, 0}};

  Matrix matA(&matA_data[0][0], 2, 2);
  Matrix matB(&matB_data[0][0], 2, 2);
  Matrix matResult(&matResult_data[0][0], 2, 2);

  Calculator calc;
  cout << "Matrices are conformable: " << calc.is_conformable(matA, matB) << endl;


  return 0;
}
