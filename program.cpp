#include <iostream>
#include <string>
#include "matrix.h"
#include "calculator.h"
#include "program.h"

Program::Program() {
  std::cout << "Program initialized!" << std::endl;
};

void Program::run() {
  int choice = -1;

  // define matrix sizes
  int rowsA, colsA, rowsB, colsB;
 
  // Matrix A 
  std::cout << "\nEnter Matrix A details:\n==================" << std::endl;
  std::cout << "No. of rows: ";
  std::cin >> rowsA;
  std::cout << "No. of columns: ";
  std::cin >> colsA;

  // Matrix B
  std::cout << "\nEnter Matrix B details:\n==================" << std::endl;
  std::cout << "No. of rows: ";
  std::cin >> rowsB;
  std::cout << "No. of columns:";
  std::cin >> colsB;

  // create calculator
  Calculator calc;
  
  // create matrices
  Matrix matA(rowsA, colsA);
  Matrix matB(rowsB, colsB);

  // check if matrices are conformable
  if (calc.is_conformable(matA, matB)) {
    // create result matrix
    Matrix matResult(rowsA, colsA);
  } 
  else {
    std::cout << "\nMatrices are not conformable!" << std::endl;
    // need to reprompt user for matrix sizes
  }

  // get matrix data
  double matA_data[rowsA][colsA];
  double matB_data[rowsB][colsB];

  std::cout << "\nEnter the data for matrix A seperated by a comma: " << std::endl;
  


  // after defining matrices, clear screen
  /* system("clear"); */

  

  /* Matrix matA(3, 3); */
  /* Matrix matB(3, 3); */
  /* Matrix matResult(3, 3); */

  /* double matA_data[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}}; */
  /* double matB_data[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; */

  /* matA.set_data(&matA_data[0][0]); */
  /* matB.set_data(&matB_data[0][0]); */

  /* Calculator calc; */
  /* std::cout << "Matrices are conformable: " << calc.is_conformable(matA, matB) << std::endl; */

  /* std::cout << "Matrix A:\n" << matA.print_data() << std::endl; */
  /* std::cout << "Matrix B:\n" << matB.print_data() << std::endl; */

  /* calc.addition(matA, matB, matResult); */
  /* calc.subtraction(matB, matA, matResult); */

  /* std::cout << "Result:\n"<< matResult.print_data() << std::endl; */
}

