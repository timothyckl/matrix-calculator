#include <iostream>
#include <limits>

using namespace std;

const int M_SIZE = 3;
typedef double matrix [M_SIZE][M_SIZE];  // defines alias for list (of lists) 
                                           // of doubles aka matrices

/* matrix m1 = { */
/*   {1.23, 2.34},  */
/*   {3.45, 4.56} */
/* }   */

void print_matrix(matrix &m);
bool create_matrix(matrix &m);
void define_matrix();
void addition(matrix &m1, matrix &m2, matrix &m_result);
void subtraction(matrix &m1, matrix &m2, matrix &m_result);

matrix mat_A;
matrix mat_B;
matrix mat_result;

void print_matrix(matrix &m) {
  for (int i = 0; i < M_SIZE; i++) {
    cout << "[";
    
    for (int j = 0; j < M_SIZE; j++) {
      cout << m[i][j] << "\t";
    }

    cout << "]\n";
  }
};

void define_matrix() {
  while (true) {
    cout << "input 9 elements into your 3x3 matrix A: \n";
    if (create_matrix(mat_A)) {
      
      while (true) {
        cout << "input 9 elements into your 3x3 matrix B: \n";
        if (create_matrix(mat_B)) {
          break;
        }
      }
      
      break;
    
    }
  }
};

bool create_matrix(matrix &m) {
  for (int i = 0; i < M_SIZE; i++) {
    for (int j = 0; j < M_SIZE; j++) {
      cin >> m[i][j];
      
      if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please try again. \n";
        
        return false;
      }
    }
  }  
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  return true;
};

void addition(matrix &m_A, matrix &m_B, matrix &m_res) {
  for (int i = 0; i < M_SIZE; i++) {
    for (int j = 0; j < M_SIZE; j++) {
      m_res[i][j] = m_A[i][j] + m_B[i][j]; 
    }
  } 
};

void subtraction(matrix &m_A, matrix &m_B, matrix &m_res) {
  for (int i = 0; i < M_SIZE; i++) {
    for (int j = 0; j < M_SIZE; j++) {
      m_res[i][j] = m_A[i][j] - m_B[i][j]; 
    }
  } 
};

int main() {
  int choice = -1;  // initialize to an invalid choice
        
  cout << "When filling up matrices, separate individual\nelements by " 
    << "a space (e.g 2 4 1.4 56.3 ...) \n\n";
  
  define_matrix();
  system("clear");  // replace with os-specific command (cls/clear) 
  
  while (choice != 3) {
    cout << "\nMatrix A: \n";
    print_matrix(mat_A);
    cout << "\nMatrix B: \n";
    print_matrix(mat_B);
  
    cout << "\n******** Pick an option ********\n"
      << "0) Define Matrix\n"
      << "1) Addition\n"
      << "2) Subtraction\n"
      << "3) Exit\n"
      << "********************************\n"
      << "Your choice: ";
    
    while (!(cin >> choice)) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cerr << "Invalid input. Please try again. \n"
        << "Enter your choice again: ";
    }
  
    cout << endl;
    
    switch(choice) {
      case 0:
        define_matrix();
        break;
      case 1:
        addition(mat_A, mat_B, mat_result);
        cout << "Performing matrix addition:\n\nResult:\n";
        print_matrix(mat_result);
      
        break;
      case 2:
        subtraction(mat_A, mat_B, mat_result);
        cout << "\nPerforming matrix subtraction:\n\nResult:\n";
        print_matrix(mat_result);

        break;
      default:
        break;
    }
    cout << "\nPress any key to continue...";
    cin .ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("clear");
  }  

  return 0; 
  
}
