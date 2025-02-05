#include "Utility.h"

int main() {
    strDate birthDate = Utility::readStructure("Enter your birth date: ");
    strDate currentDate = Utility::getTodaysDate();

    int ageInDays = Utility::DifferenceInToDatesInDays(birthDate, currentDate, false);
    std::cout << "You are " << ageInDays << " days old." << std::endl;

    return 0;
}