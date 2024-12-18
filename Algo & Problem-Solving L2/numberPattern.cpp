#include <iostream>

using namespace std;

// Take number input, print rows in ascending length and ascending value.

int readInput(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;
    } while (number < 0);
    return number;
}

void printNumberPattern(int number) {
    cout << "\n";
    for (int i = 1; i <= number; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
}

int main() {
    printNumberPattern(readInput("Input a number: "));
    return 0;
}

// yay similar to instructor