#include <iostream>
using namespace std;

int main() {
    int day;
    cout << "Enter a number between 1 and 7: ";
    cin >> day;

    if (day == 1) {
        cout << "Monday";
    } else if (day == 2) {
        cout << "Tuesday";
    } else if (day == 3) {
        cout << "Wednesday";
    } else if (day == 4) {
        cout << "Thursday";
    } else if (day == 5) {
        cout << "Friday";
    } else if (day == 6) {
        cout << "Saturday";
    } else if (day == 7) {
        cout << "Sunday";
    } else {
        cout << "Invalid day";
    }

    // or you can use switch case too

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
    }

    return 0;
}