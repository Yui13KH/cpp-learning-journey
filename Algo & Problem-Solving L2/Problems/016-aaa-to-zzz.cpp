#include <iostream>

using namespace std;

void printAlphabetTriplet() {
    // most straight forward is 3 loops
    for (int i = 65; i <= 70; i++) {
        for (int j = 65; j <= 70; j++) {
            for (int k = 65; k <= 70; k++) {
                cout << char(i) << char(j) << char(k) << endl;
            }
        }
    }
}

int main() {
    printAlphabetTriplet();
    return 0;
}