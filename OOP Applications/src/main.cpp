#include "../Libaries/clsUtility.h"

int main() {
    clsUtil::Srand();
    int random = clsUtil::RandomNumber(1, 100);

    std::cout << random << std::endl;

    return 0;
}