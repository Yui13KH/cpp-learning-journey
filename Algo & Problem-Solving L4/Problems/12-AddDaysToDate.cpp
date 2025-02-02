#include <iostream>
#include <string>
#include <functional>

struct sDate {
    int year;
    short month;
    short day;
};

bool isLeapYear(short year) { return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)); }

short daysInMonth(short year, short month) {
    static const short monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2 && isLeapYear(year)) ? 29 : monthDays[month];
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

bool validYear(short y) { return y > 0; }
bool validMonth(short m) { return m >= 1 && m <= 12; }

short ReadDay(const std::string& prompt, short year, short month) {
    return readInt(prompt,
                   [year, month](int d) { return d >= 1 && d <= daysInMonth(year, month); });
}

sDate ReadFullDate() {
    sDate Date;

    Date.year = readInt("Enter Year (e.g., 2025): ", [](int y) { return y > 0; });
    Date.month = readInt("Enter Month (1-12): ", [](int m) { return m >= 1 && m <= 12; });
    Date.day = ReadDay("Enter Day: ", Date.year, Date.month);

    return Date;
}

void addDaysToDate(sDate& date, int daysToAdd) {
    while (daysToAdd >= (isLeapYear(date.year) ? 366 : 365)) {
        daysToAdd -= (isLeapYear(date.year) ? 366 : 365);
        date.year++;
    }

    while (daysToAdd > 0) {
        int daysInCurrentMonth = daysInMonth(date.year, date.month);
        if (daysToAdd + date.day > daysInCurrentMonth) {
            daysToAdd -= (daysInCurrentMonth - date.day + 1);  // Move to the next month
            date.day = 1;
            date.month++;
            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        } else {
            date.day += daysToAdd;
            daysToAdd = 0;  // Done
        }
    }
}

int main() {
    sDate date = ReadFullDate();
    int daysToAdd = readInt("Enter number of days to add: ", [](int d) { return d >= 0; });

    addDaysToDate(date, daysToAdd);

    std::cout << "New Date: " << date.year << "/" << (date.month < 10 ? "0" : "") << date.month
              << "/" << (date.day < 10 ? "0" : "") << date.day << std::endl;

    return 0;
}
