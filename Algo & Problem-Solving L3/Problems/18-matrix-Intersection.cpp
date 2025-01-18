#include "Utility.h"
#include <unordered_set>

std::vector<int> intersectionOfMatrices(Matrix matrix1, Matrix matrix2, int rows, int cols) {
    std::unordered_set<int> set;
    std::vector<int> intersection;
    
    // Add all elements from matrix1 to the set
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            set.insert(matrix1[i][j]);
        }
    }

    // Check if any element in matrix2 exists in the set
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (set.find(matrix2[i][j]) != set.end()) {
                intersection.push_back(matrix2[i][j]);
                set.erase(matrix2[i][j]);  // Optional: to avoid duplicates
            }
        }
    }

    return intersection;
} // using unordered_set rather than vector

void printIntersection(Matrix matrix1, Matrix matrix2, int rows, int cols) {
    std::vector<int> intersection = intersectionOfMatrices(matrix1, matrix2, rows, cols);
    std::cout << "Intersection: [ ";
    for (int i = 0; i < intersection.size(); i++) {
        std::cout << intersection[i] << " ,";
    }
    std::cout << "]" << std::endl;
}

int main() {
    srand(unsigned(time(NULL)));
    int matrixRows = utility::getValidPositiveInt("Enter matrix rows: ");
    int matrixColumns = utility::getValidPositiveInt("Enter matrix cols: ");

    Matrix matrix1 = utility::generateRandomMatrix(matrixRows, matrixColumns, 1, 100);
    Matrix matrix2 = utility::generateRandomMatrix(matrixRows, matrixColumns, 1, 100);

    utility::PrintMatrix(matrix1, matrixRows, matrixColumns);
    std::cout << "\n" << "------" << "\n";
    utility::PrintMatrix(matrix2, matrixRows, matrixColumns);

    printIntersection(matrix1, matrix2, matrixRows, matrixColumns);

    return 0;
}

// command to compiler : g++ 18-matrix-Intersection.cpp Utility.cpp -o name