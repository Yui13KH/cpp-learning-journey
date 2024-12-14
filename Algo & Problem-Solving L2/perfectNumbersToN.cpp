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

void printResult(int number) {
    cout << number << " is "
         << (checkPerfectNumber(number) ? "a perfect number" : "not a perfect number") << endl;
}

int main() { printResult(readInput("input a number to be checked perfect of not")); }