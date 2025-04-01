#include "Libraries/clsDblLinkedList.h"
#include "Libraries/clsQueue.h"
#include "Libraries/clsStack.h"
#include <iostream>
int main() {
    clsMyStack<int> MyStack;

    for (int i = 1; i <= 5; i++) {
        MyStack.push(i);
    }
    MyStack.Print();

    MyStack.pop();
    MyStack.Print();

    std::cout << MyStack.top() << std::endl;
    std::cout << MyStack.Size() << std::endl;

}