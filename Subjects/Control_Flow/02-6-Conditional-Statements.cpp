#include <iostream>
using namespace std;

enum enWeekDays { MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

int main() {
    int day;
    cout << "Enter a number between 1 and 7: ";
    cin >> day;

    if (day == 1) {
        cout << "Monday \n";
    } else if (day == 2) {
        cout << "Tuesday \n";
    } else if (day == 3) {
        cout << "Wednesday \n";
    } else if (day == 4) {
        cout << "Thursday \n";
    } else if (day == 5) {
        cout << "Friday \n";
    } else if (day == 6) {
        cout << "Saturday \n";
    } else if (day == 7) {
        cout << "Sunday \n";
    } else {
        cout << "Invalid day \n";
    }

    // or you can use switch case too

    /*
    switch (day) {
        case 1:
            cout << "Monday";
            break;
        case 2:
            cout << "Tuesday";
            break;
        case 3:
            cout << "Wednesday";
            break;
        case 4:
            cout << "Thursday";
            break;
        case 5:
            cout << "Friday";
            break;
        case 6:
            cout << "Saturday";
            break;
        case 7:
            cout << "Sunday";
            break;
        default:
            cout << "Invalid day";
            break;
    } */

    // enums with switch case

    enWeekDays dayOfWeek;
    int enumValue;
    cout << "Enter a number between 1 and 7, for enum:";
    cin >> enumValue;
    dayOfWeek = enWeekDays(enumValue);

    // you can use else if's but switch case is more readable
    switch (dayOfWeek) {
        case MONDAY:
            cout << "Monday \n";
            break;
        case TUESDAY:
            cout << "Tuesday \n";
            break;
        case WEDNESDAY:
            cout << "Wednesday \n";
            break;
        case THURSDAY:
            cout << "Thursday \n";
            break;
        case FRIDAY:
            cout << "Friday \n";
            break;
        case SATURDAY:
            cout << "Saturday \n";
            break;
        case SUNDAY:
            cout << "Sunday \n";
            break;
        default:
            cout << "Invalid day \n";
            break;
    }

    return 0;
}