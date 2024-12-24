#include <iostream>
#include <cmath>
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

bool checkPrime(int number) {
    if (number < 2) return false;
    if (number == 2) return true;       // 2 is the only even prime
    if (number % 2 == 0) return false;  // Eliminate even numbers

    int limit = sqrt(number);              // Calculate square root once
    for (int i = 3; i <= limit; i += 2) {  // Check only odd numbers
        if (number % i == 0) return false;
    }
    return true;
}

void randomizeArray(int randomizedArray[], int &size) {
    size = getNumberInRange("Enter Number in Range of 1 to 100: ", 1, 100);
    for (int i = 0; i < size; i++) {
        randomizedArray[i] = RandomNumber(1, 100);
    }
}

int returnMaxInArray(int randomizedArray[], int size) {
    int biggest = randomizedArray[0];  // assume it is biggest
    for (int i = 0; i < size; i++) {
        if (randomizedArray[i] > biggest) {
            biggest = randomizedArray[i];
        }
    }
    return biggest;
}

int returnMinInArray(int randomizedArray[], int size) {
    int smallest = randomizedArray[0];  // assume it is smallest
    for (int i = 0; i < size; i++) {
        if (randomizedArray[i] < smallest) {
            smallest = randomizedArray[i];
        }
    }
    return smallest;
}

int returnSumOfArray(int randomizedArray[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += randomizedArray[i];
    }
    return sum;
}

float returnAverageOfArray(int randomizedArray[], int size) {
    return (float)returnSumOfArray(randomizedArray, size) / size;
}

int returnPrimesInArray(int randomizedArray[], int size) {
    int primesArray[size];
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (checkPrime(randomizedArray[i])) {
            primesArray[counter] = randomizedArray[i];
            counter++;
        }
    }
    if (counter == 0) {
        cout << "There are no primes in the array" << endl;
    }
    return primesArray[size];
}

int returnCopyofArray(int randomizedArray[], int size) {
    int copyArray[size];
    for (int i = 0; i < size; i++) {
        copyArray[i] = randomizedArray[i];
    }
    return copyArray[size];
}

void printArrayElements(int randomizedArray[], int size) {
    cout << "Elements of array is: ";
    for (int i = 0; i < size; i++) {
        cout << randomizedArray[i] << " ";
    }
    cout << endl;
}

void printBiggestInArray(int randomizedArray[], int size) {
    cout << "Biggest element in the array is: " << returnMaxInArray(randomizedArray, size) << endl;
}

void printSmallestInArray(int randomizedArray[], int size) {
    cout << "Smallest element in the array is: " << returnMinInArray(randomizedArray, size) << endl;
}

void printAverageInArray(int randomizedArray[], int size) {
    cout << "Average element in the array is: " << returnAverageOfArray(randomizedArray, size)
         << endl;
}

void printSumInArray(int randomizedArray[], int size) {
    cout << "Sum of elements in the array is: " << returnSumOfArray(randomizedArray, size) << endl;
}

void printCopyOfArray(int randomizedArray[], int size) {
    cout << "Copy of array is: ";
    for (int i = 0; i < size; i++) {
        cout << randomizedArray[i] << " ";
    }
    cout << endl;
}

void printPrimesInArray(int randomizedArray[], int size) {
    cout << "Primes in the array are: ";
    bool hasPrimes = false;
    for (int i = 0; i < size; i++) {
        if (checkPrime(randomizedArray[i])) {  // any non 0 value is true in boolean , thats why
                                               // this condition works
            cout << randomizedArray[i] << " ";
            hasPrimes = true;
        }
    }
    if (!hasPrimes) {
        cout << "There are no primes in the array";
    }
    cout << endl;
}

void printAllResults(int randomizedArray[], int size) {
    printArrayElements(randomizedArray, size);
    printCopyOfArray(randomizedArray, size);
    printBiggestInArray(randomizedArray, size);
    printSmallestInArray(randomizedArray, size);
    printAverageInArray(randomizedArray, size);
    printSumInArray(randomizedArray, size);
    printPrimesInArray(randomizedArray, size);
}

int main() {
    srand((unsigned)time(NULL));
    int randomizedArray[100], size;
    randomizeArray(randomizedArray, size);
    printAllResults(randomizedArray, size);
    return 0;
}