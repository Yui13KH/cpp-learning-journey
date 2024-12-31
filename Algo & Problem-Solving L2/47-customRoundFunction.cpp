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

int customRound(float num) {
    int integerPart = (int)num; // Extract integer part using simple cast
    float fractionalPart = num - integerPart; // Calculate fractional part

    if (fractionalPart >= 0.5) {
        return integerPart + 1; // Round up
    } else {
        return integerPart; // Round down , which is just the same integer part
    }
} // simple math based solution ,_, 


int main() {
    float number = ReadValidNumber(); 
    std::cout << "Custom rounded number: " << customRound(number) << std::endl;
    std::cout << "C++ rounded number: " << std::round(number) << std::endl;
    return 0;
}
