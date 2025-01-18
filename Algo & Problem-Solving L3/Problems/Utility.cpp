#include "Utility.h"
// doing this to simplify the code and not rewrite the same code again and again
namespace utility {

// Function to generate a random number in a given range [min, max]
int RandomNumberInRange(int min, int max) { return rand() % (max - min + 1) + min; }

// Function to generate a random matrix of size rows x cols
Matrix generateRandomMatrix(int rows, int cols, int min, int max) {
    Matrix matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = RandomNumberInRange(min, max);
        }
    }
    return matrix;
}

// Function to print the matrix in a formatted manner
void PrintMatrix(const Matrix& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to prompt user for a valid positive integer input
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

}  // namespace utility
