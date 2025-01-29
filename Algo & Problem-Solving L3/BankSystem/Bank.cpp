#include "BankUtils.h"

using namespace BankUtils;
// Function prototypes (assuming they exist elsewhere)

const std::string ClientsFileName = "Clients.txt";  // Example filename

int main() {
    bankManagementSystem(ClientsFileName);
    return 0;
}

// command to compile : g++ Bank.cpp BankUtils.cpp -o BankSystem