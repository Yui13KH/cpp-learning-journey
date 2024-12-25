#include <iostream>
#include <cstdlib>
#include <string>

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

char generateRandomChar(int min, int max) { return char(RandomizedNumber(min, max)); }

string generateWord(int length) {
    string word = "";
    for (int i = 0; i < length; i++) {
        word += generateRandomChar(65, 90);
    }
    return word;
}  // function to generate a random word of a given length

string generateKey() {
    string key = "";
    for (int i = 0; i < 4; i++) {
        key += generateWord(4);

        if (i != 3) {
            key += "-";
        }
    }

    return key;
}  // function to generate a random key of length of words , currently 4 words

void fillArrayWithKeys(string arrayOfKeys[], int size) {
    for (int i = 0; i < size; i++) {
        arrayOfKeys[i] = generateKey();
    }
}

void printArrayKeys(string arrayOfKeys[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Array [" << i + 1 << "]: " << arrayOfKeys[i] << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));

    string arrayOfKeys[100];  // using string cuz integer wouldnt work
    int size = readNumberInRange("Enter the number of keys to generate: ", 1, 100);

    fillArrayWithKeys(arrayOfKeys, size);
    printArrayKeys(arrayOfKeys, size);

    return 0;
}
