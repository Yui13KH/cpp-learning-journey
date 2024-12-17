#include <iostream>
using namespace std;

// this is the way i 100% believe the instructor going to solve it

// i was right instead tho the instructor didnt use an array , he ran the function immediatly in a the print function , checked if its over 0 

int readNumber(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;

    } while (number <= 0);
    return number;
}

int countFrequency(int number, int frequencyNumber) {
    int counter = 0;
    int remainder = 0;
    while (number > 0) {
        remainder = number % 10;
        number /= 10;

        if (remainder == frequencyNumber) counter++;
    }
    return counter;
}

void allFrequencies(int number, int numberValues[]) {
    for (int i = 0; i < 10; i++) {
        numberValues[i] = countFrequency(number, i);
    }
}

void printFrequencies(int numberValues[]) {
    for (int i = 0; i < 10; i++) {
        if (numberValues[i] > 0) {
            cout << "The frequency of " << i << " is " << numberValues[i] << endl;
        }
    }
}

int main() {
    int number = readNumber("Enter a positive number: ");
    int numberFrequencies[10] = {0};

    allFrequencies(number, numberFrequencies);
    printFrequencies(numberFrequencies);
}