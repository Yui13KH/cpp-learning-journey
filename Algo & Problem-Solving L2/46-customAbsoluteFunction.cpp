#include <iostream>
#include <cmath>

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

int absoluteValue(int number) {
    if (number < 0) {
        return -number;  // similar to number = number * -1;
    } else {
        return number;
    }
}

int main() {
    int number = ReadValidNumber();
    std::cout << "custom absolute value of " << number << " is " << absoluteValue(number) << std::endl;
    std::cout << "c++ absolute value of " << number << " is " << std::abs(number) << std::endl;
    return 0;
}
