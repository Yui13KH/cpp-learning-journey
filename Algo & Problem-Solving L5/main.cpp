#include "Libraries/clsDblLinkedList.h"
#include "Libraries/clsQueue.h"
#include "Libraries/clsStack.h"
#include "Libraries/clsDynamicArray.h"
#include <iostream>
int main() {
    clsDynamicArray<int> myArray(10);
    for (int i = 1; i <= 10; i++) {
        myArray.SetItem(i, i + 1);
    }
    myArray.PrintList();

    myArray.InsertBefore(myArray.Size() , 159);

    myArray.PrintList();
;

    std::cout << myArray.Size() << std::endl;
}