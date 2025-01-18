#include "Utility.h"

int countOccurrencesInMatrix(int targetNumber, const Matrix& matrixData, int matrixColumns, int matrixRows) {
    int occurrenceCounter = 0;
    for (int row = 0; row < matrixRows; row++) {
        for (int column = 0; column < matrixColumns; column++) {
            if (matrixData[row][column] == targetNumber) {
                occurrenceCounter++;
            }
        }
    }
    return occurrenceCounter;
}

int main() {
    int matrixRows = utility::getValidPositiveInt("Enter matrix rows: ");
    int matrixColumns = utility::getValidPositiveInt("Enter matrix cols: ");
    int targetNumber = utility::getValidPositiveInt("Enter number to count: ");

    Matrix matrixData = {{1, 2, 3}, {3, 2, 3}, {1, 2, 3}};

    utility::PrintMatrix(matrixData);

    std::cout << "Number of occurrences: " << countOccurrencesInMatrix(targetNumber, matrixData, matrixColumns, matrixRows) << std::endl;

    return 0;
}

// command to compiler : g++ 14-MatrixOccurrenceCounter.cpp Utility.cpp -o name