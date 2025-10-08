#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "Utilities.H"

// Deque class definition
template <typename T>
class Deque
{
private:
    Node<T> *mFront;
    Node<T> *mRear;
    int mDequeSize;
   
public:
    Deque();
    Deque(int noOfElementsParam,T defaultValueParam);
    ~Deque();
    void pushBack(const T dataParam);
    void pushFront(const T dataParam);
    void popBack();
    void popFront();
    bool firstElement(T &valParam);
    bool lastElement(T &valParam);
    size_t size();
    void clearElements();
    void printElements();
    // void resize(size_t inputsizeParam,T defaultValueParam,int directionParam);
};

//Pushing element at the back of the deque
template <typename T>
void Deque<T>::pushBack(const T dataParam)
{
    Node<T> *mNewNode = new Node<T>;
    mNewNode->mData = dataParam;
    mNewNode->mTail = nullptr;

    if(mRear){
        mNewNode->mHead = mRear;
        mRear->mTail = mNewNode;
    }
    else{
        mNewNode->mHead = nullptr;
        mFront = mNewNode;
    }
    mRear = mNewNode;
    this->mDequeSize++;
}

//Pushing element at the front of the deque
template <typename T>
void Deque<T>::pushFront(const T dataParam)
{
    Node<T> *mNewNode = new Node<T>;
    mNewNode->mData = dataParam;
    mNewNode->mHead = nullptr;

    if(mFront){
        mNewNode->mTail = mFront;
        mFront->mHead=mNewNode;
    }
    else{
        mNewNode->mTail=nullptr;
        mRear=mNewNode;
    }
    mFront = mNewNode;
    this->mDequeSize++;
}

//Popping element from the back of the deque
template <typename T>
void Deque<T>::popBack()
{
    if(mRear){
        Node<T> *sIterator = mRear;
        mRear = sIterator->mHead;
        mRear->mTail = nullptr;
        delete sIterator;
        this->mDequeSize--;
    }
    else
    {
        std::cout << "Deque is empty" << std::endl;
    }
}

//Popping element from the front of the deque
template <typename T>
void Deque<T>::popFront()
{
    if(mFront){
        Node<T> *sIterator = mFront;
        mFront = sIterator->mTail;
        mFront->mHead = nullptr;
        delete sIterator;
        this->mDequeSize--;
    }
    else
    {
        std::cout << "Deque is empty" << std::endl;
    }
}

//Getting the first element of the deque
template <typename T>
bool Deque<T>::firstElement(T &valParam)
{
    if(mFront){
        valParam = mFront->mData;
        return true;
    }
    else
    {
        return false;
    }
}

//Getting the last element of the deque
template <typename T>
bool Deque<T>::lastElement(T &valParam)
{
    if(mRear){
        valParam = mRear->mData;
        return true;
    }
    else
    {
        return false;
    }
}

//Getting the size of the deque
template <typename T>
size_t Deque<T>::size()
{
    return this->mDequeSize;
}

//Clearing all the elements of the deque
template <typename T>
void Deque<T>::clearElements()
{
    while(mFront!=nullptr)
    {
        Node<T> *sIterator = mFront;
        mFront = mFront->mTail;
        delete sIterator;
    }
    mFront = nullptr;
    mRear = nullptr;
}

//Printing all the elements of the deque
template <typename T>
void Deque<T>::printElements()
{
    Node<T> *sIterator = mFront;
    if(nullptr == mFront)
    {
        std::cout << "Deque is empty." << std::endl << std::endl;
        return;
    }
    while(sIterator)
    {
        std::cout << " " << sIterator->mData;
        sIterator = sIterator->mTail;
    }
    std::cout << std::endl;
}

//Resizing the deque // Not Required for the Moment.
/*template <typename T>
void Deque<T>::resize(size_t inputsizeParam,T defaultValueParam,int directionParam)
{
    if(inputsizeParam > this->mDequeSize)
    {
        if(dm::forward == directionParam)
        {
            while(inputsizeParam != this->mDequeSize)
            {
                pushFront(defaultValueParam);
            }
        }
        else
        {
            while(inputsizeParam != this->mDequeSize)
            {
                pushBack(defaultValueParam);
            }
        }
    }
    else if(inputsizeParam < this->mDequeSize)
    {
        if(dm::forward == directionParam)
        {
            while(inputsizeParam != this->mDequeSize)
            {
                popFront();
            }
        }
        else
        {
            while(inputsizeParam != this->mDequeSize)
            {
                popBack();
            }
        }
    }
} */ // Not Required for the Moment.

//Non-Parameterised constructor
template <typename T>
Deque<T>::Deque()
{
    this->mFront = nullptr;
    this->mRear = nullptr;
    this->mDequeSize = 0;
}

//Parameterised constructor to create a deque with default values
template <typename T>
Deque<T>::Deque(int noOfElementsParam,T defaultValueParam):mFront(nullptr),mRear(nullptr),mDequeSize(0)
{
    int sIdx;
    for(sIdx=0;sIdx<noOfElementsParam;sIdx++)
    {
        pushBack(defaultValueParam);
    }
}

template <typename T>
Deque<T>::~Deque()
{
    while(this->mFront)
    {
        Node<T> *sIterator = this->mFront;
        this->mFront = this->mFront->mTail;
        delete sIterator;
    }
}

#endif //_DEQUE_H_