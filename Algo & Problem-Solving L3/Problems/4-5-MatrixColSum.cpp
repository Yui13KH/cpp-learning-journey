#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>

using Matrix = std::vector<std::vector<int>>;  // Alias for matrix type, simplifying code

// Utility functions
int getValidPositiveInt(const std::string& prompt) {
    int input;
    do {
        std::cout << prompt;
        std::cin >> input;

        if (std::cin.fail() || input <= 0) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Please enter a valid positive integer: ";
        }
    } while (std::cin.fail() || input <= 0);
    return input;
}

int RandomNumberInRange(int min, int max) { return min + rand() % (max - min + 1); }

// Matrix operations
Matrix generateMatrix(int rows, int cols) {
    Matrix matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = RandomNumberInRange(1, 100);
        }
    }
    return matrix;
}

int calculateColSum(const Matrix& matrix, int colIndex, int numRows) {
    int sum = 0;
    for (int row = 0; row < numRows; ++row) {
        sum += matrix[row][colIndex];  // Sum values in the column across all rows
    }
    return sum;
}

std::vector<int> computeColumnSums(const Matrix& matrix) {
    std::vector<int> columnSums;
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    for (int col = 0; col < numCols; ++col) {
        columnSums.push_back(calculateColSum(matrix, col, numRows));  // Get sum of each column
    }

    return columnSums;
}

// Printing functions
void printMatrix(const Matrix& matrix) {
    std::cout << "\nGenerated Matrix:\n";
    for (const auto& row : matrix) {
        for (int column : row) {
            std::cout << std::setw(3) << column << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printColSums(const std::vector<int>& columnSums) {
    std::cout << "Sum of each column:\n";
    for (size_t i = 0; i < columnSums.size(); ++i) {
        std::cout << "Column " << i + 1 << ": " << columnSums[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    srand(unsigned(time(NULL)));

    int rows = getValidPositiveInt("Enter the number of rows: ");
    int cols = getValidPositiveInt("Enter the number of columns: ");

    Matrix matrix = generateMatrix(rows, cols);
    std::vector<int> columnSums = computeColumnSums(matrix);

    printMatrix(matrix);
    printColSums(columnSums);

    return 0;
}
