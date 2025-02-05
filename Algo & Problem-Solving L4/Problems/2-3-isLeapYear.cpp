#include "Utility.h"

void printIsLeapYear(int year) {
    std::cout << year << " is " << (Utility::isLeapYear(year) ? "a" : "not a") << " leap year"
              << std::endl;
}

int main() {
    int year = Utility::getValidPositiveInt("Enter Year: ");
    printIsLeapYear(year);
    return 0;
}
