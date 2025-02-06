#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <limits>
#include <sstream>

enum DateComparison { EARLIER = 1, SAME, LATER };
struct strDate {
    int year;
    short month;
    short day;
};

struct strPeriod {
    strDate start;
    strDate end;
};

inline const std::string nameOfTheDay[7] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                                            "Thursday", "Friday", "Saturday"};

const std::string monthNames[] = {"January",   "February", "March",    "April",
                                  "May",       "June",     "July",     "August",
                                  "September", "October",  "November", "December"};

// Declare the utility namespace
namespace Utility {

// Function declarations

int getValidPositiveInt(const std::string& prompt);
std::string getValidString(const std::string& prompt);
bool isLeapYear(int year);
int readInt(
    const std::string& prompt, std::function<bool(int)> validator = [](int) { return true; });
int getDaysInMonth(int year, int month);
bool validYear(int year);
bool validMonth(int month);
int getDayOfTheWeek(int year, int month, int day);
short readDay(const std::string& prompt, int year, short month);
short readMonth(const std::string& prompt = "Enter month (1-12): ");
int readYear(const std::string& prompt = "Enter year (> 0): ");
strDate readStructure(const std::string& prompt);
strPeriod readPeriod(const std::string& prompt);
void printDate(const strDate& date);
bool isLastMonthInYear(int year, short month, short day);
bool isLastDayInMonth(int year, short month, short day);
DateComparison compareDates(const strDate& date1, const strDate& date2);
strDate incrementDate(strDate& date);
strDate decrementDate(strDate& date);
int DifferenceInToDatesInDays(const strDate& startDate, const strDate& endDate,
                              bool includeLastDay = true);
strDate getTodaysDate();
void pause();
bool isWeekend(const strDate& date);
bool isBusinessDay(const strDate& date);
std::string getDayName(const strDate& date);

}  // namespace Utility
