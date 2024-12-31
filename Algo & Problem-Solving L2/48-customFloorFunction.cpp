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

int customFloor(float num) {
    if (num >= 0) {
        return (int)num;  // Return integer part for positive numbers
    } else {
        return (int)num - 1;  // Subtract 1 for negative numbers to round down
    }
}

int main() {
    float number = ReadValidNumber();
    std::cout << "Custom floor of " << number << " is " << customFloor(number) << std::endl;
    std::cout << "C++ floor of " << number << " is " << std::floor(number) << std::endl;

    return 0;
}
