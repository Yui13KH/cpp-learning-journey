#include "Utility.h"
// doing this to simplify the code and not rewrite the same code again and again

namespace Utility {

int getValidPositiveInt(const std::string& prompt) {
    int input;
    std::string line;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        if (iss >> input && input > 0 && iss.eof()) {
            return input;
        }

        std::cout << "Please enter a valid positive integer: ";
    }
}

// Function to prompt user for a valid string input
std::string getValidString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) {
            return input;
        }
        std::cout << "Please enter a valid string: ";
    }
}

bool isLeapYear(int year) { return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0); }

// Reads an integer from standard input using the provided prompt and validator.
// The default validator accepts any integer.
int readInt(const std::string& prompt, std::function<bool(int)> validator) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (!std::cin.fail() && validator(value)) {
            break;
        }
        std::cout << "Invalid input, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// Returns the number of days in a given month and year.
int getDaysInMonth(int year, int month) {
    if (month < 1 || month > 12) {
        return 0;  // or throw an exception, depending on your design
    }
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month];
}

// Validates that the year is greater than 0.
bool validYear(int year) { return year > 0; }

// Validates that the month is in the range [1, 12].
bool validMonth(int month) { return month >= 1 && month <= 12; }

// Calculates the day of the week for a given date.
// Returns 0 for Sunday, 1 for Monday, etc.
int getDayOfTheWeek(int year, int month, int day) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

// Reads a day value for a given month and year using a prompt.
short readDay(const std::string& prompt, int year, short month) {
    return readInt(
        prompt, [year, month](int day) { return day >= 1 && day <= getDaysInMonth(year, month); });
}

// Reads a valid month from input.
short readMonth(const std::string& prompt) {
    return readInt(prompt, [](int month) { return month >= 1 && month <= 12; });
}

// Reads a valid year from input.
int readYear(const std::string& prompt) {
    return readInt(prompt, [](int year) { return year > 0; });
}

// If you have additional functions like readShort, you could implement them similarly,
// or simply use readInt if a smaller type is not necessary.
}  // namespace Utility

// namespace utility
