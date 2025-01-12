// an important review of the concept for feature stuff :D

#include <vector>
#include <iostream>

using namespace std;

int main() {
    int a = 10;
    cout << "value of a " << a << endl;
    cout << "refrece of a " << &a << endl;

    int* p = &a;
    cout << "Pointer value " << p << endl;
    cout << "Pointer refrence " << &p << endl;
    cout << "derefrenced pointer value " << *p << endl;

    *p = 20;

    cout << "value of a after changing it through pointer p " << a << endl;
    cout << "value of derefrenced pointer p after changing its refrenced variable value " << *p
         << endl;

    a = 30;

    cout << "value of a after directly changing it " << a << endl;
    cout << "value of derefrenced pointer p after changing value directly from its variable " << *p
         << endl;

    // an example of iterator pointers

     std::vector<int> numbers = {10, 20, 30, 40, 50};

    std::vector<int>::iterator it = numbers.begin();
    for (; it != numbers.end(); ++it) {
        std::cout << *it << " " << std::endl;
    }

    return 0;
}