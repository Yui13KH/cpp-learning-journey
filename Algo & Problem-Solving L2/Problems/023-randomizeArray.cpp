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

void randomizeArray(int randomizedArray[], int& size) {
    size = getNumberInRange("Enter Number in Range of 1 to 100: ", 1, 100);
    for (int i = 0; i < size; i++) {
        randomizedArray[i] = RandomNumber(1, 100);
    }
}

void printResults(int randomizedArray[], int size) {
    cout << "Randomized Array: ";
    for (int i = 0; i < size; i++) {
        cout << randomizedArray[i] << " ";
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int size = 0;
    int randomizedArray[100];
    randomizeArray(randomizedArray, size);
    printResults(randomizedArray, size);
    return 0;
}