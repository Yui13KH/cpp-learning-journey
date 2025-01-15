#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

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

void printMiddle(const Matrix& matrix, int rows, int cols) {
    int middleRowIndex = ceil(rows / 2.0) - 1;
    int middleColIndex = ceil(cols / 2.0) - 1;
    // assuming rows and cols are odd numbers cause there is no middle in even numbers
    std::cout << "Middle Columns: " << std::endl;
    for (int i = 0; i < rows; i++) {
        std::cout << matrix[i][middleColIndex] << " ";
    }
    std::cout << std::endl;
    std::cout << "Middle Rows: " << std::endl;
    for (int i = 0; i < cols; i++) {
        std::cout << matrix[middleRowIndex][i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int rows = getValidPositiveInt("Enter the number of rows: ");
    int cols = getValidPositiveInt("Enter the number of columns: ");

    Matrix matrix = generateMatrix(rows, cols);

    printMatrix(matrix);
    printMiddle(matrix, rows, cols);

    return 0;
}