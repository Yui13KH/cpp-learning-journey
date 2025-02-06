#include "Utility.h"

std::string nameOfTheDay[7] = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                               "Thursday", "Friday", "Saturday"};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printDateChange(const strDate &oldDate, const strDate &newDate) {
    std::cout << "Before: ";
    Utility::printDate(oldDate);
    std::cout << "After:  ";
    Utility::printDate(newDate);
    std::cout << "\n";
}

void addDays(strDate &date, int days) {
    strDate oldDate = date;
    for (int i = 0; i < days; i++) {
        Utility::incrementDate(date);
    }
    printDateChange(oldDate, date);
}

void subtractDays(strDate &date, int days) {
    strDate oldDate = date;
    for (int i = 0; i < days; i++) {
        Utility::decrementDate(date);
    }
    printDateChange(oldDate, date);
}

void addMonths(strDate &date, int months) {
    strDate oldDate = date;
    for (int i = 0; i < months; i++) {
        int targetDay = date.day;
        date.month++;
        if (date.month > 12) {
            date.month = 1;
            date.year++;
        }
        int dim = Utility::getDaysInMonth(date.year, date.month);
        date.day = (targetDay > dim ? dim : targetDay);
    }
    printDateChange(oldDate, date);
}

void subtractMonths(strDate &date, int months) {
    strDate oldDate = date;
    for (int i = 0; i < months; i++) {
        int targetDay = date.day;
        date.month--;
        if (date.month < 1) {
            date.month = 12;
            date.year--;
        }
        int dim = Utility::getDaysInMonth(date.year, date.month);
        date.day = (targetDay > dim ? dim : targetDay);
    }
    printDateChange(oldDate, date);
}

void addYears(strDate &date, int years) {
    strDate oldDate = date;
    date.year += years;
    int dim = Utility::getDaysInMonth(date.year, date.month);
    if (date.day > dim) date.day = dim;
    printDateChange(oldDate, date);
}

void subtractYears(strDate &date, int years) {
    strDate oldDate = date;
    date.year -= years;
    int dim = Utility::getDaysInMonth(date.year, date.month);
    if (date.day > dim) date.day = dim;
    printDateChange(oldDate, date);
}

int daysTillEndOfMonth(const strDate &date) {
    return Utility::getDaysInMonth(date.year, date.month) - date.day;
}

int getDayOfYear(const strDate &date) {
    int dayOfYear = 0;
    for (int m = 1; m < date.month; m++) {
        dayOfYear += Utility::getDaysInMonth(date.year, m);
    }
    dayOfYear += date.day;
    return dayOfYear;
}

int daysTillEndOfYear(const strDate &date) {
    int totalDays = Utility::isLeapYear(date.year) ? 366 : 365;
    return totalDays - getDayOfYear(date);
}

bool isEndOfWeek(const strDate &date) {
    // Define end of week as Saturday (index 6, since Utility::getDayOfTheWeek returns 0 for Sunday)
    return (Utility::getDayOfTheWeek(date.year, date.month, date.day) == 6);
}

bool isWeekend(const strDate &date) {
    int dow = Utility::getDayOfTheWeek(date.year, date.month, date.day);
    // Weekend: Saturday (6) or Sunday (0)
    return (dow == 0 || dow == 6);
}

bool isBusinessDay(const strDate &date) { return !isWeekend(date); }

