#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

enum DateComparison { EARLIER, LATER, SAME };

class clsDate {
   private:
    int _year;
    short _month;
    short _day;

    static int daysInMonth[12];
    static const std::string monthNames[12];
    static std::string nameOfTheDay[7];

    void _getCurrentDate() {
        std::time_t now = std::time(0);
        std::tm* localTime = std::localtime(&now);
        _year = 1900 + localTime->tm_year;  // tm_year is years since 1900
        _month = 1 + localTime->tm_mon;     // tm_mon is 0-based (0 = January)
        _day = localTime->tm_mday;          // Day of the month
    }

    bool _isValidDate(int day, int month, int year) {
        if (month < 1 || month > 12 || day < 1) return false;
        if (isLeapYear(year)) daysInMonth[1] = 29;  // Adjust for leap year
        return day <= daysInMonth[month - 1];
    }

    std::vector<std::string> _splitString(const std::string& input,
                                          const std::string& delimiter = "/") {
        std::vector<std::string> vString;
        size_t position = 0;
        std::string token;
        std::string tempInput = input;

        while ((position = tempInput.find(delimiter)) != std::string::npos) {
            token = tempInput.substr(0, position);
            if (!token.empty()) {
                vString.push_back(token);
            }
            tempInput.erase(0, position + delimiter.length());
        }
        if (!tempInput.empty()) {
            vString.push_back(tempInput);
        }
        return vString;
    }

    int _daysInMonth(int year, int month) {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                return 31;
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                return 0;
        }
    }

    void addDaysToDate(int daysToAdd) {
        while (daysToAdd > 0) {
            int daysInCurrentMonth = _daysInMonth(_year, _month);
            if (_day + daysToAdd > daysInCurrentMonth) {
                daysToAdd -= (daysInCurrentMonth - _day + 1);  // Move to the next month
                _day = 1;
                _month++;
                if (_month > 12) {
                    _month = 1;
                    _year++;
                }
            } else {
                _day += daysToAdd;
                daysToAdd = 0;  // Done
            }
        }
    }

    static int getDayOfTheWeek(int year, int month, int day) {
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + 12 * a - 2;
        return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    }

   public:
    // Constructors
    clsDate() { _getCurrentDate(); }         // default current date
    clsDate(int day, int month, int year) {  // accepts numbers
        if (_isValidDate(day, month, year)) {
            _day = day;
            _month = month;
            _year = year;
        } else {
            std::cerr << "Invalid date! Using default current date.\n";
            _getCurrentDate();
        }
    }
    clsDate(const std::string& dateString) {  // accepts string
        std::vector<std::string> parts = _splitString(dateString);
        if (parts.size() == 3) {
            int day = std::stoi(parts[0]);
            int month = std::stoi(parts[1]);
            int year = std::stoi(parts[2]);
            if (_isValidDate(day, month, year)) {
                _day = day;
                _month = month;
                _year = year;
                return;
            }
        }
        std::cerr << "Invalid date format! Using default current date.\n";
        _getCurrentDate();
    }
    clsDate(int year, int daysToAdd) {
        _year = year;
        _month = 1;  // January
        _day = 1;    // First day

        addDaysToDate(daysToAdd);
    }

    // Getters
    int getYear() const { return _year; }
    short getMonth() const { return _month; }
    short getDay() const { return _day; }

    // Setters
    void setYear(int year) {
        if (_isValidDate(_day, _month, year))
            _year = year;
        else
            std::cerr << "Invalid year!\n";
    }

    void setMonth(short month) {
        if (_isValidDate(_day, month, _year))
            _month = month;
        else
            std::cerr << "Invalid month!\n";
    }

    void setDay(short day) {
        if (_isValidDate(day, _month, _year))
            _day = day;
        else
            std::cerr << "Invalid day!\n";
    }

    // Leap year check
    static bool isLeapYear(int year) {
        return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    }
    bool isLeapYear() { return isLeapYear(_year); }

    void printDate() { printf("%04d-%02d-%02d\n", _year, _month, _day); }

    static void printDayOfTheWeek(int year, short month, short day) {
        std::cout << "Day " << day << " of " << monthNames[month - 1] << " in year " << year
                  << " is " << nameOfTheDay[getDayOfTheWeek(year, month, day)] << std::endl;
    }

    void printDayOfTheWeek() { printDayOfTheWeek(_year, _month, _day); }

    static DateComparison compareDates(const clsDate& date1, const clsDate& date2) {
        if (date1._year != date2._year) {
            return (date1._year < date2._year) ? EARLIER : LATER;
        }
        if (date1._month != date2._month) {
            return (date1._month < date2._month) ? EARLIER : LATER;
        }
        if (date1._day != date2._day) {
            return (date1._day < date2._day) ? EARLIER : LATER;
        }
        return SAME;
    }

    DateComparison compareDates(const clsDate& other) const { return compareDates(*this, other); }
};

int clsDate::daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::string clsDate::monthNames[12] = {"January",   "February", "March",    "April",
                                             "May",       "June",     "July",     "August",
                                             "September", "October",  "November", "December"};
std::string clsDate::nameOfTheDay[7] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                                        "Thursday", "Friday", "Saturday"};


// u could keep adding more and more methods , but at this point it just copy paste from previous files with small adjustments 
