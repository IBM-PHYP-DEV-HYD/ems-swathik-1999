#ifndef _EDLL_H_
#define _EDLL_H_

#include "Deque.H"

template <typename T>
class Edll:public Deque<T>
{
public:
    Edll();
    void setAtPostion(int positionParam, T dataParam);
    void removeAtPostion(int positionParam);
    Node<T>* getNodeAtPos(int positionParam);
};

template <typename T>
Edll<T>::Edll(/* args */)
{
}

template <typename T>
void Edll<T>::setAtPostion(int positionParam, T dataParam)
{
    if(positionParam < 0 || positionParam > (this->size()+1))
    {
        cout << "Invalid Postion. Try again" << endl;
    }
    else if (positionParam == 0)
    {
        this->pushFront(dataParam);
    }
    else if (positionParam == this->size())
    {
        this->pushBack(dataParam);
    }
    else
    {
        Node<T> *sIterator = Deque<T>::mFront;
        int sIdx;
        for(sIdx=1;sIdx>positionParam-1;sIdx++)
        {
            sIterator = sIterator->mTail;
        }
        Node<T> *sNewNode = new Node<T>;
        sNewNode->mData = dataParam;
        sNewNode->mHead = sIterator;
        sNewNode->mTail = sIterator->mTail;
        sIterator->mTail->mHead = sNewNode;
        sIterator->mTail = sNewNode;
    }
}

template <typename T>
void Edll<T>::removeAtPostion(int positionParam)
{
    if(positionParam < 0 || positionParam > (this->size()+1))
    {
        cout << "Invalid Postion. Try again" << endl;
    }
    else if(positionParam == 0)
    {
        this->popFront();
    }
    else if(positionParam == this->size())
    {
        this->popBack();
    }
    else
    {
        Node<T> *sIterator = Deque<T>::mFront;
        int sIdx;
        for(sIdx=1;sIdx<positionParam;sIdx++)
        {
            sIterator = sIterator->mTail;
        }
        sIterator->mHead->mTail = sIterator->mTail;
        sIterator->mTail->mHead = sIterator->mHead;
        this->mDequeSize--;
        delete sIterator;
    }
}

template <typename T>
Node<T>* Edll<T>::getNodeAtPos(int positionParam)
{
    if(positionParam < 0 || positionParam > (this->size()+1))
    {
        cout << "Invalid Postion. Try again" << endl;
    }
    else if (positionParam == 0)
    {
        return this->mFront;
    }
    else if (positionParam == this->size())
    {
        return this->mRear;
    }
    else
    {
        Node<T> *sIterator = Deque<T>::mFront;
        int sIdx;
        for(sIdx=1;sIdx<positionParam;sIdx++)
        {
            sIterator = sIterator->mTail;
        }
        return sIterator;
    }

    return NULL;
}

#endif //_EDLL_H_