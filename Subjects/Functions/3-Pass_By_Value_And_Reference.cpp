#include <iostream>
using namespace std;

// This function demonstrates passing by value.
// See? When you pass by value, the function only works with a copy of the variables.
// It won't affect the original variables in main.
void not_real_swap(int a, int b) {
    cout << "Inside function, before swap (by value): " << a << " " << b << endl;
    int temp = a;  // Swapping the copies, not the actual variables.
    a = b;
    b = temp;
    cout << "Inside function, after swap (by value): " << a << " " << b << endl;
}

// This function demonstrates passing by reference.
// Here, you're passing the actual variables, not just copies of them.
// So, any changes made in the function will change the original variables in main. cuz its acessing the place in ram that the variables are stored in.
void Real_swap(int &a, int &b) {
    cout << "Inside function, before swap (by reference): " << a << " " << b << endl;
    int temp = a;  // Swapping the actual variables this time.
    a = b;
    b = temp;
    cout << "Inside function, after swap (by reference): " << a << " " << b << endl;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    cout << "In main, before swap: " << a << " " << b << endl;
    
    // Watch how it changes things inside the function but NOT in main.
    not_real_swap(a, b);
    cout << "In main, after swap (by value): " << a << " " << b << endl;

    // Notice how the changes here actually reflect back in main.
    Real_swap(a, b);
    cout << "In main, after swap (by reference): " << a << " " << b << endl;

    cout << "Just for fun if you print the addresses of a and b: " << &a << " , " << &b << endl;

    return 0; 
}
