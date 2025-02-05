#include "Utility.h"

bool isLastDayInMonth(int year, short month, short day) {
    if (day == Utility::getDaysInMonth(year, month)) {
        return true;
    } else {
        return false;
    }
}

bool isLastMonthInYear(int year, short month, short day) {
    if (month == 12) {
        return true;
    }
    return false;
}

void printLastDay_Month(int year, short month, short day) {
    if (isLastDayInMonth(year, month, day)) {
        std::cout << "Yes  " << day << " is last day in month" << std::endl;
    } else {
        std::cout << "No  " << day << " is not last day in month" << std::endl;
    }

    if (isLastMonthInYear(year, month, day)) {
        std::cout << "Yes  " << month << " is last month in year" << std::endl;
    } else {
        std::cout << "No  " << month << " is not last month in year" << std::endl;
    }
}

int main() {
    strDate date = Utility::readStructure("Enter Year: ");

    printLastDay_Month(date.year, date.month, date.day);
    return 0;
}