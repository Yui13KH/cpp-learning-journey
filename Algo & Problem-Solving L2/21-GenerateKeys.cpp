#include <iostream>
#include <cstdlib>

using namespace std;

int readInput(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;
    } while (number <= 0);
    return number;
}

int generateRandomNumber(int min, int max) { return rand() % (max - min + 1) + min; }

char generateRandomChar() {
    char c = char(generateRandomNumber(65, 90));
    return c;
}

string generateWord(int length) {
    string word = "";
    for (int i = 0; i < length; i++) {
        word += generateRandomChar();
    }
    return word;
}

string generateKey() {
    string key = "";
    for (int i = 0; i < 4; i++) {
        key += generateWord(4);

        if (i != 3) {
            key += "-";
        }
    }

    return key;
}

void printKeys(int number) {
    for (int i = 0; i < number; i++) {
        cout << "Key [" << i + 1 << "] : " << generateKey() << endl;
    }
}

int main() {
    srand((unsigned)time(NULL));
    printKeys(readInput("Enter the number of keys to generate: "));

    return 0;
}