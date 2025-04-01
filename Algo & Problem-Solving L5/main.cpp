#include "Libraries/clsDblLinkedList.h"
#include "Libraries/clsQueue.h"
#include "Libraries/clsStack.h"
#include "Libraries/clsDynamicArray.h"
#include "Libraries/clsMyQueueArr.h"
#include "Libraries/clsMyStackArr.h"
#include <iostream>
int main() {
    clsMyStackArr<int> myStack;

    std::cout << "Stack created. Is it empty? " << (myStack.IsEmpty() ? "Yes" : "No") << "\n";

    std::cout << "Pushing 10, 20, 30 onto the stack...\n";
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Stack contents: ";
    myStack.Print();

    std::cout << "Top element: " << myStack.top() << "\n";
    std::cout << "Bottom element: " << myStack.bottom() << "\n";

    std::cout << "Popping an element...\n";
    myStack.pop();
    myStack.Print();

    std::cout << "Clearing stack...\n";
    myStack.clear();
    std::cout << "Stack cleared. Is it empty? " << (myStack.IsEmpty() ? "Yes" : "No") << "\n";

    return 0;
}