#pragma once

#include <iostream>
#include "clsDynamicArray.h"

template <class T>
class clsMyQueueArr {
   private:
    clsDynamicArray<T> _MyList;

   public:
    void push(T Item) { _MyList.InsertAtEnd(Item); }

    void pop() { _MyList.DeleteFirstItem(); }

    void Print() { _MyList.PrintList(); }

    int Size() { return _MyList.Size(); }

    bool IsEmpty() { return _MyList.IsEmpty(); }

    T front() { return _MyList.GetItem(0); }

    T back() { return _MyList.GetItem(Size() - 1); }

    // T getValueByIndex(int Index) { return _MyList.getValueByIndex(Index); }

    // void reverse() { _MyList.Reverse(); }

    // void updateItem(int Index, T NewValue) { _MyList.UpdateValueByIndex(Index, NewValue); }

    // void insertAfter(int Index, T NewValue) { _MyList.InsertAfter(Index, NewValue); }

    // void insertFront(T NewValue) { _MyList.InsertAtBeginning(NewValue); }

    // void insertBack(T NewValue) { _MyList.InsertAtEnd(NewValue); }

    // not really queue operations but just for demo

    void clear() { _MyList.Clear(); }
};