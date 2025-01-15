#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using Matrix = std::vector<std::vector<int>>;

int getValidPositiveInt(const std::string& prompt) {
    int input;
    std::string line;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        if (iss >> input && input > 0 && iss.eof()) {
            return input;
        }

        std::cout << "Please enter a valid positive integer: ";
    }
}

int RandomNumberInRange(int min, int max) { return rand() % (max - min + 1) + min; }

Matrix generateRandomMatrix(int rows, int cols) {
    Matrix matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = RandomNumberInRange(1, 100);  // [1, 100] range for now
        }
    }
    return matrix;
}

bool matricesAreEqual(const Matrix& matrix1, const Matrix& matrix2, const int& rows,
                      const int& columns) {
    bool areEqual = true;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix1[i][j] == matrix2[i][j]) {
                return areEqual;
            } else {
                areEqual = false;
                return areEqual;
            }
        }
    }
    return areEqual;
}

void PrintMatrix(const Matrix& matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(unsigned(time(NULL)));
    // int columns = getValidPositiveInt("Input Column Size: ");
    // int rows = getValidPositiveInt("Input Row Size: ");

    int columns = 3;
    int rows = 3;

    // Matrix matrix1 = generateRandomMatrix(rows, columns);
    // Matrix matrix2 = generateRandomMatrix(rows, columns);
    // its impossible to generate 2 matrices that are equal

    Matrix matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // for testing 

    PrintMatrix(matrix1, rows, columns);
    std::cout << "\n" << "------" << "\n";
    PrintMatrix(matrix2, rows, columns);

    if (matricesAreEqual(matrix1, matrix2, rows, columns)) {
        std::cout << "\n" << "Matrices are equal" << "\n";
    } else {
        std::cout << "\n" << "Matrices are not equal" << "\n";
    }

    return 0;
}