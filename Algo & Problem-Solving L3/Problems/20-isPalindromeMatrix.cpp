#include "Utility.h"

bool isPalindromeMatrix(const Matrix& matrix) {
    // it checks if first element in the column is equal to last element in the column
    // if matrix bigger then 3 x 3 it adds 1 to the start and subtracts 1 from the end
    // loop over each row

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] != matrix[i][matrix[i].size() - j - 1]) {
                return false;
            }
        }
    }

    return true;
}

void printIsPalindromeMatrix(Matrix matrix) {
    if (isPalindromeMatrix(matrix)) {
        std::cout << "The matrix is a palindrome matrix" << std::endl;
    } else {
        std::cout << "The matrix is not a palindrome matrix" << std::endl;
    }
}

int main() {
    srand(unsigned(time(NULL)));
    int rows = utility::getValidPositiveInt("Enter matrix rows: ");
    int cols = utility::getValidPositiveInt("Enter matrix cols: ");

    Matrix randomMatrix = utility::generateRandomMatrix(rows, cols, 1, 100);
    Matrix palindromeMatrix = {{1, 2, 1}, {2, 3, 2}, {1, 2, 1}};

    utility::PrintMatrix(randomMatrix);
    std::cout << "\n" << "------" << "\n";
    utility::PrintMatrix(palindromeMatrix);

    printIsPalindromeMatrix(randomMatrix);
    printIsPalindromeMatrix(palindromeMatrix);

    return 0;
}

// command to compiler : g++ 20-isPalindromeMatrix.cpp Utility.cpp -o name