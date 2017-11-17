/*************************************************************************
	> File Name: slist.h
	> Author: fyhtea 
	> Mail:   fyhtea@gmail.com
	> Created Time: 2017年11月13日 星期一 19时34分51秒
 ************************************************************************/

#ifndef _SLIST_H
#define _SLIST_H
#endif

#include <assert.h>

template<typename T>
class CNode
{
public:
    T data;
    CNode<T> *next;
    CNode():data(T()), next(nullptr) {}
    CNode(const T &initdata):data(initdata),next(nullptr) {}
    CNode(const T &initdata, CNode<T> *p):data(initdata),next(p) {}
};

template<typename T>
class CSList
{
protected:
    int m_nCount;
    CNode<T> *m_pNodeHead;

public:
    CSList();
    CSList(const T &initdata);
    ~CSList();

public:
    int IsEmpty() const;
    int GetCount() const;
    int InsertBefore(const int pos, const T data);
    int InsertAfter(const int pos, const T data);
    int AddHead(const T data);
    int AddTail(const T data);
    void RemoveAt(const int pos);
    void RemoveHead();
    void RemoveTail();
    void RemoveAll();
    T& GetTail();
    T  GetTail() const;
    T& GetHead();
    T  GetHead() const;
    T& GetAt(const int pos);
    T  GetAt(const int pos) const;
    void SetAt(const int pos, T data);
    int Find(const T data) const;
};

template<typename T>
inline  CSList<T>::CSList():m_nCount(0),m_pNodeHead(nullptr){}

template<typename T>
inline  CSList<T>::CSList(const T &initdata):m_nCount(0),m_pNodeHead(nullptr){
    AddHead(initdata);
}

template<typename T>
inline CSList<T>::~CSList(){
    RemoveAll();
}

template<typename T>
inline int CSList<T>::IsEmpty() const{
    return 0==m_nCount;
}

template<typename T>
inline CSList<T>::AddHead(const T data){
    CNode<T> *pNewNode;

    pNewNode=new CNode<T>;
    if(pNewNode==nullptr){return 0;}

    pNewNode->data=data;
    pNewNode->next=m_pNodeHead;

    m_pNodeHead = pNewNode;
    ++m_nCount;

    return 1;
}

template<typename T>
inline int CSList<T>::AddTail(const T data){
    return InsertAfter(GetCount(), data);
}

template<typename T>
inline int CSList<T>::InsertBefore(const int pos, const T data){
    
    CNode<T> *pNewNode;
    pNewNode = new CNode<T>;
    pNewNode->data = data;

    int nRetpos=0;
    if(pNewNode == nullptr) return nRetpos;

    if(IsEmpty()){
        pNewNode->next = nullptr;
        m_pNodeHead = pNewNode;
        nRetpos = 1;
        return nRetpos;
    }

    if(pos==1){
        AddHead(data);
        nRetpos = 1;
        return nRetpos;
    }

    CNode<T> *pTmpNode1;
    CNode<T> *pTmpNode2;
    pTmpNode1 = m_pNodeHead;
    for(int i=1; i<pos; i++){
        pTmpNode2 = pTmpNode1;
        pTmpNode1 = pTmpNode1->next;
    }
    pNewNode->next = pTmpNode1;
    pTmpNode2->next = pNewNode;

    nRetpos = pos;
    m_nCount++;
    return nRetpos;
}

template<typename T>
inline int CSList<T>::InsertAfter(const int pos, const T data){
    int i;
    int nRetpos=0;
    CNode<T> *pTmpNode;
    CNode<T> *pNewNode;

    pNewNode = new CNode<T>;
    if(pNewNode==nullptr) return nRetpos;

    pNewNode->data = data;

    if(m_pNodeHead==nullptr){
        pNewNode->next = nullptr;
        m_pNodeHead = pNewNode;
        nRetpos = 1;
        m_nCount++;
        return nRetpos;
    }
    
    assert(1<=pos && pos<=m_nCount);

    pTmpNode = m_pNodeHead;
    for(i=0; i<pos; i++){
        pTmpNode = pTmpNode->next;
    }

    pNewNode->next = pTmpNode->next;
    pTmpNode->next = pNewNode;

    nRetpos = pos+1;

    m_nCount++;

    return nRetpos;
    
}


