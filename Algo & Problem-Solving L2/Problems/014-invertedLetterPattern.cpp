#include <iostream>
using namespace std;

int readInput(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;
    } while (number < 1 || number > 26);  // checks for anything outside of number range
    return number;
}

void printInvertedLetterPattern(int number) {
    cout << "\n";
    for (int i = 64 + number; i > 64; i--) {
        for (int j = number; j > 0; j--) {
            cout << char(i);
        }
        number--;
        cout << endl;
    }
}

int main() {
    printInvertedLetterPattern(readInput("Enter number between 1 and 26: "));
    return 0;
}