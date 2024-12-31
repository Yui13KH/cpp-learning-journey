#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getNumberInRange(const string& prompt, int min, int max) {
    int number;
    do {
        cout << prompt << " (" << min << " to " << max << "): ";
        cin >> number;
    } while (number < min || number > max);
    return number;
}

int generateRandomNumber(int min, int max) { return rand() % (max - min + 1) + min; }

void swapElements(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void fillArraySequential(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }
}

void shuffleArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int randomIndex = generateRandomNumber(0, size - 1);
        swapElements(array[i], array[randomIndex]);
    }
}

void printArray(const int array[], int size, const string& message) {
    cout << message;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));

    int size = getNumberInRange("Enter the size of the array", 1, 100);

    int array[size];
    fillArraySequential(array, size);

    printArray(array, size, "Original Array: ");

    shuffleArray(array, size);

    printArray(array, size, "Shuffled Array: ");

    return 0;
}
