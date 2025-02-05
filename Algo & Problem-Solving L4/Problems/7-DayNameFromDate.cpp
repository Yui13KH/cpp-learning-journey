#include "Utility.h"
#include <iostream>

const std::string monthNames[] = {"January",   "February", "March",    "April",
                                  "May",       "June",     "July",     "August",
                                  "September", "October",  "November", "December"};

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

void printDayOfTheWeek(int year, short month, short day) {
    std::cout << "Day " << day << " of " << monthNames[month - 1] << " in year " << year << " is "
              << nameOfTheDay[Utility::getDayOfTheWeek(year, month, day)] << std::endl;
}

int main() {
    int Year = Utility::readYear();
    short Month = Utility::readMonth();
    short Day = Utility::readDay("Enter day: ", Year, Month);

    printDayOfTheWeek(Year, Month, Day);

    return 0;
}
