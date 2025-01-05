#include <iostream>
using namespace std;

void funcC() {
    cout << "In funcC()" << endl;
}

void funcB() {
    cout << "In funcB()" << endl;
    funcC(); // funcC is called here
}

void funcA() {
    cout << "In funcA()" << endl;
    funcB(); // funcB is called here
}

int main() {
    cout << "In main()" << endl;
    funcA(); // funcA is called here
    return 0;
}