#pragma once
#include <iostream>

template <class T>
class clsDblLinkedList {
private:
    int _listSize = 0;

public:
    class Node {
    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = nullptr;

    void InsertAtBeginning(T value) {
        Node* newNode = new Node{ value, head, nullptr };
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
       _listSize++;
    }

    void PrintList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    Node* Find(T value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void InsertAfter(Node* current, T value) {
        if (!current) return;
        Node* newNode = new Node{ value, current->next, current };
        if (current->next != nullptr)
            current->next->prev = newNode;
        current->next = newNode;
       _listSize++;
    }

    void InsertAtEnd(T value) {
        Node* newNode = new Node{ value, nullptr, nullptr };
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
       _listSize++;
    }

    void DeleteNode(Node*& nodeToDelete) {
        if (!head || !nodeToDelete) return;
        if (head == nodeToDelete) head = nodeToDelete->next;
        if (nodeToDelete->next) nodeToDelete->next->prev = nodeToDelete->prev;
        if (nodeToDelete->prev) nodeToDelete->prev->next = nodeToDelete->next;
        delete nodeToDelete;
       _listSize--;
    }

    void DeleteFirstNode() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
       _listSize--;
    }

    void DeleteLastNode() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
        }
        else {
            Node* current = head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
       _listSize--;
    }

    int Size() const {
        return _listSize;
    }

    bool IsEmpty() {
        // Returns the result of the condition itself, which evaluates to true or false
        return head == nullptr;
    }

    void Clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        _listSize = 0;
    }

};
