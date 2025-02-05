#include "Utility.h"
#include <iostream>

short getDaysInYear(int year) {
    return (Utility::isLeapYear(year)) ? 366 : 365;  // Return 366 for leap years, 365 otherwise
}

short getHoursInYear(int year) {
    return getDaysInYear(year) * 24;  // Hours = days * 24
}

short getMinutesInYear(int year) {
    return getHoursInYear(year) * 60;  // Minutes = hours * 60
}

short getSecondsInYear(int year) {
    return getMinutesInYear(year) * 60;  // Seconds = minutes * 60
}

void printYearDuration(int year) {
    std::cout << "Year " << year << " has:" << std::endl;
    std::cout << getDaysInYear(year) << " days" << std::endl;
    std::cout << getHoursInYear(year) << " hours" << std::endl;
    std::cout << getMinutesInYear(year) << " minutes" << std::endl;
    std::cout << getSecondsInYear(year) << " seconds" << std::endl;
}

int main() {
    int Year = Utility::readYear();
    printYearDuration(Year);
    return 0;
}
