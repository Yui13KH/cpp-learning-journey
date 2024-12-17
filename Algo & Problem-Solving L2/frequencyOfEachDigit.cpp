#include <iostream>
using namespace std;

// this is the way i 100% believe the instructor going to solve it

// i was right instead tho the instructor didnt use an array , he ran the function immediatly in a
// the print function , checked if its over 0

int readNumber(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;

    } while (number <= 0);
    return number;
}

void countFrequency(int number, int numberFrequency[]) {
    int remainder = 0;
    while (number > 0) {
        remainder = number % 10;
        number /= 10;
        numberFrequency[remainder] += 1;
    }
}

void printAllFrequencies(int numberFrequency[]) {
    for (int i = 0; i <= 9; i++) {
        if (numberFrequency[i] <= 0) {
            continue;
        } else {
            cout << "frequency of " << i << " is " << numberFrequency[i] << endl;
        }
    }
}

int main() {
    int number = readNumber("enter a number: ");
    int numberFrequencies[10] = {0};

    countFrequency(number, numberFrequencies);
    printAllFrequencies(numberFrequencies);
}