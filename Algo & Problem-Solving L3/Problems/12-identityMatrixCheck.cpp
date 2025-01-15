#include "Utility.h"

bool isIdentityMatrix(const Matrix& matrix, int rows, int cols) {
    if (rows != cols) return false;  // Identity matrix must be square

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                return false;
            } else {
                return true;
            }
        }
    }

    return true;
}

int main() {
    int rows = utility::getValidPositiveInt("Enter the number of rows: ");
    int cols = utility::getValidPositiveInt("Enter the number of columns: ");

    Matrix matrix = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    utility::PrintMatrix(matrix, rows, cols);

    if (isIdentityMatrix(matrix, rows, cols)) {
        std::cout << "The matrix is an identity matrix." << std::endl;
    } else {
        std::cout << "The matrix is not an identity matrix." << std::endl;
    }

    return 0;
}

// in compilation you have to compile utility.cpp with this file together or it will not work
// command : g++ 12-identityMatrixCheck.cpp Utility.cpp -o name