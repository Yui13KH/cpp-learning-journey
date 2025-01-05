#include <iostream>
using namespace std;
int ReadNumber() {
    int Number; // when u declare a variable the cin checks what type your expecting 
    cout << "Please enter a number?" << endl;
    cin >> Number; // so this line is expecting a number of type int thats why if you input something else it will throw an error
    while (cin.fail()) { // cin is a object not a function the .fail is a function of the object cin 
        // user didn't input a number
        cin.clear(); // clears the error and the input we just entered
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clears the input buffer until the end of the line 
        cout << "Invalid Number, Enter a valid one:" << endl;
        cin >> Number; // asks the user for a valid number again
    }
    return Number;
    // the loop works because the cin.fail() returns true when the user inputs something that is not a number
}
int main() { cout << "Your Number is:" << ReadNumber(); }