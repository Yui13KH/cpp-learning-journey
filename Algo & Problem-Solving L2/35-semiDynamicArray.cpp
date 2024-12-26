#include <iostream>
#include <cstdlib>

int RandomNumber(int from, int to) {
    int random = std::rand() % (to - from + 1) + from;
    return random;
}

int ReadInputInRange(int min, int max, std::string message) {
    int number = 0;
    do {
        std::cout << message << std::endl;
        std::cin >> number;
    } while (number < min || number > max);
    return number;
}

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

void semiArrayFilling(int array[100], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        std::cout << "Enter Element[" << i + 1 << "]" << std::endl;
        array[i] = ReadValidNumber("Enter a number: ");
    }
}

void printArrayElements(int array[100], int arrayLength) {
    std::cout << "Array Elements ";
    for (int i = 0; i < arrayLength; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::srand(unsigned(time(NULL)));
    int array[100], arraylength;
    arraylength = ReadInputInRange(1, 100, "Enter size of array [1,100]: ");
    semiArrayFilling(array, arraylength);
    printArrayElements(array, arraylength);

    return 0;

    // idk for now i am bored and outside this works , probably removing the arrayLength , keep running and ask for user input every itteration 
}