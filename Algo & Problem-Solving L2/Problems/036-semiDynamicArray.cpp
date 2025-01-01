#include <iostream>

int ReadInputInRange(int min, int max, std::string message) {
    int number = 0;
    do {
        std::cout << message << std::endl;
        std::cin >> number;
    } while (number < min || number > max);
    return number;
}

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
    arrayLength++;
    array[arrayLength - 1] = number;
}

void InputUserNumbersInArray(int array[100], int& arrayLength) {
    bool AddMore = true;

    do {
        AddElementToArray(ReadValidNumber(), array, arrayLength);
        std::cout << "\nWant to add more yes[1],no[0]: ";
        std::cin >> AddMore;
    } while (AddMore);
}

void PrintArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    int array[100], arraylength = 0;
    InputUserNumbersInArray(array, arraylength);
    std::cout << "\nArray Length: " << arraylength << std::endl;
    std::cout << "Array elements: ";
    PrintArray(array, arraylength);

    return 0;
}