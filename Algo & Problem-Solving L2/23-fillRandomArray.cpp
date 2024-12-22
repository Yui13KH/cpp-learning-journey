#include <iostream>
#include <cstdlib>

using namespace std;

int inputPositiveNumber(string message) {
    int number = 0;
    do {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}

int RandomNumber(int from, int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}

void fillRandomArray(int arr[], int& size) {
    size = inputPositiveNumber("Enter the size of the array: ");

    for (int i = 0; i < size; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

void printArray(int arr[], int size) {
    cout << "Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand((unsigned)time(NULL));
    int array[100] = {0};
    int arraySize = 0;

    fillRandomArray(array, arraySize);
    printArray(array, arraySize);

    return 0;
}