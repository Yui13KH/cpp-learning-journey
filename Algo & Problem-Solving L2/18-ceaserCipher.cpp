#include <iostream>
#include <string>

using namespace std;


string readInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

string encrypt(const string& message, int key) {
    string encrypted = "";
    key = key % 26; 

    for (char c : message) {
        if (c >= 'A' && c <= 'Z') { // for of loop , basically like if u use a loop from i = 1 to message.length , goes over all letters 
            encrypted += char((c - 'A' + key + 26) % 26 + 'A'); // this is uhhhh '-' look down
        } else if (c >= 'a' && c <= 'z') {
            encrypted += char((c - 'a' + key + 26) % 26 + 'a');
        } else {
            encrypted += c;
        }
    }
    return encrypted;
}

string decrypt(const string& message, int key) {
    return encrypt(message, -key);
}

void printResults(const string& result, int key) {
    cout << "Result with key " << key << ": " << result << endl;
}

int main() {
    string message = readInput("Enter the message: ");
    int key = stoi(readInput("Enter the encryption key (number): "));

    string encrypted = encrypt(message, key);
    printResults(encrypted, key);

    string decrypted = decrypt(encrypted, key);
    printResults(decrypted, -key);

    return 0;
}


/*char((c - 'A' + key + 26) % 26 + 'A') , this line i am not gonna lie i didnt figure it out myself , the idea is that if normally u input for example Z and shift by even 1 , then it should go to A , but normally it would just go to whatever ascii is after z , this is KINDA fine , but what is not fine is that the user could input a stupid number like 1000 and it will overflow ALL characters cuz ascii limit is 256 it will give u those weird ? squares  

so what this does is 
c - 'A'  this turns any number into a 0 based A which is 65 in ascii becomes 0 , Z becomes 25
+ key adds the shift (encryption key)
+ 26 for negative values ensures it works too
% 26 keeps the range between 0 - 25
+ 'A' undoes the first step and throws it back in the ascii range of 65 to 90

*/ 