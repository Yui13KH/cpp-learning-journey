#include "Utility.h"
#include <iostream>
#include <iomanip>
#include <string>

short FirstDayTillDate(int year, short month, short day) {
    short days = 0;
    for (short i = 1; i < month; ++i) {
        days += Utility::getDaysInMonth(year, i);
    }
    return days + day;
}

void printDaysTillDate(int year, short month, short day) {
    short days = FirstDayTillDate(year, month, day);
    std::cout << "Days till date: " << days << std::endl;
    std::cout << "Hours till date: " << days * 24 << std::endl;
    std::cout << "Minutes till date: " << days * 24 * 60 << std::endl;
    std::cout << "Seconds till date: " << days * 24 * 60 * 60 << std::endl;
}

int main() {
    int year = Utility::readYear();
    short month = Utility::readMonth();
    printDaysTillDate(year, month, Utility::readDay("Enter day: ", year, month));
    return 0;
}
