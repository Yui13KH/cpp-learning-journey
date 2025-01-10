#include <iostream>
using namespace std;

// Overloaded functions
void display(int num) {
    cout << "Integer: " << num << endl;
}

void display(double num) {
    cout << "Double: " << num << endl;
}

void display(string text) {
    cout << "String: " << text << endl;
}

int main() {
    display(5);            // Calls the integer version
    display(3.14);         // Calls the double version
    display("Hello!");     // Calls the string version
    return 0;
}