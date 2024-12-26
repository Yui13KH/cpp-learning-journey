#include <iostream>
#include <cstdlib>

int ReadValidNumber(std::string prompt) {
    int number = 0;
    bool validInput;
    do {
        std::cout << prompt;
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

void printArrayElements(int array[], int arrayLength) {
    std::cout << "Array Elements: ";
    for (int i = 0; i < arrayLength; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void fillArrayWithUserInput(int array[], int& counter, int maxSize) {
    bool addMore = true;
    while (addMore && counter < maxSize) {
        array[counter++] = ReadValidNumber("Enter a number: ");
        std::cout << "Do you want to add another number? yes(1) or no(0): ";
        std::cin >> addMore;
    }
}

int main() {
    int array[100];
    int counter = 0;

    fillArrayWithUserInput(array, counter, 100);
    printArrayElements(array, counter);

    return 0;
}

