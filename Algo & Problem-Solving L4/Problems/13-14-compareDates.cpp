#include "Utility.h"

void printDateComparison(const strDate& date1, const strDate& date2) {
    DateComparison result = Utility::compareDates(date1, date2);
    switch (result) {
        case EARLIER:
            Utility::printDate(date1);
            std::cout << " is earlier than ";
            Utility::printDate(date2);
            std::cout << std::endl;
            break;
        case SAME:
            Utility::printDate(date1);
            std::cout << " is the same as ";
            Utility::printDate(date2);
            std::cout << std::endl;
            break;
        case LATER:
            Utility::printDate(date1);
            std::cout << " is later than ";
            Utility::printDate(date2);
            std::cout << std::endl;
            break;
    }
}

int main() {
    strDate date1 = Utility::readStructure("Enter Date 1: ");
    strDate date2 = Utility::readStructure("Enter Date 2: ");

    printDateComparison(date1, date2);
}
