#include <iostream>
#include <cstdlib>
#include <iomanip>  // For setw (better formatting)
#include <vector>
#include <string>

// Utility Functions
int RandomNumberInRange(int min, int max) { 
    return rand() % (max - min + 1) + min; 
}

int getValidPositiveInt(const std::string& prompt) {
    int input;
    std::cout << prompt;
    while (!(std::cin >> input) || input <= 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');  // Ignore invalid input
        std::cout << "Please enter a valid positive integer: ";
    }
    return input;
}

// Core Matrix Operations
std::vector<std::vector<int>> generateMatrix(int rows, int cols) { // the function of it same type
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols)); // a vector of vectors that stores int values
    for (short i = 0; i < rows; ++i) {
        for (short j = 0; j < cols; ++j) {
            matrix[i][j] = RandomNumberInRange(1, 100);
        }
    }
    return matrix;
}

int calculateRowSum(const std::vector<std::vector<int>>& matrix, int rowIndex, int cols) {
    int sum = 0;
    for (int col = 0; col < cols; col++) {
        sum += matrix[rowIndex][col];
    }
    return sum;
}

std::vector<int> computeRowSums(const std::vector<std::vector<int>>& matrix) {
    std::vector<int> rowSums;
    for (size_t row = 0; row < matrix.size(); ++row) { // gets outer row size with .size
        int cols = matrix[row].size(); // gets inner columns size like [row][column]
        rowSums.push_back(calculateRowSum(matrix, row, cols));
    }
    return rowSums;
}

// Printing Functions
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    std::cout << "\nGenerated Matrix:\n";
    for (const auto& row : matrix) {
        for (int column : row) {
            std::cout << std::setw(3) << column << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printRowSums(const std::vector <int> rowSums) {
    std::cout << "Sum of each row:\n";
    for (size_t i = 0; i < rowSums.size(); ++i) {
        std::cout << "Row " << i + 1 << ": " << rowSums[i] << std::endl;
    }
    std::cout << std::endl;
}

// Main Function
int main() {
    srand(unsigned(time(NULL))); 

    int rows = getValidPositiveInt("Enter the number of rows: ");
    int cols = getValidPositiveInt("Enter the number of columns: ");

    std::vector<std::vector<int>> matrix = generateMatrix(rows, cols);
    std::vector<int> rowSums = computeRowSums(matrix);

    printMatrix(matrix);
    printRowSums(rowSums);

    return 0;
}
