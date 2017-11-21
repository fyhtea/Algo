/*************************************************************************
	> File Name: lqueue.h
	> Author: 
	> Mail: 
	> Created Time: 2017年11月21日 星期二 20时11分15秒
 ************************************************************************/

#ifndef _LQUEUE_H
#define _LQUEUE_H

#include "../list/slist.h"


template<typename T>
class CLQueue:public CSList<T>
{
    public:
    int EnQueue(const T data);
    T DeQueue();
    T& GetFront();
    T GetFront() const;
    T& GetRear();
    T GetRear() const;
};

template<typename T>
inline int CLQueue<T>::EnQueue(const T data){
    return CSList<T>::AddTail(data);
}

template<typename T>
inline T CLQueue<T>::DeQueue(){
    T data = this->GetHead();
    this->RemoveHead();
    return data;
}

template<typename T>
inline T& CLQueue<T>::GetFront(){
    return this->GetHead();
}

template<typename T>
inline T CLQueue<T>::GetFront() const{
    return this->GetHead();
}

template<typename T>
inline T& CLQueue<T>::GetRear(){
    return this->GetTail();
}

template<typename T>
inline T CLQueue<T>::GetRear() const{
    return this->GetTail();
}

#endif
