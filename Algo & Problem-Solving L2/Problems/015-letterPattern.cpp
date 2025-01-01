#include <iostream>

using namespace std;

int readInput(string msg) {
    int number = 0;
    do {
        cout << msg;
        cin >> number;
    } while (number < 1 || number > 26); // checks for anything outside of number range
    return number;
}

void prinLetterPattern(int number) {
    cout << "\n";
    for (int i = 0; i < number; i++) {
        char letter = 'a' + i;
        for (int j = 0; j <= i; j++) {  //  this part took me a while to figure out cuz i forget
                                        //  that j will go to 0 for every loop of i but i will be
                                        //  changing while j starts from 0 for every loop
            cout << letter;
        }
        cout << endl;
    }
}

int main() {
    prinLetterPattern(readInput("Enter number between 1 and 26: "));
    return 0;
}