#include <iostream>
#include <iomanip>
#include <string>

short ReadYear() {
    short year = 0;
    std::cout << "\nEnter Year To Check: ";
    std::cin >> year;
    return year;
}

bool isLeapYear(short year) { return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0); }
short getDaysInMonth(short year, short month) {
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return days[month];
}

int getDayOfTheWeek(short year, short month, short day) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

// for more info on this formula : https://en.wikipedia.org/wiki/Zeller%27s_congruence

void printMonth(int year, int month) {
    std::string names[] = {"",    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    if (month < 1 || month > 12) {
        std::cout << "Invalid month." << std::endl;
        return;
    }

    int days = getDaysInMonth(year, month);
    int firstDay = getDayOfTheWeek(year, month, 1);

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
    printYear(ReadYear());
    return 0;
}
