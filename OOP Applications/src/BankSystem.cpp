#include <iostream>
#include "../Libaries/clsPerson.h"
#include "../Libaries/clsBankClient.h"

int main() {
    clsBankClient Client1 = clsBankClient::Find("A101");

    Client1.Print();

    return 0;
}