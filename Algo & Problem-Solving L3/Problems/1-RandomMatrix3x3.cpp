#include <iostream>
#include <cstdlib>
#include <iomanip>  // for setw for better formatting
#include <vector>

int RandomNumberInRange(int min, int max) { return rand() % (max - min + 1) + min; }

int getValidPositiveInt(const std::string& prompt) {
    int input;
    std::cout << prompt;
    while (!(std::cin >> input) || input <= 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');  // Ignore up to 1000 characters
        std::cout << "Please enter a valid positive integer: ";
    }
    return input;
}

std::vector<std::vector<int>> generateMatrix(int rows, int cols) {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));  // Initialize 2D vector

    for (short i = 0; i < rows; ++i) {
        for (short j = 0; j < cols; ++j) {
            matrix[i][j] = RandomNumberInRange(1, 100);  // Fill with random numbers
        }
    }
    return matrix;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << std::setw(3) << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(unsigned(time(NULL)));

    int rows = getValidPositiveInt("Enter the number of rows: ");
    int cols = getValidPositiveInt("Enter the number of columns: ");

    std::vector<std::vector<int>> matrix = generateMatrix(rows, cols);
    printMatrix(matrix);

    return 0;
}