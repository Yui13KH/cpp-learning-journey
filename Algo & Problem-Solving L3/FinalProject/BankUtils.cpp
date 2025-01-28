// i have no idea how to order this but lets do the normal stuff

/*
1 - Show All Clients
2 - Add New Client
3 - Delete Client
4 - Update Client
5 - Find Client and Print its values
6 - Transactions (deposit , withdraw , all balances , menu)

1 - for the first thing u need {
    - read accounts from .txt files as a vector of strings
    - parse them to a vector of structs
    - print the details of those vector of structs into terminal
    - print all of their details in console
}

2 - {
    - read accounts from .txt files as a vector of strings
    - read client details from user
    - parse the struct into line
    - push line into vector of strings
    - overwrite file
}

3 - {
    deleting an account i a bit more annoying
    - cut string first part to delimiter , to extract the account number ,

    - check account number with inputted number for deletion
    - it match , confirm deletion ? , delete
    - if not match , account number isnt in file
    - deletion works by copying the original vector of strings to a new one except the account
number u want to delete
}

4 - {
    pretty much like deletion but instead of deleting
    u find account number ,
    extract the entire file ,
    parse to struct ,
    using the struct re-assign its values , except its account number
    - parse to line
    - rewrite the original struct
    - overwrite the file
}

5 - {
    using the account number finding logic
    , find account
    , take its valuse as line
    , parse to struct
    , print them
}

6 - {
    using the account number logic , access account
    parse to struct ,
    re-assign account balance value depending on option
}
 */

#include "BankUtils.h"

struct strClient {
    std::string accountNumber;
    std::string pinCode;
    std::string fullName;
    std::string phoneNumber;
    int accountBalance = 0;
};

std::string getValidString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) {
            return input;
        }
        std::cout << "Please enter a valid string: ";
    }
}

int getValidPositiveInt(const std::string& prompt) {
    int input;
    std::string line;

    while (true) {
        std::cout << prompt;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        if (iss >> input && input > 0 && iss.eof()) {
            return input;
        }

        std::cout << "Please enter a valid positive integer: ";
    }
}

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

void ReadClient(strClient& client) {
    std::cout << "\nClient Information" << std::endl;
    client.accountNumber = getValidString("Enter Account Number: ");
    client.pinCode = getValidString("Enter PIN Code: ");
    client.fullName = getValidString("Enter Full Name: ");
    client.phoneNumber = getValidString("Enter Phone Number: ");
    client.accountBalance = getValidPositiveInt("Enter Account Balance: ");
    std::cout << "\nClient Info Collected" << std::endl;
}