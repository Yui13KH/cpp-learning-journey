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
    Node* tail = nullptr;

    int getListSize() const { return _listSize; }
    void setListSize(int value) { _listSize = value; }

    void InsertAtBeginning(T value) {
        Node* newNode = new Node{value, head, nullptr};
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        _listSize++;
    }

    void PrintList() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    Node* Find(T value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->value == value) return current;
            current = current->next;
        }
        return nullptr;
    }

    void InsertAfter(Node* current, T value) {
        if (!current) return;
        Node* newNode = new Node{value, current->next, current};
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
        _listSize++;
    }

    bool InsertAfter(int index, T value) {
        Node* current = getNodeByIndex(index);
        if (current != nullptr) {
            InsertAfter(current, value);
            return true;
        } else {
            return false;
        }
    }

    void InsertAtEnd(T value) {
        Node* newNode = new Node{value, nullptr, tail};
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        _listSize++;
    }

    void DeleteNode(Node*& nodeToDelete) {
        if (!nodeToDelete) return;
        if (nodeToDelete == head) head = nodeToDelete->next;
        if (nodeToDelete == tail) tail = nodeToDelete->prev;

        if (nodeToDelete->next) nodeToDelete->next->prev = nodeToDelete->prev;
        if (nodeToDelete->prev) nodeToDelete->prev->next = nodeToDelete->next;

        delete nodeToDelete;
        nodeToDelete = nullptr;
        _listSize--;
    }

    void DeleteFirstNode() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
        _listSize--;
    }

    void DeleteLastNode() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
        _listSize--;
    }

    int Size() const { return _listSize; }

    bool IsEmpty() const { return head == nullptr; }

    void Clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        _listSize = 0;
    }

    void Reverse() {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    Node* getNodeByIndex(int index) {
        if (index < 0 || index >= _listSize) return nullptr;

        if (index < _listSize / 2) {
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            return current;
        } else {
            Node* current = tail;
            for (int i = _listSize - 1; i > index; i--) {
                current = current->prev;
            }
            return current;
        }  // simple optimization , goes to index from closer end
    }

    T getValueByIndex(int index) {
        Node* node = getNodeByIndex(index);

        if (node != nullptr) {
            return node->value;
        } else {
            return 0;
        }
    }

    bool UpdateValueByIndex(int index, T value) {
        Node* node = getNodeByIndex(index);
        if (node != nullptr) {
            node->value = value;
            return true;
        } else {
            return false;
        }
    }
};
