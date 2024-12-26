#include <iostream>
#include <cstdlib>

// using namespace std;  i am not using using namespace anymore cause it may cause confusion and its
// not very good

int readNumberInRange(std::string msg, int min, int max) {
    int number;
    do {
        std::cout << msg;
        std::cin >> number;
    } while (min > number || number > max);
    return number;
}

int RandomizedNumber(int min, int max) { return rand() % (max - min + 1) + min; }

void RandomizeArray(int array[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++) {
        array[i] = RandomizedNumber(1, 100);
    }
}

void printArrayElements(int arrayOfKeys[], int arrayLenght) {
    std::cout << "Elements of array are" << std::endl;
    for (int i = 0; i < arrayLenght; i++) {
        std::cout << arrayOfKeys[i] << " ";
    }
    std::cout << std::endl;
}

int searchInArray(const int array[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

void printFoundValue(const int array[], int size, int target) {
    int index = searchInArray(array, size, target);
    if (index != -1) {
        std::cout << "Value " << target << " found at index " << index << " (order: " << index + 1
                  << ")." << std::endl;
    } else {
        std::cout << "Value " << target << " not found in the array." << std::endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int array[100];
    int arrayLenght = readNumberInRange("Enter a number between 1-100: ", 1, 100);
    RandomizeArray(array, arrayLenght);
    printArrayElements(array, arrayLenght);
    int target = readNumberInRange("Enter Number To Search for between 1-100: ", 1, 100);
    searchInArray(array, arrayLenght, target);
    printFoundValue(array, arrayLenght, target);
    return 0;
}