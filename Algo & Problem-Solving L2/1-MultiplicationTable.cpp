#include <iostream>
#include <string>
#include <iomanip>  // For formatting output

using namespace std;

int readInput(const string& prompt) {
    int value;
    cout << prompt;
    cin >> value;
    return value;
}

void printHeader(int firstNum, int lastNum) {
    cout << "\t\t\tMultiplication Table from " << firstNum << " to " << lastNum << endl;

    int tableWidth = (lastNum - firstNum + 1) * 8 + 5; // approximate width of the table
    cout << string(tableWidth, '-') << endl;

    cout << "\t";
    for (int i = firstNum; i <= lastNum; ++i) {
        cout << left << setw(8) << i;  // Align numbers to the left.
    }
    cout << endl;
}

void printTableBody(int firstNum, int lastNum) {
    for (int i = firstNum; i <= lastNum; ++i) {
        cout << setw(4) << i << " | ";
        for (int j = firstNum; j <= lastNum; ++j) {
            cout << setw(8) << i * j;
        }
        cout << endl;
    }
}

void printTable(int firstNum, int lastNum) {
    printHeader(firstNum, lastNum);
    printTableBody(firstNum, lastNum);
}

int main() {
    // Read input values
    int firstNum = readInput("Enter the number that the table starts from: ");
    int lastNum = readInput("Enter the number that the table ends at: ");

    // Print the multiplication table
    printTable(firstNum, lastNum);

    return 0;
}

// i kinda overcomplicated it but it works I guess
