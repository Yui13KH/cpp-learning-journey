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

int SumMatrix(const Matrix& matrix, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
    }
    return sum;
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
    int rows = getValidPositiveInt("Enter the number of rows: ");
    int cols = getValidPositiveInt("Enter the number of columns: ");

    Matrix matrix = generateRandomMatrix(rows, cols);

    PrintMatrix(matrix, rows, cols);

    int sum = SumMatrix(matrix, rows, cols);
    std::cout << "Sum of the matrix: " << sum << std::endl;

    return 0;
}