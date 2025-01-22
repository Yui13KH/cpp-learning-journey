#include "Utility.h"

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance;
};

void ReadClient(strClient &client) {
    std::cout << "\nClient Information" << std::endl;
    client.accountNumber = utility::getValidString("Enter Account Number: ");
    client.pinCode = utility::getValidString("Enter PIN Code: ");
    client.fullName = utility::getValidString("Enter Full Name: ");
    client.phoneNumber = utility::getValidString("Enter Phone Number: ");
    client.accountBalance = utility::getValidPositiveInt("Enter Account Balance: ");
    std::cout << "\nClient Info Collected" << std::endl;
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

std::string JoinClientData(const strClient &client, const std::string &delimiter) {
    std::vector<std::string> clientData = {
        client.accountNumber, 
        client.pinCode, 
        client.fullName,
        client.phoneNumber,
        std::to_string(client.accountBalance)
    };

    return JoinString(clientData, delimiter);
}

int main() {
    strClient client;
    ReadClient(client);

    std::string delimiter = utility::getValidString("Enter delimiter: ");
    std::string joinedString = JoinClientData(client, delimiter);

    std::cout << joinedString << std::endl;
    return 0;
}

// compile: g++ 45-RecordToLine.cpp Utility.cpp -o 45-RecordToLine