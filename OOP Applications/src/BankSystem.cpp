#include "../Libaries/clsUtility.h"
#include "../Libaries/clsDate.h"
#include "../Libaries/clsString.h"

int main() {
    clsUtility::Srand();
    int random = clsUtility::RandomNumber(1, 100);

    std::cout << random << std::endl;


    return 0;
}