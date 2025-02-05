#include "Utility.h"
#include <iostream>
#include <string>
#include <sstream>
#include <functional>

short daysInMonth(int year, short month) {
    static const short monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2 && Utility::isLeapYear(year)) ? 29 : monthDays[month];
}
short DateToOrdinalDay(int year, short month, short day) {
    short dayCount = day;
    for (short m = 1; m < month; m++) {
        dayCount += daysInMonth(year, m);
    }
    return dayCount;
}

std::string convertOrdinalToDate(int year, short ordinalDay) {
    short month = 1;
    while (ordinalDay > daysInMonth(year, month)) {
        ordinalDay -= daysInMonth(year, month);
        month++;
    }

    std::ostringstream oss;
    oss << (month < 10 ? "0" : "") << month << "/" << (ordinalDay < 10 ? "0" : "") << ordinalDay
        << "/" << year;
    return oss.str();  // simple improvement in printing for numbers less then 10,
}

void printOrdinalAndDate(int year, short month, short day) {
    short ordinal = DateToOrdinalDay(year, month, day);
    std::cout << "\nFor " << (month < 10 ? "0" : "") << month << "/" << (day < 10 ? "0" : "") << day
              << "/" << year << ":\n"
              << "  Ordinal Day: " << ordinal << "\n"
              << "  Converted Back: " << convertOrdinalToDate(year, ordinal) << std::endl;
}

int main() {
    std::cout << "Welcome to the Date and Ordinal Day Converter!\n";

    int year = Utility::readYear();
    short month = Utility::readMonth("Enter Month: ");

    short day = Utility::readDay("Enter Day: ", year, month);

    printOrdinalAndDate(year, month, day);

    return 0;
}
