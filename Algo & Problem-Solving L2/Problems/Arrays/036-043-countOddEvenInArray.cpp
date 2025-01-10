#include <iostream>
#include <cstdlib>

int RandomNumberInRange(int min, int max) { return rand() % (max - min + 1) + min; }

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

void RandomizeArray(int array[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        array[i] = RandomNumberInRange(1, 100);
    }
}

int countEvenNumbers(int array[], int arrayLength) {
    int count = 0;
    for (int i = 0; i < arrayLength; i++) {
        if (array[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int countOddNumbers(int array[], int arrayLength) {
    int count = 0;
    for (int i = 0; i < arrayLength; i++) {
        if (array[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

void PrintResults(int array[], int arrayLength) {
    std::cout << "Array: ";
    for (int i = 0; i < arrayLength; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << "\nEven numbers: " << countEvenNumbers(array, arrayLength) << "\nOdd numbers: " << countOddNumbers(array, arrayLength) << std::endl;
}

int main(){
    srand((unsigned)time(NULL));
    int array[100];
    int arrayLength = ReadValidPositiveNumber();
    RandomizeArray(array, arrayLength);
    PrintResults(array, arrayLength);
    return 0;
}
