#include "Utility.h"

void printDifferenceInDays(strDate& startDate, strDate& endDate, bool includeLastDay) {
    int diff = Utility::DifferenceInToDatesInDays(startDate, endDate, includeLastDay);
    std::cout << "Difference " << (includeLastDay ? "Including" : "Not Including")
              << " Last Day is : " << diff << " days." << std::endl;
}

int main() {
    strDate startDate = Utility::readStructure("Enter Date 1: ");
    strDate endDate = Utility::readStructure("Enter Date 2: ");

    printDifferenceInDays(startDate, endDate, true);
    printDifferenceInDays(startDate, endDate, false);

    return 0;
}