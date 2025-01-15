#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

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

Matrix generateMatrix(int rows, int cols) {
    int counter = 1;
    Matrix matrix(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = counter++;
        }
    }

    return matrix;
}

Matrix addMatrices(const Matrix& matrix1, const Matrix& matrix2, int rows, int cols) {
    Matrix SumMatrix(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            SumMatrix[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }

    return SumMatrix;
}

void printMatrix(const Matrix& matrix) {
    std::cout << "\nGenerated Matrix:\n";
    for (const auto& row :
         matrix) {  // using auto here cause saying std::vector<int>& is a hassle to type
        for (int column : row) {
            std::cout << std::setw(3) << column << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int rows = getValidPositiveInt("Enter the number of rows: ");
    int cols = getValidPositiveInt("Enter the number of columns: ");

    Matrix matrix1 = generateMatrix(rows, cols);
    Matrix matrix2 = generateMatrix(rows, cols);

    Matrix sumMatrix = addMatrices(matrix1, matrix2, rows, cols);

    printMatrix(matrix1);
    printMatrix(matrix2);
    printMatrix(sumMatrix);

    return 0;
}