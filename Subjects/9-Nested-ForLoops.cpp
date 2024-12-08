#include <iostream>
using namespace std;

void printAAtoZZ() {
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            cout << char(i) << char(j) << endl;
        }
    }
}

void printStarsBigToSmall() {
    for (int i = 10; i >= 1; i--) {
        for (int j = i; j > 0; j--) {
            cout << "*";
        }
        cout << "\n";
    }
}

void pyramidNumbersShrinking() {
    for (int i = 10; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j << ' ';
        }
        cout << "\n";
    }
}

void pyramidNumbersGrowing() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j << ' ';
        }
        cout << "\n";
    }
}

void pyramidAlphabetGrowing() {
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= i; j++) {
            cout << char(j) << " ";
        }
        cout << "\n";
    }
}

void reverseShrinkingNumbers() {
    for (int i = 10; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            cout << j << " ";
        }
        cout << "\n";
    }
}

int main() {
    // printAAtoZZ();
    // printStarsBigToSmall();
    // pyramidNumbersShrinking();
    // pyramidNumbersGrowing();
    // pyramidAlphabetGrowing();
    // reverseShrinkingNumbers();
    // the homeworks in the video
}