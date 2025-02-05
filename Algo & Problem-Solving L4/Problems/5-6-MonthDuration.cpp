#include "Utility.h"
#include <iostream>

int getHoursInMonth(int year, short month) { return Utility::getDaysInMonth(year, month) * 24; }

int getMinutesInMonth(int year, short month) { return getHoursInMonth(year, month) * 60; }

int getSecondsInMonth(int year, short month) { return getMinutesInMonth(year, month) * 60; }

void printMonthDuration(int year, short month) {
    std::cout << "Month " << month << " in year " << year << " has:" << std::endl;
    std::cout << Utility::getDaysInMonth(year, month) << " days" << std::endl;
    std::cout << getHoursInMonth(year, month) << " hours" << std::endl;
    std::cout << getMinutesInMonth(year, month) << " minutes" << std::endl;
    std::cout << getSecondsInMonth(year, month) << " seconds" << std::endl;
}

int main() {
    int Year = Utility::readYear();
    short Month = Utility::readMonth();
    printMonthDuration(Year, Month);
    return 0;
}
