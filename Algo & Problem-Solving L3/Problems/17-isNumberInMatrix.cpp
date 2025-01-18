#include "Utility.h"

bool isNumberInMatrix(const int& targetNumber, const Matrix& matrix, const int& rows,
                      const int& cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == targetNumber) {
                return true;
            } else {
                return false;
            }
        }
    }
    return true;
}

void PrintIsNumberInMAtrix(const int& targetNumber, const Matrix& matrix, const int& rows,
                           const int& cols) {
    if (isNumberInMatrix(targetNumber, matrix, rows, cols)) {
        std::cout << "Yes the number is in the matrix" << std::endl;
    } else {
        std::cout << "No the number is not in the matrix" << std::endl;
    }
}

int main() {
    srand(unsigned(time(NULL)));
    int matrixRows = utility::getValidPositiveInt("Enter matrix rows: ");
    int matrixColumns = utility::getValidPositiveInt("Enter matrix cols: ");
    int targetNumber = utility::getValidPositiveInt("Enter number to search for: ");

    Matrix matrix = utility::generateRandomMatrix(matrixRows, matrixColumns, 1,100);

    utility::PrintMatrix(matrix);

    PrintIsNumberInMAtrix(targetNumber, matrix, matrixRows, matrixColumns);

    return 0;
}

// command to compiler : g++ 17-isNumberInMatrix.cpp Utility.cpp -o name