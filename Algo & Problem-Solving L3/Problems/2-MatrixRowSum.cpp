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
            matrix[i][j] = RandomNumberInRange(1, 100);
        }
    }
    return matrix;
}

int calculateRowSum(const std::vector<std::vector<int>>& matrix, int rowIndex, int cols) {
    int sum = 0;  // empty variable for summing the cols values
    for (int col = 0; col < cols; col++) {
        sum += matrix[rowIndex][col];  // adds the collumns of the row were on
    }
    return sum;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    std::cout << std::endl;
    for (const auto& row : matrix) {  // Iterates through each row in the matrix
        for (int column : row) {      // Iterates through each element (column) in the row
            std::cout << std::setw(3) << column << " ";  // Print the number
        }
        std::cout << std::endl;  // Print a newline after printing all elements in the row
    }
    std::cout << std::endl;
}

void printRowSums(const std::vector<std::vector<int>>& matrix, int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        std::cout << "Row " << i + 1 << " sum: " << calculateRowSum(matrix, i, cols) << std::endl;
    }
}

int main() {
    srand(unsigned(time(NULL)));

    int rows = getValidPositiveInt("Enter the number of rows: ");
    int cols = getValidPositiveInt("Enter the number of columns: ");

    std::vector<std::vector<int>> matrix = generateMatrix(rows, cols);

    printMatrix(matrix);
    printRowSums(matrix, cols, rows);

    return 0;
}