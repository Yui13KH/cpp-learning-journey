#include "clsDblLinkedList.h"
#include <stack>

template <class T>
class clsMyStack {
   private:
    clsDblLinkedList<T> _list;

   public:
    void push(T Item) { _list.InsertAtEnd(Item); }
    void pop() { _list.DeleteLastNode(); }
    T top() { return _list.getValueByIndex(_list.Size() - 1); }
    T bottom() { return _list.getValueByIndex(0); }
    void Print() { _list.PrintList(); }
    int Size() { return _list.Size(); }
    bool IsEmpty() { return _list.IsEmpty(); }
    void clear() { _list.Clear(); }
};
