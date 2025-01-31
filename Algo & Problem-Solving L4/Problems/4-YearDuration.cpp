#include <iostream>

short ReadYear(){
    short Year;
    std::cout << "\n Enter Year To Check: ";
    std::cin >> Year;
    return Year;
}

bool isLeapYear(short year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short getDaysInYear(short year) {
    return (isLeapYear(year)) ? 366 : 365;  // Return 366 for leap years, 365 otherwise
}

short getHoursInYear(short year) {
    return getDaysInYear(year) * 24;  // Hours = days * 24
}

short getMinutesInYear(short year) {
    return getHoursInYear(year) * 60;  // Minutes = hours * 60
}

short getSecondsInYear(short year) {
    return getMinutesInYear(year) * 60;  // Seconds = minutes * 60
}

void printYearDuration(short year) {
    std::cout << "Year " << year << " has:" << std::endl;
    std::cout << getDaysInYear(year) << " days" << std::endl;
    std::cout << getHoursInYear(year) << " hours" << std::endl;
    std::cout << getMinutesInYear(year) << " minutes" << std::endl;
    std::cout << getSecondsInYear(year) << " seconds" << std::endl;
}

int main() {
    short Year = ReadYear();
    printYearDuration(Year);
    return 0;
}
