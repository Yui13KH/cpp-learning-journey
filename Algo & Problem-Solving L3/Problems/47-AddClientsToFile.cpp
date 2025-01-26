#include "Utility.h"
#include <fstream>

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance;
};

strClient ReadClient() { // using a function of type struct better then void
    strClient client;

    std::cout << "\nClient Information" << std::endl;
    client.accountNumber = utility::getValidString("Enter Account Number: ");
    client.pinCode = utility::getValidString("Enter PIN Code: ");
    client.fullName = utility::getValidString("Enter Full Name: ");
    client.phoneNumber = utility::getValidString("Enter Phone Number: ");
    client.accountBalance = utility::getValidPositiveInt("Enter Account Balance: ");

    return client;
}

std::string JoinString(const std::vector<std::string> &input, const std::string &delimiter) {
    std::string joinedString;
    for (size_t i = 0; i < input.size(); i++) {
        joinedString += input[i];
        if (i != input.size() - 1) {
            joinedString += delimiter;
        }
    }
    return joinedString;
}

std::string ClientLine(const strClient &client, const std::string &delimiter) {
    std::vector<std::string> clientData = {client.accountNumber, client.pinCode, client.fullName,
                                           client.phoneNumber,
                                           std::to_string(client.accountBalance)};

    return JoinString(clientData, delimiter);
}

void AddClientLineToFile(std::string FileName, std::string ClientLine) {
    std::fstream ClientFile;
    ClientFile.open(FileName, std::ios::out | std::ios::app);
    if (ClientFile.is_open()) {
        ClientFile << ClientLine << std::endl;
        ClientFile.close();
    }
} // appends the new line into the file

void AddNewClient(std::string filename, std::string delimiter) {
    strClient client;
    client = ReadClient();
    AddClientLineToFile(filename, ClientLine(client, delimiter));
} // using nested functions for each of them to do something else

void AddClients(std::string filename, std::string delimiter) {
    char option = 'Y';
    do {
        std::cout << "Adding New Client:\n\n";
        AddNewClient(filename, delimiter);
        std::cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
        std::cin >> option;
    } while (toupper(option) == 'Y');
} // keeps adding clients if user wants

int main() {

    std::string filename = utility::getValidString("Enter File Name: ");
    std::string delimiter = utility::getValidString("Enter delimiter: ");

    AddClients(filename, delimiter);

    return 0;
}

// compile: g++ 47-AddClientsToFile.cpp Utility.cpp -o 47-AddingClientsToFile