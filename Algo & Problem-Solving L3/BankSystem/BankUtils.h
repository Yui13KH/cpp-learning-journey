#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

inline std::string DELIMITER = "#//#";  // makes it accesible in the BankUtils.cpp
// had multiple definitions error

// Define a namespace for the banking system
namespace BankUtils {

int getValidPositiveInt(const std::string& prompt);

// main functions

void bankManagementSystem(std::string FileName);
void showAllClients(const std::string& filename);
void AddClients(std::string filename, std::string delimiter = DELIMITER);
void DeleteClient(const std::string& FileName);
void FindClient(std::string Filename);
void handleClientUpdate(std::string FileName);
void Transactions(std::string FileName);


}  // namespace BankUtils

// well appearently i only need to define the ones i am calling in the main file
// the other function declerations can be kept in their Bank Utils file