#include <iostream>
#include <cstdlib>

using namespace std;

int getNumberInRange(string message, int min, int max) {
    int number;
    do {
        cout << message;
        cin >> number;
    } while (number < min || number > max);
    return number;
}

int RandomNumber(int from, int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}

void fillArrayFrom1ToN(int originalArray[], int &size) {
    size = getNumberInRange("Input Nmber from 1 to 100: ", 1, 100);
    for (int i = 0; i <= size; i++) {
        originalArray[i] = i + 1;
    }
}

void shuffleArray(int originalArray[], int shuffledArray[], int size) {
    for (int i = 0; i < size; i++) {
        int number;

        do {
            number = RandomNumber(0, size - 1);
        } while (shuffledArray[number] != 0);

        shuffledArray[number] = originalArray[i];
    }
}

void printArrayElement(int array[], int size) {
    cout << "Array Elements are: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    };
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int originalArray[100];
    int shuffeledArray[100] = {0};
    int size = 0;
    fillArrayFrom1ToN(originalArray, size);
    printArrayElement(originalArray, size);
    shuffleArray(originalArray, shuffeledArray, size);
    printArrayElement(shuffeledArray, size);
    return 0;
}