#include "Utility.h"
#include <fstream>

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance = 0;
};

const std::string ClientsFileName = "Clients.txt";  // changable but for consistency and testing

std::vector<std::string> SplitString(std::string input, std::string delimiter) {
    std::vector<std::string> vString;

    short position = 0;
    std::string token;

    while ((position = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, position);  // store word temporarily
        if (token != "") {
            vString.push_back(token);
        }

        input.erase(0, position + delimiter.length());
    }

    if (input != "") {
        vString.push_back(token);  // last word
    }

    return vString;
}

strClient ConvertLineToRecord(std::string line, std::string delimiter = "#//#") {
    strClient Client;
    std::vector<std::string> vClientData;

    vClientData = SplitString(line, delimiter);

    Client.accountNumber = vClientData[0];
    Client.pinCode = vClientData[1];
    Client.fullName = vClientData[2];
    Client.phoneNumber = vClientData[3];
    Client.accountBalance = std::stoi(vClientData[4]);

    return Client;
}

std::vector<strClient> LoadCleintsDataFromFile(std::string FileName) {
    std::vector<strClient> vClients;
    std::fstream MyFile;
    MyFile.open(FileName, std::ios::in);  // read Mode
    if (MyFile.is_open()) {
        std::string Line;
        strClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

void PrintClientCard(const strClient& Client) {
    std::cout << "\nThe following are the client details:\n";
    std::cout << std::left;
    std::cout << std::setw(16) << "\nAccount Number" << ": " << Client.accountNumber;
    std::cout << std::setw(16) << "\nPin Code" << ": " << Client.pinCode;
    std::cout << std::setw(16) << "\nName" << ": " << Client.fullName;
    std::cout << std::setw(16) << "\nPhone" << ": " << Client.phoneNumber;
    std::cout << std::setw(16) << "\nAccount Balance" << ": " << Client.accountBalance << std::endl;
}

bool FindClientByAccountNumber(std::string AccountNumber, strClient& Client) {
    std::vector<strClient> vClients = LoadCleintsDataFromFile(ClientsFileName);
    for (strClient C : vClients) {
        if (C.accountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

std::string ReadClientAccountNumber() {
    std::string AccountNumber = "";
    AccountNumber = utility::getValidString("Enter Account Number: ");
    return AccountNumber;
}

void FindClient() {
    strClient Client;
    std::string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, Client)) {
        PrintClientCard(Client);
    } else {
        std::cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
}

int main() { return 0; }

// compile: g++ 49-ClientByAccountNumber.cpp Utility.cpp -o 49-ClientByAccountNumber