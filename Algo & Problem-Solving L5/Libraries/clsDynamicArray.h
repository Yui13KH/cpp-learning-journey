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
};
