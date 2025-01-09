// an important review of the concept for feature stuff :D

#include <iostream>

using namespace std;

int main() {
    int a = 10;
    cout << "value of a " << a << endl; 
    cout << "refrece of a " << &a << endl;

    int * p = &a;
    cout << "Pointer value " << p << endl;
    cout << "Pointer refrence " << &p << endl;
    cout << "derefrenced pointer value " << *p << endl;

    *p = 20;

    cout << "value of a after changing it through pointer p " << a << endl;
    cout << "value of derefrenced pointer p after changing its refrenced variable value " << *p << endl;

    a = 30;

    cout << "value of a after directly changing it " << a << endl;
    cout << "value of derefrenced pointer p after changing value directly from its variable " << *p << endl;

  


    return 0;
}