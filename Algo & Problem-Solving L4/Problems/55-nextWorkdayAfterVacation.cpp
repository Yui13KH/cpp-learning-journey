#include "Utility.h"

strDate nextWorkDay(const strDate& startDate, short vacationDuration) {
    strDate returnDate = startDate;
    short vacationDayCount = 0;

    while (vacationDayCount < vacationDuration) {
        if (Utility::isBusinessDay(returnDate)) {
            vacationDayCount++;
        }
        returnDate = Utility::incrementDate(returnDate);
    }

    // Ensure the final return date is a business day
    while (!Utility::isBusinessDay(returnDate)) {
        returnDate = Utility::incrementDate(returnDate);
    }

    return returnDate;
}

int main() {
    // placeholder
    strDate vacationStartDate = Utility::readStructure("Enter Vacation Start Date: ");
    short vacationDuration = Utility::readInt("Enter Vacation Duration: ");

    strDate nextWorkDayDate = nextWorkDay(vacationStartDate, vacationDuration);
    std::cout << "Next Work Day: " << nextWorkDayDate.day << "/" << nextWorkDayDate.month << "/"
              << nextWorkDayDate.year << std::endl;

    return 0;
}