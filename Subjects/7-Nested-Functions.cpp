#include <iostream>
using namespace std;

enum enWeekDays { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };
void printInputMessage() {
    cout << "Enter a number for the day of the week." << endl;
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;
    cout << "6. Saturday" << endl;
    cout << "7. Sunday" << endl;
    cout << "Your choice: ";
}

enWeekDays getDay() {
    enWeekDays day;
    int choice;
    cin >> choice;
    day = (enWeekDays)choice;
    return day;
}

string getDayName(enWeekDays day) {
    switch (day) {
        case MONDAY:
            return "Monday";
            break;
        case TUESDAY:
            return "Tuesday";
            break;
        case WEDNESDAY:
            return "Wednesday";
            break;
        case THURSDAY:
            return "Thursday";
            break;
        case FRIDAY:
            return "Friday";
            break;
        case SATURDAY:
            return "Saturday";
            break;
        case SUNDAY:
            return "Sunday";
            break;
        default:
            return "Invalid day";
            break;
    }
}

int main() {
    printInputMessage();
    enWeekDays day = getDay();
    cout << "The day is: " << getDayName(day) << endl;
}