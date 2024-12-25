#include <iostream>
#include <cstdlib>

using namespace std;

int readNumberInRange(string msg, int min, int max) {
    int number;
    do {
        cout << msg;
        cin >> number;
    } while (min > number || number > max);
    return number;
}

int RandomizedNumber(int min, int max) { return rand() % (max - min + 1) + min; }

void RandomizeArray(int array[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        array[i] = RandomizedNumber(1, 100);
    }
}

void printArrayKeys(int arrayOfKeys[], int arrayLenght) {
    cout << "Elements of array are" << endl;
    for (int i = 0; i < arrayLenght; i++) {
        cout << arrayOfKeys[i] << " ";
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int array[100];
    int arrayLenght = readNumberInRange("Enter a number between 1-100: ", 1, 100);
    RandomizeArray(array, arrayLenght);
    printArrayKeys(array, arrayLenght);

    return 0;
}