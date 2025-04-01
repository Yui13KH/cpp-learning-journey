#include "Libraries/clsDblLinkedList.h"
#include "Libraries/clsQueue.h"
#include "Libraries/clsStack.h"
#include "Libraries/clsDynamicArray.h"
#include <iostream>
int main() {
    clsDynamicArray<int> myArray(5);
    for (int i = 0; i < 5; i++) {
        myArray.SetItem(i, i + 1);
    }
    myArray.PrintList();

    myArray.Resize(3);
    myArray.PrintList();

    myArray.Resize(10);
    myArray.PrintList();
}