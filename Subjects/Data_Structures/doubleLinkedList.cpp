#pragma once
#include <iostream>

template <typename T>
class clsDblLinkedList {
   private:
    class Node {
       public:
        T value;
        Node* next;
        Node* prev;

        Node(T val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;

   public:
    clsDblLinkedList() : head(nullptr), tail(nullptr) {}

    void InsertAtBeginning(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void InsertAtEnd(T value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* Find(T value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void InsertAfter(T searchValue, T newValue) {
        Node* target = Find(searchValue);
        if (target == nullptr) {
            std::cout << "Node with value " << searchValue << " not found.\n";
            return;
        }

        Node* newNode = new Node(newValue);
        newNode->next = target->next;
        newNode->prev = target;

        if (target->next != nullptr) {
            target->next->prev = newNode;
        } else {
            tail = newNode;
        }

        target->next = newNode;
    }

    void InsertBefore(T searchValue, T newValue) {
        Node* target = Find(searchValue);
        if (target == nullptr) {
            std::cout << "Node with value " << searchValue << " not found.\n";
            return;
        }

        Node* newNode = new Node(newValue);
        newNode->next = target;
        newNode->prev = target->prev;

        if (target->prev != nullptr) {
            target->prev->next = newNode;
        } else {
            head = newNode;
        }

        target->prev = newNode;
    }

    void DeleteFirst() {
        if (head == nullptr) {
            std::cout << "The list is already empty.\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    void DeleteLast() {
        if (tail == nullptr) {
            std::cout << "The list is already empty.\n";
            return;
        }

        Node* temp = tail;
        tail = tail->prev;

        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
    }

    void DeleteNode(T value) {
        Node* target = Find(value);
        if (target == nullptr) {
            std::cout << "Node with value " << value << " not found.\n";
            return;
        }

        if (target == head) {
            DeleteFirst();
        } else if (target == tail) {
            DeleteLast();
        } else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
            delete target;
        }
    }

    void PrintList() {
        if (head == nullptr) {
            std::cout << "The list is empty.\n";
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " <-> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
};
