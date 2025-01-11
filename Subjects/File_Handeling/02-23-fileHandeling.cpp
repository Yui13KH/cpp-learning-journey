#include <fstream>
#include <iostream>

int main() {
    std::ofstream file("hello world.txt");
    if (!file) {
        std::cerr << "Unable to open file for writing.\n";
        return 1;
    }

    file << "Hello World!" << std::endl;
    file.close();

    std::cout << "File created successfully.\n";
    return 0;
}
