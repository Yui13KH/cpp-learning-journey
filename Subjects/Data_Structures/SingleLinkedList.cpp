#include <iostream>

class Node {
   public:
    int value;   // The part that have the value
    Node* next;  // Pointer to the next node in the list

    // Constructor to make a node
    Node(int val) {
        value = val;
        next = nullptr;  // Initially, the next pointer is set to nullptr
    }
};

class LinkedList {
   private:
    Node* head;  

   public:
    //constructor
    LinkedList() {
        head = nullptr;  // Initially, the list is empty
    }


    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);  // Create a new node
        newNode->next = head;           // Make the new node point to the current head
        head = newNode;                 // Make the head point to the new node
        std::cout << "Inserted " << val << " at the beginning\n";
    }


    bool find(int val) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == val) {
                return true;  // Value found
                std::cout << "Value " << val << " Found";
            }
            current = current->next;
        }
        return false;  // Value not found
        std::cout << "Value " << val << " Not Found";
    }


    void insertAfter(int prevVal, int newVal) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == prevVal) {
                Node* newNode = new Node(newVal);  
                newNode->next = current->next;     // New node points to the next node
                current->next = newNode;           // Current node points to the new node
                std::cout << "Inserted " << newVal << " after " << prevVal << "\n";
                return;
            }
            current = current->next;  // moves to the next node
        }
        std::cout << "Value " << prevVal << " not found in the list\n";
    }


    void insertAtEnd(int val) {
        Node* newNode = new Node(val);  
        if (head == nullptr) {          // If the list is empty, the new node is the head
            head = newNode;
            std::cout << "Inserted " << val << " at the end (list was empty)\n";
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {  // Traverse to the last node
            current = current->next;
        }
        current->next = newNode;  // Last node points to the new node
        std::cout << "Inserted " << val << " at the end\n";
    }


    void deleteNode(int val) {
        if (head == nullptr) {
            std::cout << "List is empty, cannot delete\n";
            return;
        }
        // If the head is the node to be deleted
        if (head->value == val) {
            Node* temp = head;  // Temporary pointer to hold the current head
            head = head->next;  // Move the head pointer to the next node
            delete temp;        // Delete the old head node
            std::cout << "Deleted node with value " << val << "\n";
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->value == val) {
                Node* temp = current->next;           // Node to be deleted
                current->next = current->next->next;  // Bypass the node
                delete temp;                          // Free memory of the deleted node
                std::cout << "Deleted node with value " << val << "\n";
                return;
            }
            current = current->next;
        }
        std::cout << "Value " << val << " not found in the list\n";
    }


    void deleteFirst() {
        if (head == nullptr) {
            std::cout << "List is empty, cannot delete\n";
            return;
        }
        Node* temp = head;
        head = head->next;  // Move head to the next node
        delete temp;        // Delete the old head
        std::cout << "Deleted the first node\n";
    }


    void deleteLast() {
        if (head == nullptr) {
            std::cout << "List is empty, cannot delete\n";
            return;
        }
        if (head->next == nullptr) {  // If there's only one node
            delete head;
            head = nullptr;
            std::cout << "Deleted the last node (it was the only node)\n";
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {  // Traverse to the second last node
            current = current->next;
        }
        delete current->next;     // Delete the last node
        current->next = nullptr;  // Set second last node's next to nullptr
        std::cout << "Deleted the last node\n";
    }


    void printList() {
        if (head == nullptr) {
            std::cout << "The list is empty\n";
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    // Destructor to free the memory 
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        std::cout << "List destroyed\n";
    }
};

int main() {
    LinkedList list;

    // Test insertions
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAfter(20, 25);

    list.printList();

    // Test deletions
    list.deleteNode(10);
    list.deleteFirst();
    list.deleteLast();

    list.printList();  // Expected: 25 -> nullptr

    return 0;
}