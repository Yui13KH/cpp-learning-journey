#include "Libraries/clsDblLinkedList.h"
#include <iostream>
int main() {
    clsDblLinkedList<int> List;

    if (List.IsEmpty()) {
        std::cout << "\nlist is empty\n";
    } else {
        std::cout << "\nlist is not empty\n";
    }

    List.InsertAtBeginning(1);
    List.InsertAtBeginning(2);
    List.InsertAtBeginning(3);
    List.InsertAtBeginning(4);
    List.InsertAtBeginning(5);
    List.DeleteFirstNode();

    List.PrintList();
    std::cout << "list size: " << List.Size();

    if (List.IsEmpty()) {
        std::cout << "\nlist is empty\n";
    } else {
        std::cout << "\nlist is not empty\n";
    }

    List.Clear();

    std::cout << "list size: " << List.Size();
    return 0;
}