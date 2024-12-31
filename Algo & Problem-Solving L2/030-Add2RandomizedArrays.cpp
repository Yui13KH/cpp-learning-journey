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

void randomizeArray(int randomizedArray[], int size) {
    for (int i = 0; i < size; i++) {
        randomizedArray[i] = RandomNumber(1, 100);
    }
}

void SumArray(int firstArray[], int secondArray[], int sumArray[], int size) {
    for (int i = 0; i < size; i++) {
        sumArray[i] = firstArray[i] + secondArray[i];
    }
}

void printResults(int firstArray[], int secondArray[], int sumArray[], int size) {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "arr1 ";
    for (int i = 0; i < size; i++) {
        cout << firstArray[i] << " ";
    }
    cout << endl;

    cout << "arr2 ";
    for (int i = 0; i < size; i++) {
        cout << secondArray[i] << " ";
    }
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "arr3 ";
    for (int i = 0; i < size; i++) {
        cout << sumArray[i] << " ";
    }
    cout << endl;
    cout << "----------------------------------------" << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int firstArray[100], secondArray[100], size, sumArray[100];
    size = getNumberInRange("Enter Number in Range of 1 to 100: ", 1, 100);
    randomizeArray(firstArray, size);
    randomizeArray(secondArray, size);
    SumArray(firstArray, secondArray, sumArray, size);
    printResults(firstArray, secondArray, sumArray, size);
    return 0;
}
