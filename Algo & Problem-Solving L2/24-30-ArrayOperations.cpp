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

void randomizeArray(int randomizedArray[], int &size) {
    size = getNumberInRange("Enter Number in Range of 1 to 100: ", 1, 100);
    for (int i = 0; i < size; i++) {
        randomizedArray[i] = RandomNumber(1, 100);
    }
}

int returnBiggestNumInArray(int randomizedArray[], int size) {
    int biggest = randomizedArray[0];  // assume it is biggest
    for (int i = 0; i < size; i++) {
        if (randomizedArray[i] > biggest) {
            biggest = randomizedArray[i];
        }
    }
    return biggest;
}

int returnSmallestNumInArray(int randomizedArray[], int size) {
    int smallest = randomizedArray[0];  // assume it is smallest
    for (int i = 0; i < size; i++) {
        if (randomizedArray[i] < smallest) {
            smallest = randomizedArray[i];
        }
    }
    return smallest;
}

int returnSumOfArray (int randomizedArray[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += randomizedArray[i];
    }
    return sum;
}

void printArrayElements(int randomizedArray[], int size) {
    cout << "Elements of array is: ";
    for (int i = 0; i < size; i++) {
        cout << randomizedArray[i] << " ";
    }
    cout << endl;
}

void printBiggestInArray(int randomizedArray[], int size) {
    cout << "Biggest element in the array is: " << returnBiggestNumInArray(randomizedArray, size)
         << endl;
}

void printSmallestInArray(int randomizedArray[], int size) {
    cout << "Smallest element in the array is: " << returnSmallestNumInArray(randomizedArray, size)
         << endl;
}

void printAllResults(int randomizedArray[], int size) {
    printArrayElements(randomizedArray, size);
    printBiggestInArray(randomizedArray, size);
    printSmallestInArray(randomizedArray, size);
}

int main() {
    srand((unsigned)time(NULL));
    int randomizedArray[100], size;
    randomizeArray(randomizedArray, size);
    printAllResults(randomizedArray, size);
    return 0;
}