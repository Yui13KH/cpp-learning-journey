#include "Utility.h"
#include <iostream>
#include <string>
#include <functional>

enum DateComparison { EARLIER = 1, SAME, LATER };

struct sDate {
    int year;
    short month;
    short day;
};

short daysInMonth(int year, short month) {
    static const short monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2 && Utility::isLeapYear(year)) ? 29 : monthDays[month];
}

int readInt(const std::string& prompt, std::function<bool(int)> validator) {
    int input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (!std::cin.fail() && validator(input)) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Invalid input, try again." << std::endl;
    }
    return input;
}
sDate ReadFullDate() {
    sDate Date;

    Date.year = readInt("Enter Year (e.g., 2025): ", [](int y) { return y > 0; });
    Date.month = readInt("Enter Month (1-12): ", [](int m) { return m >= 1 && m <= 12; });
    Date.day = Utility::readDay("Enter Day: ", Date.year, Date.month);

    return Date;
}

DateComparison compareDates(const sDate& date1, const sDate& date2) {
    if (date1.year != date2.year) return (date1.year < date2.year) ? EARLIER : LATER;
    if (date1.month != date2.month) return (date1.month < date2.month) ? EARLIER : LATER;
    if (date1.day != date2.day) return (date1.day < date2.day) ? EARLIER : LATER;
    return SAME;
}

void printDate(const sDate& date) {
    std::cout << date.year << "/" << date.month << "/" << date.day;
}

void printDateComparison(const sDate& date1, const sDate& date2) {
    DateComparison result = compareDates(date1, date2);

    switch (result) {
        case EARLIER:
            printDate(date1);
            std::cout << " is earlier than ";
            printDate(date2);
            std::cout << std::endl;
            break;
        case SAME:
            printDate(date1);
            std::cout << " is the same as ";
            printDate(date2);
            std::cout << std::endl;
            break;
        case LATER:
            printDate(date1);
            std::cout << " is later than ";
            printDate(date2);
            std::cout << std::endl;
            break;
    }
}

int main() {
    sDate date1 = ReadFullDate();
    sDate date2 = ReadFullDate();

    printDateComparison(date1, date2);
}
