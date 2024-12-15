#include <iostream>
using namespace std;

int readNumberInput(string msg) {
    int number = 0;
    do {
        cout << msg << endl;
        cin >> number;

    } while (number <= 0);
    return number;
}

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

void printReversedNumber(int inputNumber) {
    cout << "Reversed Number of " << inputNumber << " is " << reverseDigits(inputNumber) << endl;
}

int main() { printReversedNumber(readNumberInput("Input a number to reverse: ")); }