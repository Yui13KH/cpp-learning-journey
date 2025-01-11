#include <iostream>
using namespace std;

void checkNumber(int number) {
    // Using if-else
    if (number > 0) {
        cout << number << " is positive." << endl;
    } else {
        cout << number << " is negative." << endl;
    }

    // Using ternary operator for concise code
    cout << number << " is " << (number > 0 ? "positive" : "negative") << endl;
}  // see if its a 2 condition thing a simple true/false then ternary can be very consise but if its
   // more then use if-else cuz ternary will be very hard to read

void checkNumberBad(int number) {
    if (number > 0) {
        cout << number << " is positive." << endl;
    } else if (number < 0) {
        cout << number << " is negative." << endl;
    } else {
        cout << number << " is zero." << endl;
    }

    cout << number << " is " << (number > 0 ? "positive" : (number < 0 ? "negative" : "zero"))
         << endl;
}

int main() {
    int num = 5;
    checkNumber(num);
    checkNumberBad(num);

    return 0;
}
