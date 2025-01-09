#include <iostream>
using namespace std;

int main() {
    // Declare pointers for int and float
    int* ptrX;    // Pointer to an integer
    float* ptrY;  // Pointer to a float

    // Dynamically allocate memory for these variables
    ptrX = new int;
    ptrY = new float;

    // Assign values to the dynamically allocated variables
    *ptrX = 10;
    *ptrY = 10.5f;

    // Use the allocated memory
    cout << "Value of ptrX: " << *ptrX << endl;
    cout << "Value of ptrY: " << *ptrY << endl;

    // Deallocate the memory to avoid memory leaks
    delete ptrX;
    delete ptrY;

    ptrX = nullptr;
    ptrY = nullptr;  // to avoid dangling pointers

    // dynamically make an array

    int num = 0;
    cout << "Enter number of users: " << endl;
    cin >> num;

    ptrX = new int[num];  // reusing the same previous pointer

    cout << "enter ages of users: " << endl;

    for (int i = 0; i < num; i++) {
        cout << "User " << i + 1 << ": ";

        cin >> *(ptrX + i);
    }

    cout << "\nDisplaying ages of users" << endl;
    for (int i = 0; i < num; i++) {
        cout << "User " << i + 1 << ": " << *(ptrX + i) << endl;
    }

    delete[] ptrX;
    ptrX = nullptr;

    return 0;
}