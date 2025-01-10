#include <iostream>
#include <string>

using namespace std;

int readPositiveNumbers(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;

    } while (number <= 0);
    return number;
}

void printReversedDigits(int number) {
    while (number > 0) {
        cout << number % 10 << endl;
        number /= 10;
    }
}

void printReversedDigitsAsString(int number) {
    string strNumber = to_string(number);

    for (int i = strNumber.length() - 1; i >= 0; i--) {
        cout << strNumber[i] << endl;
    }
}
// same idea but casted to string

int main() { printReversedDigits(readPositiveNumbers("enter a number to be reversed: ")); }