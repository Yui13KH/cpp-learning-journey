#include <iostream>
#include <cmath>

double getValidUserInput() {
    double number = 0.0;
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

double customSqrt(double number) { return std::pow(number, 0.5); }

void calculateAndPrintSquareRoot(double number) {
    double customResult = customSqrt(number);
    double builtInResult = std::sqrt(number);

    std::cout << "Custom square root of " << number << " is " << customResult << std::endl;
    std::cout << "Built-in square root of " << number << " is " << builtInResult << std::endl;
}

int main() {
    double number = getValidUserInput();
    calculateAndPrintSquareRoot(number);

    return 0;
}
