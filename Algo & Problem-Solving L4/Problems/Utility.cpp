#include "Utility.h"
// doing this to simplify the code and not rewrite the same code again and again

namespace Utility {

int getValidPositiveInt(const std::string& prompt) {
    int input;
    std::string line;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        if (iss >> input && input > 0 && iss.eof()) {
            return input;
        }

        std::cout << "Please enter a valid positive integer: ";
    }
}
// to be honest kinda dead but i used it a lot so removing would break a lot of files , use ReadInt
// instead

std::string getValidString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) {
            return input;
        }
        std::cout << "Please enter a valid string: ";
    }
}

bool isLeapYear(int year) { return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0); }

// Reads an integer from standard input using the provided prompt and validator.
// The default validator accepts any integer.
int readInt(const std::string& prompt, std::function<bool(int)> validator) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (!std::cin.fail() && validator(value)) {
            break;
        }
        std::cout << "Invalid input, try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return value;
}

// Returns the number of days in a given month and year.
int getDaysInMonth(int year, int month) {
    if (month < 1 || month > 12) {
        return 0;  // or throw an exception, depending on your design
    }
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month];
}

// Validates that the year is greater than 0.
bool validYear(int year) { return year > 0; }

// Validates that the month is in the range [1, 12].
bool validMonth(int month) { return month >= 1 && month <= 12; }

// Calculates the day of the week for a given date.
// Returns 0 for Sunday, 1 for Monday, etc.
int getDayOfTheWeek(int year, int month, int day) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

// Reads a day value for a given month and year using a prompt.
short readDay(const std::string& prompt, int year, short month) {
    return readInt(
        prompt, [year, month](int day) { return day >= 1 && day <= getDaysInMonth(year, month); });
}

// Reads a valid month from input.
short readMonth(const std::string& prompt) {
    return readInt(prompt, [](int month) { return month >= 1 && month <= 12; });
}

// Reads a valid year from input.
int readYear(const std::string& prompt) {
    return readInt(prompt, [](int year) { return year > 0; });
}

strDate readStructure(const std::string& prompt) {
    strDate date;

    std::cout << prompt << std::endl;

    date.year = readYear("Enter year: ");
    date.month = readMonth("Enter month (1-12): ");
    date.day = readDay("Enter day: ", date.year, date.month);

    return date;
}

strPeriod readPeriod(const std::string& prompt) {
    strPeriod period;

    std::cout << prompt << std::endl;

    while (true) {
        period.start = readStructure("Enter start date: ");
        std::cout << std::endl;
        period.end = readStructure("Enter end date: ");
        std::cout << std::endl;

        if (compareDates(period.start, period.end) == EARLIER) {
            break;
        }
        std::cout << "Invalid period! End date must be the same or later than the start date. Try "
                     "again.\n";
    }

    return period;
}

void printDate(const strDate& date) {
    std::cout << date.year << "/" << date.month << "/" << date.day;
}

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

DateComparison compareDates(const strDate& date1, const strDate& date2) {
    if (date1.year != date2.year) return (date1.year < date2.year) ? EARLIER : LATER;
    if (date1.month != date2.month) return (date1.month < date2.month) ? EARLIER : LATER;
    if (date1.day != date2.day) return (date1.day < date2.day) ? EARLIER : LATER;
    return SAME;
}

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

strDate decrementDate(strDate& date) {
    if (date.day > 1) {
        date.day--;
        return date;
    }

    if (date.month > 1) {
        date.month--;
        date.day = Utility::getDaysInMonth(date.year, date.month);
        return date;
    }

    date.year--;
    date.month = 12;
    date.day = Utility::getDaysInMonth(date.year, date.month);
    return date;
}

int DifferenceInToDatesInDays(const strDate& startDate, const strDate& endDate,
                              bool includeLastDay) {
    int diff = 0;

    // If startDate is later than endDate, swap them and mark the result as negative.
    bool isNegative = false;
    strDate sDate = startDate;
    strDate eDate = endDate;

    if (compareDates(sDate, eDate) == LATER) {
        std::swap(sDate, eDate);
        isNegative = true;
    }

    // Count days by incrementing the earlier date until it matches the later date.
    while (compareDates(sDate, eDate) != SAME) {
        sDate = incrementDate(sDate);
        diff++;
    }

    // Adjust for including/excluding the last day.
    if (!includeLastDay && diff > 0) {
        diff--;
    }

    return isNegative ? -diff : diff;
}

strDate getTodaysDate() {
    strDate date;
    time_t now = time(0);
    tm* ltm = localtime(&now);
    date.year = ltm->tm_year + 1900;
    date.month = ltm->tm_mon + 1;
    date.day = ltm->tm_mday;
    return date;
}

void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

bool isWeekend(const strDate& date) {
    int dow = Utility::getDayOfTheWeek(date.year, date.month, date.day);
    // weekend in us i believe are saturday (6) and sunday (0)
    return (dow == 5 || dow == 6);
}

bool isBusinessDay(const strDate& date) { return !isWeekend(date); }

std::string getDayName(const strDate& date) {
    return nameOfTheDay[getDayOfTheWeek(date.year, date.month, date.day)];
}

}  // namespace Utility
