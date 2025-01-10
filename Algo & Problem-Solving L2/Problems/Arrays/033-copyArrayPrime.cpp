#include <iostream>
#include <cstdlib>
#include <cmath>

int RandomNumberInRange(int min, int max) { return rand() % (max - min + 1) + min; }

int ReadValidNumber() {
    int number = 0;
    bool validInput;
    do {
        std::cout << "Enter a number: ";
        std::cin >> number;

        validInput = !std::cin.fail();
        if (!validInput) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a valid integer.\n";
        } else {
            std::cin.ignore(1000, '\n');
        }

    } while (!validInput);
    return number;
}

void AddElementToArray(int number, int array[100], int& arrayLength) {
    array[arrayLength] = number;
    arrayLength++;
}

void PopulateArrayWithRandomNumbers(int array[100], int& arrayLength, int userSpecifiedLength) {
    arrayLength = 0;  // Reset the array length
    for (int i = 0; i < userSpecifiedLength; i++) {
        int randomNumber = RandomNumberInRange(1, 100);
        AddElementToArray(randomNumber, array, arrayLength);
    }
}

bool checkPrime(int number) {
    if (number < 2) return false;
    if (number == 2) return true;       // 2 is the only even prime
    if (number % 2 == 0) return false;  // Eliminate even numbers

    int limit = sqrt(number);              // Calculate square root once
    for (int i = 3; i <= limit; i += 2) {  // Check only odd numbers
        if (number % i == 0) return false;
    }
    return true;
}

void CopyPrimes(int array1[100], int array1Length, int array2[100], int& array2Length) {
    array2Length = 0;  // Reset the second array length
    for (int i = 0; i < array1Length; i++) {
        if (checkPrime(array1[i])) {
            AddElementToArray(array1[i], array2, array2Length);
        }
    }
}

void printArray(const std::string& message, const int array[], int arrayLength) {
    std::cout << message;
    for (int i = 0; i < arrayLength; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::srand(unsigned(time(NULL)));

    int array1[100];
    int array2[100];
    int array1Length = 0;
    int array2Length = 0;

    PopulateArrayWithRandomNumbers(array1, array1Length, ReadValidNumber());

    CopyPrimes(array1, array1Length, array2, array2Length);

    std::cout << "Original numbers length: " << array1Length << std::endl;
    printArray("Original numbers: ", array1, array1Length);

    std::cout << "Prime numbers length: " << array2Length << std::endl;
    printArray("Prime numbers: ", array2, array2Length);
    return 0;
}