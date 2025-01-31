#include <iostream>

short ReadYear() {
    short Year;
    std::cout << "\nEnter Year To Check: ";
    std::cin >> Year;
    return Year;
}

short ReadMonth() {
    short Month;
    std::cout << "\nEnter Month To Check: ";
    std::cin >> Month;
    return Month;
}

bool isLeapYear(short year) { return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0); }

short getDaysInMonth(short year, short month) {
    if (month < 1 || month > 12) return 0;

    int NumberOfDays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return NumberOfDays[month];
    // return (month == 2) ? (isLeapYear(year) ? 29 : 28) : NumberOfDays[month]; // works but a big confusing
    
}

int getHoursInMonth(short year, short month) { return getDaysInMonth(year, month) * 24; }

int getMinutesInMonth(short year, short month) { return getHoursInMonth(year, month) * 60; }

int getSecondsInMonth(short year, short month) { return getMinutesInMonth(year, month) * 60; }

void printMonthDuration(short year, short month) {
    std::cout << "Month " << month << " in year " << year << " has:" << std::endl;
    std::cout << getDaysInMonth(year, month) << " days" << std::endl;
    std::cout << getHoursInMonth(year, month) << " hours" << std::endl;
    std::cout << getMinutesInMonth(year, month) << " minutes" << std::endl;
    std::cout << getSecondsInMonth(year, month) << " seconds" << std::endl;
}

int main() {
    short Year = ReadYear();
    short Month = ReadMonth();
    printMonthDuration(Year, Month);
    return 0;
}
