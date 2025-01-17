#include "Utility.h"

struct Count {
    int zeros;
    int nonZeros;
};

Count countOccurrencesInMatrix(const Matrix& matrixData, int matrixColumns, int matrixRows) {
    Count results = {0, 0};
    for (int row = 0; row < matrixRows; row++) {
        for (int column = 0; column < matrixColumns; column++) {
            if (matrixData[row][column] == 0) {
                results.zeros++;
            } else {
                results.nonZeros++;
            }
        }
    }
    return results;
}

void printIsParse(Count results) {
    if (results.zeros > results.nonZeros) {
        std::cout << "Matrix is sparse." << std::endl;
    } else if (results.nonZeros > results.zeros){
        std::cout << "Matrix is NOT sparse" << std::endl;
    } else {
        std::cout << "zeros and non-zeros are equal" << std::endl; // for even arrays edge case
    }
}

int main() {
    srand(unsigned(time(NULL)));
    int matrixRows = utility::getValidPositiveInt("Enter matrix rows: ");
    int matrixColumns = utility::getValidPositiveInt("Enter matrix cols: ");

    Matrix matrix = utility::generateRandomMatrix(matrixRows, matrixColumns, 0, 1);

    utility::PrintMatrix(matrix, matrixRows, matrixColumns);
    Count results = countOccurrencesInMatrix(matrix, matrixColumns, matrixRows);

    printIsParse(results);

    return 0;
}

// command to compiler : g++ 16-isMatrixSparse.cpp Utility.cpp -o name