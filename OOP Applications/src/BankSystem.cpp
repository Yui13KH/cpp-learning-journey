#include <iostream>
#include "../Libaries/clsInputValidate.h"
#include "../Libaries/clsBankClient.h"

void PrintClientRecordLine(clsBankClient& Client) {
    std::cout << "| " << std::left << std::setw(15) << Client.AccountNumber() << " | "
              << std::setw(20) << Client.FullName() << " | " << std::setw(25) << Client.Email()
              << " | " << std::setw(15) << Client.Phone() << " | " << std::setw(10)
              << Client.GetPinCode() << " | " << std::setw(12) << Client.GetAccountBalance()
              << " |\n";
}

void PrintTableHeader() {
    std::cout << "\n\t\t\t\t\tClient List\n";
    std::cout << clsUtility::RepeatChar('-', 116) << "\n";
    std::cout << "| " << std::left << std::setw(15) << "Account Number"
              << " | " << std::setw(20) << "Client Name"
              << " | " << std::setw(25) << "Email"
              << " | " << std::setw(15) << "Phone"
              << " | " << std::setw(10) << "Pin Code"
              << " | " << std::setw(12) << "Balance"
              << " |\n";
    std::cout << clsUtility::RepeatChar('-', 116) << "\n";
}

void ReadClientInfo(clsBankClient& Client) {
    cout << "\nEnter FirstName: ";
    Client.SetFirstName(clsInputValidate::ReadString());

    cout << "\nEnter LastName: ";
    Client.SetLastName(clsInputValidate::ReadString());

    cout << "\nEnter Email: ";
    Client.SetEmail(clsInputValidate::ReadString());

    cout << "\nEnter Phone: ";
    Client.SetPhone(clsInputValidate::ReadString());

    cout << "\nEnter PinCode: ";
    Client.SetPinCode(clsInputValidate::ReadString());

    cout << "\nEnter Account Balance: ";
    Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
}

void UpdateClient() {
    std::string AccountNumber = "";

    std::cout << "\nPlease Enter client Account Number: ";
    AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    std::cout << "\n\nUpdate Client Info:";
    std::cout << "\n____________________\n";

    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = Client1.Save();

    switch (SaveResult) {
        case clsBankClient::enSaveResults::svSucceeded: {
            cout << "\nAccount Updated Successfully :-)\n";
            Client1.Print();
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject: {
            cout << "\nError account was not saved because it's Empty";
            break;
        }
    }
}

void AddNewClient() {
    string AccountNumber = "";

    std::cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber)) {
        std::cout << "\nAccount Number Is Already Used, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult) {
        case clsBankClient::enSaveResults::svSucceeded: {
            std::cout << "\nAccount Addeded Successfully :-)\n";
            NewClient.Print();
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject: {
            std::cout << "\nError account was not saved because it's Empty";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists: {
            std::cout << "\nError account was not saved because account number is used!\n";
            break;
        }
    }
}

void DeleteClient() {
    std::string AccountNumber = "";

    std::cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber)) {
        std::cout << "\nAccountNumber is not found, choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    std::cout << "\nAre you sure you want to delete this client y/n? : ";

    char Answer = 'n';

    std::cin >> Answer;

    if (Answer == 'y' || Answer == 'Y') {
        if (Client1.Delete()) {
            std::cout << "\nClient Deleted Successfully\n";

            Client1.Print();
        } else {
            std::cout << "\nError Client Was not Deleted\n";
        }
    }
}

void ShowClientList() {
    std::vector<clsBankClient> vClients = clsBankClient::GetClientList();

    PrintTableHeader();

    if (vClients.size() == 0) {
        std::cout << "\t\t\tNo Clients Avilable In the System!";
    } else {
        for (clsBankClient Client : vClients) {
            PrintClientRecordLine(Client);
        }
    }
    std::cout << clsUtility::RepeatChar('-', 116) << "\n";
}

int main() {
    ShowClientList();

    return 0;
}