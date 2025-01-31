#include <iostream>

short ReadYear() {
    short Year;
    std::cout << "\nEnter Year To Check: ";
    std::cin >> Year;
    return Year;
}

const std::string monthNames[] = {"January", "February", "March",     "April",   "May",      "June",
                                 "July",    "August",   "September", "October", "November", "December"};

short ReadMonth() {
    short Month;
    do {
        std::cout << "\nEnter Month To Check: ";
        std::cin >> Month;
    } while (Month < 1 || Month > 12);

    return Month;
}

short ReadDay(short month, short year) {
    short maxDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        maxDaysInMonth[1] = 29;
    }

    short Day;
    do {
        std::cout << "\nEnter Day To Check: ";
        std::cin >> Day;
    } while (Day < 1 || Day > maxDaysInMonth[month - 1]);

    return Day;
}

/*
formula for georgian calander goes like this

a = [14 - month / 12]
y = year - a
m = month + 12 * a - 2

for georgin calander

d = (day + y + [y / 4] - [y / 100] + [y / 400] + [31 * m ] / 12) % 7

value of d is a number from 0 to 6
0 = monday
1 = tuesday
etc.

tbh i dont have any idea how the above formula works but it works :D 

 now just use the formula to get the day of the week
*/

std::string nameOfTheDay[7] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                               "Thursday", "Friday", "Saturday"};

int getDayOfTheWeek(short year, short month, short day) {
    int a = (14 - month ) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
}

void printDayOfTheWeek(short year, short month, short day) {
    std::cout << "Day " << day << " of " << monthNames[month - 1] << " in year " << year << " is "
              << nameOfTheDay[getDayOfTheWeek(year, month, day)] << std::endl;
}

int main() {
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay(Month, Year);

    printDayOfTheWeek(Year, Month, Day);

    return 0;
}
