#include <iostream>
#include <iomanip>
#include <string>

short readYear() {
    short year;
    do {
        std::cout << "\nEnter year: ";
        std::cin >> year;
    } while (year < 1);
    return year;
}

short readMonth() {
    short month;
    do {
        std::cout << "\nEnter month (1-12): ";
        std::cin >> month;
    } while (month < 1 || month > 12);
    return month;
}

short readDay(short month, short year) {
    short day;
    short maxDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        maxDaysInMonth[1] = 29;
    }

    do {
        std::cout << "\nEnter day (1-" << maxDaysInMonth[month - 1] << "): ";
        std::cin >> day;
    } while (day < 1 || day > maxDaysInMonth[month - 1]);

    return day;
}

bool isLeapYear(short year) { return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0); }
short getDaysInMonth(short year, short month) {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return days[month];
}

short FirstDayTillDate(short year, short month, short day) {
    short days = 0;
    for (short i = 1; i < month; ++i) {
        days += getDaysInMonth(year, i);
    }
    return days + day;
}

void printDaysTillDate(short year, short month, short day) {
    short days = FirstDayTillDate(year, month, day);
    std::cout << "Days till date: " << days << std::endl;
    std::cout << "Hours till date: " << days * 24 << std::endl;
    std::cout << "Minutes till date: " << days * 24 * 60 << std::endl;
    std::cout << "Seconds till date: " << days * 24 * 60 * 60 << std::endl;
}

int main() {
    printDaysTillDate(readYear(), readMonth(), readDay(readMonth(), readYear()));
    return 0;
}