template<typename T>
inline int CSList<T>::GetCount() const {
    return m_nCount;
}

template<typename T>
inline void CSList<T>::RemoveAt(const int pos){
    assert(pos>=1 && pos <= m_nCount);

    int i;
    CNode<T> *pTmpNode1;
    CNode<T> *pTmpNode2;
    pTmpNode1 = m_pNodeHead;

    if(pos == 1){
        m_pNodeHead = m_pNodeHead->next;
        delete pTmpNode1;
        m_nCount--;
        return;
    }

    for(i=1;i<pos;i++){
        pTmpNode2 = pTmpNode1;
        pTmpNode1 = pTmpNode1->next;
    }
    pTmpNode2->next=pTmpNode1->next;
    m_nCount--;
    delete pTmpNode1;
    return;
}

template<typename T>
inline void CSList<T>::RemoveHead(){
    assert(m_nCount!=0);

    RemoveAt(1);
}

template<typename T>
inline void CSList<T>::RemoveTail(){
    assert(m_nCount!=0);
    
    RemoveAt(m_nCount);
}

template<typename T>
inline void CSList<T>::RemoveAll(){
    CNode<T> *pTmpNode;
    pTmpNode = m_pNodeHead;

    for(int i=0; i<m_nCount; i++){
        pTmpNode = m_pNodeHead->next;
        delete m_pNodeHead;
        m_pNodeHead = pTmpNode;
    }
    m_nCount = 0;
}

template<typename T> 
inline T& CSList<T>::GetTail(){
    assert(m_nCount!=0);

    CNode<T> *pTmpNode = m_pNodeHead;

    for(int i=1; i<m_nCount; i++){
        pTmpNode = pTmpNode->next;
    }

    return pTmpNode->data;
}


template<typename T>
inline T CSList<T>::GetTail() const{
    assert(m_nCount!=0);

    CNode<T> *pTmpNode = m_pNodeHead;

    for(int i=1;i<m_nCount;i++){
        pTmpNode=pTmpNode->next;
    }
    return pTmpNode->data;
}



template<typename T>
inline T& CSList<T>::GetHead(){
    assert(m_nCount!=0);

    return m_pNodeHead->data;
}

template<typename T>
inline T CSList<T>::GetHead() const{
    assert(m_nCount!=0);

    return m_pNodeHead->data;
}

template<typename T>
inline T& CSList<T>::GetAt(const int pos){
    
    assert(m_nCount!=0 && pos<=m_nCount);
    CNode<T> *pTmpNode = m_pNodeHead;

    for(int i=1; i<pos; i++){
        pTmpNode = pTmpNode->next;
    }
    return pTmpNode->data;
}

template<typename T>
inline T CSList<T>::GetAt(const int pos) const
{
    assert(1 <= pos && pos <= m_nCount);

    int i;
    CNode<T> *pTmpNode = m_pNodeHead;

    for (i = 1; i < pos; ++i)
    {
        pTmpNode = pTmpNode->next;
    }

    return pTmpNode->data;
}


template<typename>
inline void CSList<T>::SetAt(const int pos, T data){
    assert(m_nCount!=0;pos<=m_nCount);
    
    CNode<T> *pTmpNode = m_pNodeHead;

    for(int i=1;i<pos;i++){
        pTmpNode=pTmpNode->next;
    }

    pTmpNode->data = data;
}

template<typename T>
inline int CSList<T>::Find(const T data) const{
    CNode<T> *pTmpNode=m_pNodeHead;

    for(int i=0;i<m_nCount;i++){
        if(pTmpNode->data==data){
            return i+1;
        }
        pTmpNode=pTmpNode->next;
    }
    return 0;
}
