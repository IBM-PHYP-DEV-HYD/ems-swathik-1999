#ifndef _EDLL_H_
#define _EDLL_H_

#include "Deque.H"

template <typename T>
class Edll:public Deque<T>
{
public:
    Edll();
    void setAtPostion(int postionParam, T dataParam);
    void removeAtPostion(int postionParam);
    T getNodeAtPostion(int postionParam);
};

template <typename T>
Edll<T>::Edll(/* args */)
{
}

template <typename T>
void Edll<T>::setAtPostion(int postionParam, T dataParam)
{
    if(postionParam<0 || postionParam>(mDequeSize+1))
    {
        cout << "Invalid Postion. Try again" << endl;
    }
    else if (postionParam==0)
    {
        this->pushFront(dataParam);
    }
    else if (postionParam==mDequeSize)
    {
        this->pushBack(dataParam);
    }
    else
    {
        Node<T> *sIterator = mFront;
        int sIdx;
        for(sIdx=0;sIdx==postionParam-1;sIdx++)
        {
            sIdx++;
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
void Edll<T>::removeAtPostion(int postionParam)
{
    if(postionParam<0 || postionParam>(mDequeSize+1))
    {
        cout << "Invalid Postion. Try again" << endl;
    }
    else if (positionParam==0)
    {
        this->popFront();
    }
    else if(positionParam==mDequeSize)
    {
        this->popBack();
    }
    else
    {
        Node<T> *sIterator = mFront;
        int sIdx;
        for(sIdx=0;sIdx==postionParam;sIdx++)
        {
            sIdx++;
            sIterator = sIterator->mTail;
        }
        sIterator->mHead->mTail = sIterator->mTail;
        sIterator->mTail->mHead = sIterator->mHead;
        delete sIterator;
    }
}

template <typename T>
T Edll<T>::getNodeAtPostion(int postionParam)
{
    if(postionParam<0 || postionParam>(mDequeSize+1))
    {
        cout << "Invalid Postion. Try again" << endl;
    }
    else if (positionParam==0)
    {
        return this->mFront->mData;
    }
    else if (positionParam==mDequeSize)
    {
        return this->mRear->mData;
    }
    else
    {
        Node<T> *sIterator = mFront;
        int sIdx;
        for(sIdx=0;sIdx==postionParam;sIdx++)
        {
            sIdx++;
            sIterator = sIterator->mTail;
        }
        return sIterator->mData;
    }
}

#endif //_EDLL_H_