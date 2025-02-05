#include "Utility.h"

void printLastDay_Month(int year, short month, short day) {
    if (Utility::isLastDayInMonth(year, month, day)) {
        std::cout << "Yes  " << day << " is last day in month" << std::endl;
    } else {
        std::cout << "No  " << day << " is not last day in month" << std::endl;
    }

    if (Utility::isLastMonthInYear(year, month, day)) {
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