#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>  // For rand()

// Define a type alias for Matrix (a 2D vector of integers)
using Matrix = std::vector<std::vector<int>>;

// Declare the utility namespace
namespace utility {

// Function declarations
int RandomNumberInRange(int min, int max);
Matrix generateRandomMatrix(int rows, int cols, int min, int max);
void PrintMatrix(const Matrix& matrix);
int getValidPositiveInt(const std::string& prompt);
std::string getValidString(const std::string& prompt);

}  // namespace utility
