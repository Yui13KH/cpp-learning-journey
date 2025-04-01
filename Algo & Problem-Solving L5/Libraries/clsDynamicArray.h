#pragma once

#include <iostream>

template <class T>
class clsDynamicArray {
   protected:
    int _Size = 0;

   public:
    T* OriginalArray;

    clsDynamicArray(int Size = 0) {
        if (Size < 0) Size = 0;

        _Size = Size;

        OriginalArray = new T[_Size];
    }

    ~clsDynamicArray() { delete[] OriginalArray; }

    bool SetItem(int index, T Value) {
        if (index >= _Size || _Size < 0) {
            return false;
        }

        OriginalArray[index] = Value;
        return true;
    }

    int Size() { return _Size; }

    bool IsEmpty() { return (_Size == 0 ? true : false); }

    void PrintList()

    {
        for (int i = 0; i <= _Size - 1; i++) {
            std::cout << OriginalArray[i] << " ";
        }

        std::cout << "\n";
    }

    void Resize(int NewSize) {
        if (NewSize <= 0) {  // if resizing is to zero
            delete[] OriginalArray;
            OriginalArray = nullptr;
            _Size = 0;
            return;
        }

        T* TempArray = new T[NewSize];                      // Allocate new array
        int MinSize = (NewSize < _Size) ? NewSize : _Size;  // if the new size is smaller

        for (int i = 0; i < MinSize; i++) {
            TempArray[i] = OriginalArray[i];
        }  // copy the elements of the original array

        delete[] OriginalArray;     // delete the original array
        OriginalArray = TempArray;  // set the original array to the new array
        _Size = NewSize;            // set the size
    }

    T GetItem(int index) {
        if (index < 0 || index >= _Size) {
            throw std::out_of_range("Index out of bounds");
        }
        return OriginalArray[index];
    }

    void Reverse() {
        int left = 0, right = _Size - 1;
        while (left < right) {
            std::swap(OriginalArray[left], OriginalArray[right]);
            left++;
            right--;
        }
    }

    void Clear() { Resize(0); }

    void DeleteItemAt(int index) {
        if (index < 0 || index >= _Size) {
            throw std::out_of_range("Index out of bounds");
        }

        for (int i = index; i < _Size - 1; i++) {
            OriginalArray[i] = OriginalArray[i + 1];
        }

        _Size--;  // deletion without copying , just shifting
    }

    void DeleteFirstItem() { DeleteItemAt(0); }

    void DeleteLastItem() { DeleteItemAt(_Size - 1); }

    void DeleteItemByValue(T Value) {
        int index = Find(Value);
        if (index != -1) {
            DeleteItemAt(index);
        }
    }

    T Find(T value) {
        for (int i = 0; i < _Size; i++) {
            if (OriginalArray[i] == value) {
                return i;
            }
        }
        return -1;
    }

    bool InsertAt(int index, T value) {
        if (index > _Size || index < 0) {
            return false;
        }

        Resize(_Size + 1);

        for (int i = _Size - 1; i > index; i--) {
            OriginalArray[i] = OriginalArray[i - 1];
        }

        OriginalArray[index] = value;

        return true;
    }

    void InsertAtBeginning(T value) { InsertAt(0, value); }

    void InsertAtEnd(T value) { InsertAt(_Size, value); }

    bool InsertBefore(int index, T value) {
        if (index <= 0 || index > _Size) {
            return false;
        }
        return InsertAt(index - 1, value);
    }

    bool InsertAfter(int index, T value) {
        if (index < 0 || index >= _Size - 1) {
            return false;
        }
        return InsertAt(index + 1, value);
    }
};
