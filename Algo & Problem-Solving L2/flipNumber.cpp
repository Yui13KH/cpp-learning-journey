#include <iostream>
using namespace std;

string readInput(string msg) {
    string strNumber;
    do {
        cout << msg << endl;
        cin >> strNumber;

        bool isValid = true;
        for (char c : strNumber) {
            if (!isdigit(c)) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            return strNumber;
        } else {
            cout << "Invalid input. Please enter a positive number." << endl;
        }

    } while (true);
}

string reverseDigits(string strNumber) {
    string reversed = "";
    for (int i = strNumber.length() - 1; i >= 0; i--) {
        reversed += strNumber[i];
    }
    return reversed;
}
/*
int reverseDigits(int inputNumber) {
    int reversedNumber = 0;
    int digit = 0;
    while (inputNumber > 0) {
        digit = inputNumber % 10;
        inputNumber /= 10;
        reversedNumber = reversedNumber * 10 + digit;
    }
    return reversedNumber;
}
*/

// look this is exactly how the instructor solved it but it wont work for huge numbers just like
// problem 6 : reverse_digits , instead u could take a string of digits and use a decending for
// loop and make a new string that is reversed

void printReversedNumber(string inputNumber) {
    cout << "Reversed Number of " << inputNumber << " is " << reverseDigits(inputNumber) << endl;
}

int main() { printReversedNumber(readInput("write a number: ")); }