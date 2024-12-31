#include <iostream>
#include <cstdlib>

int RandomNumber(int from, int to) { return std::rand() % (to - from + 1) + from; }

int ReadInputInRange(int min, int max, std::string message) {
    int number = 0;
    do {
        std::cout << message;
        std::cin >> number;
        if (number < min || number > max) {
            std::cout << "Please enter a number between " << min << " and " << max << ".\n";
        }
    } while (number < min || number > max);
    return number;
}

void AddElementToArray(int number, int array[100], int& arrayLength) {
    arrayLength++;
    array[arrayLength - 1] = number;
}

void SimulateUserInputToArray(int array[100], int& arrayLength, int specifiedLength, int minValue,
                              int maxValue) {
    for (int i = 0; i < specifiedLength; i++) {
        int simulatedInput = RandomNumber(minValue, maxValue);
        AddElementToArray(simulatedInput, array, arrayLength);
    }
}

void SimulateCopyingArray(int source[100], int& sourceLength, int destination[100],
                          int& destinationLength) {
    destinationLength = 0;
    int i = 0;
    do {
        AddElementToArray(source[i], destination, destinationLength);
        i++;
    } while (i < sourceLength);
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::srand(unsigned(time(NULL)));

    int array1[100], array2[100];
    int arrayLength1 = 0, arrayLength2 = 0;

    int userSpecifiedLength = ReadInputInRange(1, 100, "Enter the length of the array (1-100): ");

    SimulateUserInputToArray(array1, arrayLength1, userSpecifiedLength, 1, 100);

    std::cout << "Original Array (array1):" << std::endl;
    PrintArray(array1, arrayLength1);
    SimulateCopyingArray(array1, arrayLength1, array2, arrayLength2);

    std::cout << "Copied Array (array2):" << std::endl;
    PrintArray(array2, arrayLength2);

    return 0;
}
