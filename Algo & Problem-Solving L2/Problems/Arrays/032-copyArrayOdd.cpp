#include <iostream>
#include <cstdlib>

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

void CopyOddNumbersFromUserInput(int array1[100], int array1Length, int array2[100],
                                 int& array2Length) {
    array2Length = 0;  // Reset the second array length
    int i = 0;
    do {
        if (array1[i] % 2 != 0) {
            AddElementToArray(array1[i], array2, array2Length);
        }
        i++;
    } while (i < array1Length);
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

    std::cout << "Enter the length of the array: ";
    int userInput = ReadValidNumber();

    PopulateArrayWithRandomNumbers(array1, array1Length, userInput);

    CopyOddNumbersFromUserInput(array1, array1Length, array2, array2Length);

    printArray("The length of the original array is: " + std::to_string(array1Length) +
                   "\nElements of array1: ",
               array1, array1Length);

    printArray("The length of the copied array is: " + std::to_string(array2Length) +
                   "\nElements of array2: ",
               array2, array2Length);

    return 0;
}
