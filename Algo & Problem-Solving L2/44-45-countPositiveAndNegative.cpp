#include <iostream>
#include <cstdlib>

int ReadValidPositiveNumber() {
    int number = 0;
    bool validInput;
    do {
        std::cout << "Enter a number: ";
        std::cin >> number;

        validInput = !std::cin.fail() && number > 0;
        if (!validInput) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            if (number <= 0) {
                std::cout << "Invalid input. Please enter a positive number.\n";
            } else {
                std::cout << "Invalid input. Please enter a valid integer.\n";
            }
        } else {
            std::cin.ignore(1000, '\n');
        }

    } while (!validInput);
    return number;
}

int RandomNumberInRange(int min, int max) { return rand() % (max - min + 1) + min; }

void RandomizeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = RandomNumberInRange(-100, 100);
    }
}

int positiveNumberCounter(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}

int negativeNumberCounter(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }
    return count;
}

void printArrayElements(int arr[], int size) {
    std::cout << "Elements of array are: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}

void printResults(int positiveCount, int negativeCount) {
    std::cout << "Number of positive numbers: " << positiveCount << std::endl;
    std::cout << "Number of negative numbers: " << negativeCount << std::endl;
}

int main() {
    std::srand(unsigned(time(NULL)));

    int arr[100];
    int size = ReadValidPositiveNumber();

    RandomizeArray(arr, size);

    int positiveCount = positiveNumberCounter(arr, size);
    int negativeCount = negativeNumberCounter(arr, size);

    printArrayElements(arr, size);
    printResults(positiveCount, negativeCount);

    return 0;
}