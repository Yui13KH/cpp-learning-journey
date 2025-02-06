#include "Utility.h"

short returnVacationDuration(strDate vacationStartDate, strDate vacationEndDate) {
    short weekdayCount = 0;
    strDate currentDate = vacationStartDate;

    // Loop until currentDate is later than vacationEndDate.
    // EARLIER (1) and SAME (2) mean we should continue.
    while (Utility::compareDates(currentDate, vacationEndDate) != LATER) {
        if (Utility::isBusinessDay(currentDate)) {
            weekdayCount++;
        }
        currentDate = Utility::incrementDate(currentDate);
    }

    return weekdayCount;
}

int main() {
    // placeholder
    strDate vacationStartDate = Utility::readStructure("Enter Vacation Start Date: ");
    strDate vacationEndDate = Utility::readStructure("Enter Vacation End Date: ");

    short vacationDuration = returnVacationDuration(vacationStartDate, vacationEndDate);
    std::cout << "Vacation Duration: " << vacationDuration << " days." << std::endl;

    return 0;
}