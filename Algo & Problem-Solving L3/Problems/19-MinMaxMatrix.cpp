#include "Utility.h"

std::vector<int> flattenMatrix(Matrix& matrix) {
    std::vector<int> flattenedMatrix;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            flattenedMatrix.push_back(matrix[i][j]);
        }
    }
    return flattenedMatrix;
}

std::pair<int, int> findMinMax(std::vector<int>& flattenedMatrix) {
    int min = flattenedMatrix[0];
    int max = flattenedMatrix[0];

    for (int i = 0; i < flattenedMatrix.size(); i++) {
        if (flattenedMatrix[i] < min) {
            min = flattenedMatrix[i];
        }
        if (flattenedMatrix[i] > max) {
            max = flattenedMatrix[i];
        }
    }
    return std::make_pair(min, max);
}

int main() {
    srand(unsigned(time(NULL)));
    int matrixRows = utility::getValidPositiveInt("Enter matrix rows: ");
    int matrixColumns = utility::getValidPositiveInt("Enter matrix cols: ");

    Matrix matrix = utility::generateRandomMatrix(matrixRows, matrixColumns, 1, 100);

    utility::PrintMatrix(matrix);

    std::vector<int> flattenedMatrix = flattenMatrix(matrix);

    std::pair<int, int> minMaxPair = findMinMax(flattenedMatrix);
    std::cout << "Min: " << minMaxPair.first << std::endl;
    std::cout << "Max: " << minMaxPair.second << std::endl;

    return 0;
}

// command to compiler : g++ 19-MinMaxMatrix.cpp Utility.cpp -o name