/*************************************************************************
	> File Name: stack.h
	> Author: 
	> Mail: 
	> Created Time: 2017年11月21日 星期二 09时59分33秒
 ************************************************************************/

#ifndef _STACK_H
#define _STACK_H

#include "../list/slist.h"

template<typename T>
class CStack:public CSList<T>
{
    public:
    int push(T data);
    int pop(T *data = nullptr);
    int top(T *data) const;
};

template<typename T>
inline int CStack<T>::push(T data){
    return this->AddTail(data);
}

template<typename T>
inline int CStack<T>::pop(T *data){
    if(this->IsEmpty()){
        return 0;
    }

    if(data){
        top(data);
    }

    CSList<int>::RemoveTail();
    return 1;
}

template<typename T>
inline int CStack<T>::top(T *data) const{
    assert(data);

    if(this->IsEmpty()){
        return 0;
    }

    *data = this->GetTail();
    return 1;
}






#endif
