#pragma once

#include <iostream>
#include <string>
#include <functional>
#include <limits>
#include <sstream>

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

}  // namespace Utility