void additionMenu(strDate &date) {
    int choice;
    do {
        clearScreen();
        std::cout << "Current Date: ";
        Utility::printDate(date);
        printf("\nAddition Menu:\n");
        printf("%02d - %-20s\n", 1, "Add X Days");
        printf("%02d - %-20s\n", 2, "Add 1 Week");
        printf("%02d - %-20s\n", 3, "Add X Weeks");
        printf("%02d - %-20s\n", 4, "Add 1 Month");
        printf("%02d - %-20s\n", 5, "Add X Months");
        printf("%02d - %-20s\n", 6, "Add 1 Year");
        printf("%02d - %-20s\n", 7, "Add X Years");
        printf("%02d - %-20s\n", 8, "Add 1 Decade");
        printf("%02d - %-20s\n", 9, "Add X Decades");
        printf("%02d - %-20s\n", 10, "Add 1 Century");
        printf("%02d - %-20s\n", 11, "Add 1 Millennium");
        printf("%02d - %-20s\n", 12, "Go Back");

        choice = Utility::getValidPositiveInt("Choose an option: ");
        switch (choice) {
            case 1: {
                int days = Utility::getValidPositiveInt("Enter days to add: ");
                addDays(date, days);
                break;
            }
            case 2:
                addDays(date, 7);
                break;
            case 3: {
                int weeks = Utility::getValidPositiveInt("Enter weeks to add: ");
                addDays(date, weeks * 7);
                break;
            }
            case 4:
                addMonths(date, 1);
                break;
            case 5: {
                int months = Utility::getValidPositiveInt("Enter months to add: ");
                addMonths(date, months);
                break;
            }
            case 6:
                addYears(date, 1);
                break;
            case 7: {
                int years = Utility::getValidPositiveInt("Enter years to add: ");
                addYears(date, years);
                break;
            }
            case 8:
                addYears(date, 10);
                break;
            case 9: {
                int decades = Utility::getValidPositiveInt("Enter decades to add: ");
                addYears(date, decades * 10);
                break;
            }
            case 10:
                addYears(date, 100);
                break;
            case 11:
                addYears(date, 1000);
                break;
            case 12:
                break;
            default:
                std::cout << "Invalid option.\n";
        }
        Utility::pause();
    } while (choice != 12);
}

void subtractionMenu(strDate &date) {
    int choice;
    do {
        clearScreen();
        std::cout << "Current Date: ";
        Utility::printDate(date);
        printf("\nSubtraction Menu:\n");
        printf("%02d - %-20s\n", 1, "Subtract X Days");
        printf("%02d - %-20s\n", 2, "Subtract 1 Week");
        printf("%02d - %-20s\n", 3, "Subtract X Weeks");
        printf("%02d - %-20s\n", 4, "Subtract 1 Month");
        printf("%02d - %-20s\n", 5, "Subtract X Months");
        printf("%02d - %-20s\n", 6, "Subtract 1 Year");
        printf("%02d - %-20s\n", 7, "Subtract X Years");
        printf("%02d - %-20s\n", 8, "Subtract 1 Decade");
        printf("%02d - %-20s\n", 9, "Subtract X Decades");
        printf("%02d - %-20s\n", 10, "Subtract 1 Century");
        printf("%02d - %-20s\n", 11, "Subtract 1 Millennium");
        printf("%02d - %-20s\n", 12, "Go Back");

        choice = Utility::getValidPositiveInt("Choose an option: ");
        switch (choice) {
            case 1: {
                int days = Utility::getValidPositiveInt("Enter days to subtract: ");
                subtractDays(date, days);
                break;
            }
            case 2:
                subtractDays(date, 7);
                break;
            case 3: {
                int weeks = Utility::getValidPositiveInt("Enter weeks to subtract: ");
                subtractDays(date, weeks * 7);
                break;
            }
            case 4:
                subtractMonths(date, 1);
                break;
            case 5: {
                int months = Utility::getValidPositiveInt("Enter months to subtract: ");
                subtractMonths(date, months);
                break;
            }
            case 6:
                subtractYears(date, 1);
                break;
            case 7: {
                int years = Utility::getValidPositiveInt("Enter years to subtract: ");
                subtractYears(date, years);
                break;
            }
            case 8:
                subtractYears(date, 10);
                break;
            case 9: {
                int decades = Utility::getValidPositiveInt("Enter decades to subtract: ");
                subtractYears(date, decades * 10);
                break;
            }
            case 10:
                subtractYears(date, 100);
                break;
            case 11:
                subtractYears(date, 1000);
                break;
            case 12:
                break;
            default:
                std::cout << "Invalid option.\n";
        }
        Utility::pause();
    } while (choice != 12);
}

