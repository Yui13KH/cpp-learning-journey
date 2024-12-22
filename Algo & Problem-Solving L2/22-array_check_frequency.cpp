#include <iostream>

using namespace std;

int inputPositiveNumber(string message) {
    int number = 0;
    do {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}

int getNumberInRange(string message, int min, int max) {
    int number;
    do {
        cout << message;
        cin >> number;
    } while (number < min || number > max);
    return number;
}  // dont allow the user to input other then 0 - 9 :-)

void inputArrayValues(int arraySize, int arrayOfValues[]) {
    cout << "Enter array elements (each between 0 and 9):" << endl;
    for (int i = 0; i < arraySize; i++) {
        arrayOfValues[i] = getNumberInRange("Element [" + to_string(i + 1) + "]: ", 0, 9);
    }
}

void frequencyOfDigitsInArray(int arraySize, int arrayOfValues[], int arrOfFrequencies[]) {
    // Initialize all items to 0
    for (int i = 0; i < 10; i++) {
        arrOfFrequencies[i] = 0;
    }

    for (int i = 0; i < arraySize; i++) {
        arrOfFrequencies[arrayOfValues[i]]++;
    }
}

void printValues(int arrayOfValues[], int arrOfFrequency[], int digitOfFrequency, int arraySize) {
    cout << "Original Array:";
    for (int i = 0; i < arraySize; i++) {
        cout << " " << arrayOfValues[i];
    }
    cout << endl;

    cout << digitOfFrequency << " is repeated " << arrOfFrequency[digitOfFrequency] << " time(s)"
         << endl;
}

int main() {
    int arrOfValues[100];
    int arrOfFrequencies[10];
    int arraySize = inputPositiveNumber("Enter array size: ");
    inputArrayValues(arraySize, arrOfValues);
    int numberToCheck = getNumberInRange("Enter the number you want to check (0-9): ", 0, 9);

    frequencyOfDigitsInArray(arraySize, arrOfValues, arrOfFrequencies);
    printValues(arrOfValues, arrOfFrequencies, numberToCheck, arraySize);

    return 0;
}