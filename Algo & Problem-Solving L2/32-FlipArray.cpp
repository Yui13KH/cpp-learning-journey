#include <iostream>
#include <cstdlib>
using namespace std;

int RandomNumber(int from, int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}

int getNumberInRange(string message, int min, int max) {
    int number;
    do {
        cout << message;
        cin >> number;
    } while (number < min || number > max);
    return number;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void fillArrayRandomly(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = RandomNumber(1, 100);
    }
}

void flipArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - i - 1]);
    }
}
// instructor used a loop that goes from 1 to n , and adding elements using size - i - 1

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size = getNumberInRange("Enter the size of the array: ", 1, 100);
    int arr[size];
    fillArrayRandomly(arr, size);
    printArray(arr, size);
    flipArray(arr, size);
    printArray(arr, size);
    cout << endl;

    return 0;
}