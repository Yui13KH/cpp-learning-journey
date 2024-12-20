#include <iostream>
#include <string>

using namespace std;

bool isValidPassword(const string& str) {
    if (str.length() != 3) return false;
    for (char c : str) {
        if (c < 'A' || c > 'Z') {
            return false;
        }
    }
    return true;
}  // simple check if its 3 letters long and in range

string readInput(const string& msg) {
    string strNumber;
    bool validInput = false;

    do {
        cout << msg << endl;
        cin >> strNumber;

        if (isValidPassword(strNumber)) {
            validInput = true;
        } else {
            cout << "Invalid input. Please enter exactly 3 uppercase letters (A-Z)." << endl;
        }

    } while (!validInput);

    return strNumber;
}

void printAlphabetTriplet(string password) {
    string passwordCheck = "";
    int counter = 0;

    // Nested loops to generate all triplets
    for (int i = 65; i <= 90; i++) {
        for (int j = 65; j <= 90; j++) {
            for (int k = 65; k <= 90; k++) {
                counter++;
                passwordCheck = string(1, char(i)) + char(j) + char(k);

                if (passwordCheck == password) {
                    cout << "Password is " << passwordCheck << endl;
                    cout << "Found after " << counter << " trials." << endl;
                    return;
                } else {
                    cout << "Trial[" << counter << "]: " << passwordCheck << endl;
                }
            }
        }
    }
}

int main() {
    printAlphabetTriplet(readInput("Enter a password of 3 capital letters: "));
    return 0;
}

// (i - 65) * 26 * 26 + (j - 65) * 26 + (k - 65) + 1 , doing this to calculate the entire number of
// trials