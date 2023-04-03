#include <iostream>
#include <tuple>
#include <string>
#include "matrix.h"

using namespace std;

int main() {
  int rows = 3;
  int cols = 2;

  double data[rows][cols] = {{1, 2}, {3, 4}, {5, 6}};
  Matrix m(&data[0][0], rows, cols);
  cout << m.print_data() << endl;
  return 0;
}
