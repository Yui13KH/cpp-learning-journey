#include <iostream>
#include <stack>

void printStack() {
    std::stack<int> stkNumbers;  // makes a stack of integers

    stkNumbers.push(10);  // adds 10 to the top of the stack
    stkNumbers.push(20);
    stkNumbers.push(30);
    stkNumbers.push(40);
    stkNumbers.push(50);  // last in , first one to get out

    std::cout << "count: " << stkNumbers.size() << std::endl;

    std::cout << "Numbers are : \n";
    while (!stkNumbers.empty()) {
        std::cout << stkNumbers.top() << std::endl;
        stkNumbers.pop();
    }
}

#include <iostream>
#include <stack>

void printStack(std::stack<int> s) {
    // Print and empty the stack
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}

void swapStacks() {
    std::stack<int> stack1, stack2;

    // Populate stack1
    for (int i = 10; i <= 50; i += 10) {
        stack1.push(i);
    }
    
    // Populate stack2
    for (int i = 60; i <= 100; i += 10) {
        stack2.push(i);
    }

    // Printing before swap
    std::cout << "Before swapping:" << std::endl;
    std::cout << "Stack1 top: " << stack1.top() << ", Stack2 top: " << stack2.top() << std::endl;

    std::cout << "Stack1 items: ";
    printStack(stack1);

    std::cout << "Stack2 items: ";
    printStack(stack2);

    // Swap the stacks
    stack1.swap(stack2);

    // Printing after swap
    std::cout << "After swapping:" << std::endl;
    std::cout << "Stack1 top: " << stack1.top() << ", Stack2 top: " << stack2.top() << std::endl;

    std::cout << "Stack1 items: ";
    printStack(stack1);

    std::cout << "Stack2 items: ";
    printStack(stack2);
}

// my thoughts about it is that its like a gun magazine but the bullets are values

int main() {
    swapStacks();

    return 0;
}
