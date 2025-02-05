#include "Utility.h"

strDate incrementDate(strDate& date) {
    if (!Utility::isLastDayInMonth(date.year, date.month, date.day)) {
        date.day++;
        return date;
    }

    date.day = 1;
    if (!Utility::isLastMonthInYear(date.year, date.month, date.day)) {
        date.month++;
        return date;
    }

    date.month = 1;
    date.year++;
    return date;
}

void printDateIncrement(strDate& date) {
    std::cout << "Before Increment: ";
    Utility::printDate(date);
    std::cout << std::endl;

    std::cout << "After Increment: ";
    incrementDate(date);
    Utility::printDate(date);
    std::cout << std::endl;
}

int main() {
    strDate Date = Utility::readStructure("Enter Date: ");

    printDateIncrement(Date);
    return 0;
}