#include <iostream>
#include <cmath>

// ANSI color codes
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";

// Function to read a valid integer

// Function to read a valid floating-point number
float ReadValidFloat() {
    float number = 0.0;
    bool validInput;
    do {
        std::cout << "Enter a number: ";
        std::cin >> number;

        validInput = !std::cin.fail();
        if (!validInput) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter a valid floating-point number.\n";
        } else {
            std::cin.ignore(1000, '\n');
        }

    } while (!validInput);
    return number;
}

// Custom Absolute Function
int customAbsolute(int number) {
    if (number < 0) {
        return -number;
    } else {
        return number;
    }
}

// Custom Round Function
int customRound(float num) {
    int integerPart = (int)num;
    float fractionalPart = num - integerPart;
    if (fractionalPart >= 0.5) {
        return integerPart + 1;
    } else {
        return integerPart;
    }
}

// Custom Floor Function
int customFloor(float num) {
    if (num >= 0) {
        return (int)num;
    } else {
        return (int)num - 1;
    }
}

// Custom Ceil Function
int customCeil(float num) {
    if (num == (int)num) {
        return num;
    } else if (num > 0) {
        return (int)num + 1;
    } else {
        return (int)num;
    }
}

// Custom Square Root Function
double customSqrt(double number) {
    if (number < 0) {
        std::cout << "Square root of negative numbers is not defined in real numbers.\n";
        return -1;
    }
    return std::pow(number, 0.5);  // Simpler implementation
}

// Menu Function
void displayMenu() {
    std::cout << BOLD << "\nCustom Functions Menu:\n" << RESET;
    std::cout << GREEN << "1. Absolute Value\n";
    std::cout << YELLOW << "2. Round Number\n";
    std::cout << BLUE << "3. Floor Number\n";
    std::cout << MAGENTA << "4. Ceil Number\n";
    std::cout << CYAN << "5. Square Root\n";
    std::cout << RED << "0. Exit\n" << RESET;
    std::cout << BOLD << "Choose an option: " << RESET;
}

void processMenuChoice(int choice) {
    switch (choice) {
        case 1: {
            int number = ReadValidFloat();
            std::cout << YELLOW << "Custom Absolute Value: " << GREEN << customAbsolute(number) << RESET << std::endl;
            std::cout << YELLOW << "Built-in Absolute Value: " << GREEN << std::abs(number) << RESET << std::endl;
            break;
        }
        case 2: {
            float number = ReadValidFloat();
            std::cout << YELLOW << "Custom Rounded Value: " << GREEN << customRound(number) << RESET << std::endl;
            std::cout << YELLOW << "Built-in Rounded Value: " << GREEN << std::round(number) << RESET << std::endl;
            break;
        }
        case 3: {
            float number = ReadValidFloat();
            std::cout << YELLOW << "Custom Floor Value: " << GREEN << customFloor(number) << RESET << std::endl;
            std::cout << YELLOW << "Built-in Floor Value: " << GREEN << std::floor(number) << RESET << std::endl;
            break;
        }
        case 4: {
            float number = ReadValidFloat();
            std::cout << YELLOW << "Custom Ceil Value: " << GREEN << customCeil(number) << RESET << std::endl;
            std::cout << YELLOW << "Built-in Ceil Value: " << GREEN << std::ceil(number) << RESET << std::endl;
            break;
        }
        case 5: {
            double number = ReadValidFloat();
            double customResult = customSqrt(number);
            double builtInResult = std::sqrt(number);
            if (customResult != -1) {
                std::cout << YELLOW << "Custom Square Root: " << GREEN << customResult << RESET << std::endl;
                std::cout << YELLOW << "Built-in Square Root: " << GREEN << builtInResult << RESET << std::endl;
            }
            break;
        }
        case 0:
            break;
        default:
            std::cout << RED << "Invalid choice. Please try again.\n" << RESET;
    }
}

// Main Function
int main() {
    int choice;
    do {
        displayMenu();
        std::cin >> choice;
        processMenuChoice(choice);
    } while (choice != 0);
    std::cout << "Goodbye!\n";
    return 0;
}