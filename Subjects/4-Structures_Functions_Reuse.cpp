#include <iostream>
#include <string>
using namespace std;

struct strPerson {
    string firstName;
    string lastName;
    int age;
    string phoneNumber;
};

void ReadPerson(strPerson &person) {
    cout << "Enter first name: ";
    getline(cin, person.firstName);
    cout << "Enter last name: ";
    getline(cin, person.lastName);
    cout << "Enter age: ";
    cin >> person.age;
    cout << "Enter phone number: ";
    cin.ignore(); // to ignore the newline character 
    getline(cin, person.phoneNumber);
}

void PrintPerson(strPerson person) {
    cout << "\n *** Person Details ***" << endl;
    cout << "First name: " << person.firstName << endl;
    cout << "Last name: " << person.lastName << endl;
    cout << "Age: " << person.age << endl;
    cout << "Phone number: " << person.phoneNumber << endl;
    cout << "\n ************************" << endl;
}

int main() {
    strPerson person1; // initializing the struct variable
    ReadPerson(person1);  // calling the function to take input
    PrintPerson(person1); // calling the function to print the details 
    // using these functions we can reuse the code for multiple people , and if we want more details we can just change the struct variable
    // etc...
    return 0;
}