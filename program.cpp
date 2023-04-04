#include <iostream>
#include <string>
#include <thread>
#include <limits>
#include "matrix.h"
#include "calculator.h"
#include "program.h"

Program::Program() {
  std::cout << "Program initialized!" << std::endl;
  // wait one second
  std::this_thread::sleep_for(std::chrono::seconds(1));
  // clear screen
  system("clear");
};

void Program::get_matrix_data() {
  std::cout << "Not implemented yet!" << std::endl;
}

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

  // get matrix data
  double matA_data[rowsA][colsA];
  double matB_data[rowsB][colsB];

  // need to change this to a function
  std::cout << "\nEnter the data for matrix A (seperated by space): " << std::endl;
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < colsA; j++) {
      std::cin >> matA_data[i][j];
    }
  }

  // need to change this to a function
  std::cout << "\nEnter the data for matrix B (seperated by space): " << std::endl;
  for (int i = 0; i < rowsB; i++) {
    for (int j = 0; j < colsB; j++) {
      std::cin >> matB_data[i][j];
    }
  }

  // set matrix data
  matA.set_data(&matA_data[0][0]);
  matB.set_data(&matB_data[0][0]);

  // after defining matrices, clear screen
  system("clear");

  // print matrices
  std::cout << "\nMatrix A:\n" << matA.print_data() << std::endl;
  std::cout << "\nMatrix B:\n" << matB.print_data() << std::endl;

  while (choice != 3) {
    // get choice
    std::cout << "\nChoose an operation:\n========================" << std::endl;
    std::cout << "0. Define Matrices\n1. Addition\n2. Subtraction\n3. Exit" << std::endl;
    std::cout << "========================\nEnter your choice: ";

    while (!(std::cin >> choice)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Enter your choice again: ";
    }

    std::cout << std::endl;
    
    switch(choice) {
      case 0:
        // define new matrices here
        std::cout << "Not implemented yet!" << std::endl;
        break;
      case 1:
        {
          Matrix addition_result = calc.addition(matA, matB);
          
          if (!addition_result.is_empty) {
            std::cout << addition_result.print_data() << std::endl;
          } else {
            std::cout << "Addition not possible!" << std::endl;
          }
          break; 
        }
      case 2:
        {
          Matrix subtraction_result = calc.subtraction(matA, matB);
          
          if (!subtraction_result.is_empty) {
            std::cout << subtraction_result.print_data() << std::endl;
          } else {
            std::cout << "Subtraction not possible!" << std::endl;
          }
          break;
        }   
      case 3:
        std::cout << "Exiting..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        break;
      default:
        std::cout << "Invalid choice. Try again." << std::endl;
        break;
    }
  }
}
