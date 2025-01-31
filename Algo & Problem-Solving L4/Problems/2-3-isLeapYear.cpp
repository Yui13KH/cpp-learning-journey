#include "Utility.h"

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void printIsLeapYear(int year) {
    std::cout << year << " is " << (isLeapYear(year) ? "a" : "not a") << " leap year" << std::endl;
}

int main() {
    int year = utility::getValidPositiveInt("Enter Year: ");
    printIsLeapYear(year);
    return 0;
}
