#include <iostream>
#include <string>
#include <sstream>
#include <functional>  

bool isLeapYear(short year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

short daysInMonth(short year, short month) {
    static const short monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (month == 2 && isLeapYear(year)) ? 29 : monthDays[month];
}

// using a generic read short for all the other ones :D , also passing a function as a perameter for validation
short readShort(const std::string& prompt, const std::string& errorMsg, std::function<bool(short)> validator) {
    short input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        if (!std::cin.fail() && validator(input)) {
            break;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << errorMsg << std::endl;
    }
    return input;
}

// validation functions that we pass to the upper function
bool validYear(short y) { return y > 0; }
bool validMonth(short m) { return m >= 1 && m <= 12; }

// cant user a set validator cause month and year arent known till runtime
short ReadDay(const std::string& prompt, short year, short month) {
    return readShort(prompt, "Invalid day! Please enter a valid day for the given month and year.",
                     [year, month](short d) { return d >= 1 && d <= daysInMonth(year, month); });
}

short DateToOrdinalDay(short year, short month, short day) {
    short dayCount = day;
    for (short m = 1; m < month; m++) {
        dayCount += daysInMonth(year, m);
    }
    return dayCount;
}

std::string convertOrdinalToDate(short year, short ordinalDay) {
    short month = 1;
    while (ordinalDay > daysInMonth(year, month)) {
        ordinalDay -= daysInMonth(year, month);
        month++;
    }

    std::ostringstream oss;
    oss << (month < 10 ? "0" : "") << month << "/" 
        << (ordinalDay < 10 ? "0" : "") << ordinalDay << "/" 
        << year;
    return oss.str(); // simple improvement in printing for numbers less then 10, 
}

void printOrdinalAndDate(short year, short month, short day) {
    short ordinal = DateToOrdinalDay(year, month, day);
    std::cout << "\nFor " << (month < 10 ? "0" : "") << month << "/" 
              << (day < 10 ? "0" : "") << day << "/" << year << ":\n"
              << "  Ordinal Day: " << ordinal << "\n"
              << "  Converted Back: " << convertOrdinalToDate(year, ordinal) << std::endl;
}

int main() {
    std::cout << "Welcome to the Date and Ordinal Day Converter!\n";
    
    short year = readShort("Enter Year (e.g., 2025): ", "Invalid year! Enter a positive number.", validYear);
    short month = readShort("Enter Month (1-12): ", "Invalid month! Enter a number between 1 and 12.", validMonth);
    short day = ReadDay("Enter Day: ", year, month);

    printOrdinalAndDate(year, month, day);
    
    return 0;
}