void checkMenu(const strDate &date) {
    int choice;
    do {
        clearScreen();
        printf("Current Date: ");
        Utility::printDate(date);
        printf("\nCheck Menu:\n");
        printf("%02d - %-35s\n", 1, "Check if Leap Year");
        printf("%02d - %-35s\n", 2, "Print Day of the Week");
        printf("%02d - %-35s\n", 3, "Is End of Week? (Saturday)");
        printf("%02d - %-35s\n", 4, "Is Weekend? (Sat/Sun)");
        printf("%02d - %-35s\n", 5, "Is Business Day? (Mon-Fri)");
        printf("%02d - %-35s\n", 6, "Days till End of Week (Sat)");
        printf("%02d - %-35s\n", 7, "Days till End of Month");
        printf("%02d - %-35s\n", 8, "Days till End of Year");
        printf("%02d - %-35s\n", 9, "Go Back");

        choice = Utility::getValidPositiveInt("Choose an option: ");
        printf("\n");
        switch (choice) {
            case 1: {
                bool leap = Utility::isLeapYear(date.year);
                printf("Leap Year: %s\n", leap ? "Yes" : "No");
                break;
            }
            case 2: {
                int dow = Utility::getDayOfTheWeek(date.year, date.month, date.day);
                // Assuming Utility::nameOfTheDay is a std::string array
                printf("Day of the Week: %s\n", nameOfTheDay[dow].c_str());
                break;
            }
            case 3: {
                bool endWeek = isEndOfWeek(date);
                printf("Is End of Week (Saturday): %s\n", endWeek ? "Yes" : "No");
                break;
            }
            case 4: {
                bool weekend = isWeekend(date);
                printf("Is Weekend (Sat/Sun): %s\n", weekend ? "Yes" : "No");
                break;
            }
            case 5: {
                bool business = isBusinessDay(date);
                printf("Is Business Day (Mon-Fri): %s\n", business ? "Yes" : "No");
                break;
            }
            case 6: {
                // Calculate days until Saturday.
                // Utility::getDayOfTheWeek returns 0 for Sunday, 1 for Monday, ... 6 for Saturday.
                int dow = Utility::getDayOfTheWeek(date.year, date.month, date.day);
                int daysLeft = (dow <= 6) ? ((6 - dow) % 7) : 0;
                printf("Days till End of Week (Saturday): %d\n", daysLeft);
                break;
            }
            case 7: {
                int daysLeft = daysTillEndOfMonth(date);
                printf("Days till End of Month: %d\n", daysLeft);
                break;
            }
            case 8: {
                int daysLeft = daysTillEndOfYear(date);
                printf("Days till End of Year: %d\n", daysLeft);
                break;
            }
            case 9:
                break;
            default:
                printf("Invalid option.\n");
        }
        Utility::pause();
    } while (choice != 9);
}

void menu(strDate &date) {
    int choice;
    do {
        clearScreen();
        std::cout << "Main Menu:\n"
                     "1 - Addition Menu\n"
                     "2 - Subtraction Menu\n"
                     "3 - Check Menu\n"
                     "4 - Exit\n";
        choice = Utility::getValidPositiveInt("Choose an option: ");
        switch (choice) {
            case 1:
                additionMenu(date);
                break;
            case 2:
                subtractionMenu(date);
                break;
            case 3:
                checkMenu(date);
                break;
            case 4:
                break;
            default:
                std::cout << "Invalid option.\n";
                Utility::pause();
        }
    } while (choice != 4);
}

int main() {
    strDate date = Utility::readStructure("Enter Date");
    menu(date);
    return 0;
}
