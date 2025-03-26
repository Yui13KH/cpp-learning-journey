#include <iostream>
#include <queue>

void printQueue(std::queue<int> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
}

void SimpleQueue() {
    std::queue<int> myQueue;

    for (int i = 10; i <= 50; i += 10) {
        myQueue.push(i);
    }

    std::cout << "\nCount: " << myQueue.size() << std::endl;
    std::cout << "\nFront " << myQueue.front() << std::endl;
    std::cout << "\nBack " << myQueue.back() << std::endl;

    std::cout << "\nQueue: \n";
    printQueue(myQueue);
}

void swapQueues() {
    std::queue<int> q1, q2;

    for (int i = 10; i <= 50; i += 10) {
        q1.push(i);
    }

    for (int i = 60; i <= 100; i += 10) {
        q2.push(i);
    }

    std::cout << "\nBefore swapping:\n";
    std::cout << "Queue 1: ";
    printQueue(q1);
    std::cout << "\nQueue 2: ";
    printQueue(q2);

    q1.swap(q2);

    std::cout << "\nAfter swapping:\n";
    std::cout << "Queue 1: ";
    printQueue(q1);
    std::cout << "\nQueue 2: ";
    printQueue(q2);
}

int main() {
    SimpleQueue();
    swapQueues();
    return 0;
}