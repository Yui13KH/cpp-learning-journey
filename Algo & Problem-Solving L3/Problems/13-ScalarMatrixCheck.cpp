#include "Utility.h"

bool isScalarMatrix(const Matrix& matrix, int rows, int cols) {
    int scalarValue = matrix[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((i == j && matrix[i][j] != scalarValue) || (i != j && matrix[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

void printIsScalarMatrix(const Matrix& matrix, int rows, int cols) {
    if (isScalarMatrix(matrix, rows, cols)) {
        std::cout << "The matrix is a scalar matrix." << std::endl;
    } else {
        std::cout << "The matrix is NOT a scalar matrix." << std::endl;
    }
}

int main() {
    int rows = utility::getValidPositiveInt("Enter the number of rows: ");
    int cols = utility::getValidPositiveInt("Enter the number of columns: ");

    Matrix matrix = {{1, 0, 0}, {0, 2, 0}, {0, 0, 1}};

    utility::PrintMatrix(matrix, rows, cols);

    printIsScalarMatrix(matrix, rows, cols);

    return 0;
}

// in compilation you have to compile utility.cpp with this file together or it will not work
// command : g++ 13-ScalarMatrixCheck.cpp Utility.cpp -o name