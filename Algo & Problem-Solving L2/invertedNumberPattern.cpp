#include <iostream>

using namespace std;

// Take number input, print rows in descending length and descending value.

int readInput(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;
    } while (number < 0);
    return number;
}

void printInvertedPattern(int number) {
    cout << "\n";
    for (; number > 0; number--) {
        for (int j = 0; j < number; j++) {
            cout << number;
        }
        cout << endl;
    };
}

int main() {
    printInvertedPattern(readInput("Enter a number: "));

    return 0;
}