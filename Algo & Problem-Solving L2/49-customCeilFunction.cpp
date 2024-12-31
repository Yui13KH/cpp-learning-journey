#include <iostream>
#include <cmath>

float ReadValidNumber() {
    float number = 0.0;
    bool validInput;
    do {
        std::cout << "Enter a number: ";
        std::cin >> number;

        validInput = !std::cin.fail();
        if (!validInput) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a valid floating point number.\n";
        } else {
            std::cin.ignore(1000, '\n');
        }

    } while (!validInput);
    return number;
}

int customCeil(float num) {
    if (num >= 0) {
        return (int)num + 1;  // Add 1 for positive numbers to round up
    } else {
        return (int)num;  // Return integer part for negative numbers
    }
}

int main() {
    float number = ReadValidNumber();
    std::cout << "Custom ceil of " << number << " is " << customCeil(number) << std::endl;
    std::cout << "C++ ceil of " << number << " is " << std::ceil(number) << std::endl;

    return 0;
}


