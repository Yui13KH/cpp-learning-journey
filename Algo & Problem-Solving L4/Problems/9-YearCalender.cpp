#include "Utility.h"
#include <iostream>
#include <iomanip>
#include <string>

void printMonth(int year, int month) {
    std::string names[] = {"",    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    if (month < 1 || month > 12) {
        std::cout << "Invalid month." << std::endl;
        return;
    }

    int days = Utility::getDaysInMonth(year, month);
    int firstDay = Utility::getDayOfTheWeek(year, month, 1);

    std::cout << std::setfill('-') << std::setw(29) << "-" << std::setfill(' ') << std::endl;
    std::cout << std::setw(16) << names[month] << std::setw(16) << std::endl;
    std::cout << std::setfill('-') << std::setw(29) << "-" << std::setfill(' ') << std::endl;
    std::cout << "Sun Mon Tue Wed Thu Fri Sat" << std::endl;

    for (int i = 0; i < firstDay; ++i) {
        std::cout << "    ";
    }

    for (int day = 1; day <= days; ++day) {
        std::cout << std::setw(3) << day << " ";
        if ((day + firstDay) % 7 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void printYear(int year) {
    for (int i = 1; i <= 12; i++) {
        printMonth(year, i);
    }
}

int main() {
    printYear(Utility::readYear());
    return 0;
}
