#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int from, int to) {
    int random = rand() % (to - from + 1) + from;
    return random;
}

int main() {
    srand(unsigned(time(NULL)));

    RandomNumber(1, 10);

    return 0;
}