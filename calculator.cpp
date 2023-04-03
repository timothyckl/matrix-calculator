#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

class Calculator {
  public:
    Calculator(string mode_i="matrix") {
      mode = mode_i;
    }

    bool is_conformable(Matrix &matA, Matrix &matB) {
      auto [rowsA, colsA] = matA.get_shape();
      auto [rowsB, colsB] = matB.get_shape();

      if (rowsA == rowsB && colsA == colsB) { return true; }
      else { return false; }
    }

    void addition(Matrix &matA, Matrix &matB, Matrix &matResult) {
      if (is_conformable(matA, matB)) {
        auto [rowsA, colsA] = matA.get_shape();
        auto [rowsB, colsB] = matB.get_shape();

        for (int i = 0; i < rowsA; i++) {
          for (int j = 0; j < colsA; j++) {
            matResult.get_data()[i * colsA + j] = 
              matA.get_data()[i * colsA + j] + matB.get_data()[i * colsA + j];
          }
        }
      }
      else { 
        cout << "Matrices are not conformable for addition" << endl; 
      } 
    }

  private:
    string mode;
};

int main() {
  double matA_data[2][2] = {{1, 2}, {3, 4}};
  double matB_data[2][2] = {{5, 6}, {7, 8}};
  double matResult_data[2][2] = {{0, 0}, {0, 0}};

  Matrix matA(&matA_data[0][0], 2, 2);
  Matrix matB(&matB_data[0][0], 2, 2);
  Matrix matResult(&matResult_data[0][0], 2, 2);

  Calculator calc;
  /* bool comformable = calc.is_conformable(matA, matB); */
  /* cout << "Matrices are conformable: " << comformable << endl; */

  calc.addition(matA, matB, matResult);
  cout << matResult.print_data() << endl;

  return 0;
};


