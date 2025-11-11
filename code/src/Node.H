// Doubly linked list node structure
template <typename T>

struct Node{
    T *mData;
    Node<T> *mPrev;
    Node<T> *mNext;
};