// well assume the txt file is always Clients.txt
#include "BankUtils.h"

using namespace BankUtils;  // i aint rewriting this everytime

const std::string ClientsFileName = "Clients.txt";

void showAllClients(std::string filename) { PrintClients(filename); }

int main() {
    showAllClients(ClientsFileName); // testing for now

    return 0;
}

// compile command : g++ Bank.cpp BankUtils.cpp -o BankSystem