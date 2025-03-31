#include "Libraries/clsDblLinkedList.h"
#include "Libraries/clsQueue.h"
#include <iostream>
int main() {
    clsMyQueue<int> MyQueue;

    MyQueue.push(1);
    MyQueue.push(2);
    MyQueue.push(3);
    MyQueue.push(4);
    MyQueue.push(5);
    MyQueue.Print();

    MyQueue.updateItem(2, 10);
    MyQueue.Print();

    MyQueue.clear();
    MyQueue.Print();

    return 0;
}