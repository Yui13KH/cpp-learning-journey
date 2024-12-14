#include <iostream>

using namespace std;

int readInput(string msg) {
    int number = 0;
    do {
        cout << msg << " ";
        cin >> number;
    } while (number <= 0);
    return number;
}

bool checkPerfectNumber(int number) {
    if (number <= 1) return false;  // Perfect numbers are greater than 1
    int sum = 0;
    for (int i = 1; i < number; i++) {  // Loop from 1 to number-1
        if (number % i == 0) {
            sum += i;
        }
    }
    return number == sum;
}

void printPerfectNumbersToN(int number) {
    // loop use checkPerfectNumber function , returns true print , else dont
    for (int i = 1; i <= number; i++) {
        if (checkPerfectNumber(i)) {
            cout << i << endl;
        }
    }
}

int main() { printPerfectNumbersToN(readInput("enter upper limit for perfect numbers")); }