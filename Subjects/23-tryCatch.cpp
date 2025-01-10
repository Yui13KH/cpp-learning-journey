#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> num{1, 2, 3, 4, 5};
    try {
        cout << num.at(5);  // trying to acess a data that doenst exists
    } catch (...) {
        cout << "out of bound\n";
    }
    cout << "\nwithout the try catch " << endl;
    cout << num.at(5) << endl;
    return 0;
}