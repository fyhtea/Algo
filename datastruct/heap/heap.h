/*************************************************************************
	> File Name: heap.h
	> Author: 
	> Mail: 
	> Created Time: 2018年03月13日 星期二 11时23分47秒
 ************************************************************************/

#ifndef _HEAP_H
#define _HEAP_H

#include<iostream>
#include<assert.h>
using namespace std;

#define PARENT(i) (i-1)/2
#define LEFT(i) i*2+1
#define RIGHT(i) i*2+2
#define DEFAULT_SIZE 25

template <typename T> class Heap{
    
public:
    Heap() = default;
    virtual ~Heap() = default;

public:
    virtual void show_heap() const=0;
    virtual bool insert_heap(const T&) = 0;
    virtual bool remove_heap(T &) = 0;
};



template<typename T> class MaxHeap:public Heap<T>{

public:
    MaxHeap(int );
    MaxHeap(const T [], const int);
    ~MaxHeap();

public:
    bool insert_heap(const T&);  
    bool remove_heap(T &);  
    void show_heap() const;
    void heap_sort();

protected:
    void max_heapify(int i);
    void build_maxheap();
private:
    T *heap;
    int length;
    int heap_size;
};
template<typename T>
bool MaxHeap<T>::insert_heap(const T &elem)
{

}

template<typename T>
bool MaxHeap<T>::remove_heap(T &elem)
{
    
}

template<typename T>
MaxHeap<T>::MaxHeap(int size)
{
    length = DEFAULT_SIZE;
    heap = new T[length];
    assert(heap!=nullptr);
    heap_size = 0;
}

template<typename T>
MaxHeap<T>::MaxHeap(const T arr[], const int arrSize)
{
    length = DEFAULT_SIZE;
    heap = new T[length];
    assert(heap!=nullptr);
    heap_size = arrSize;

    for(int i=0;i<heap_size;i++){
        heap[i] = arr[i];
    }
    build_maxheap();
/*
    for(int i=heap_size/2-1;i>=0;i--){
        max_heapify(i);
    }
*/
}

template<typename T> 
MaxHeap<T>::~MaxHeap()
{
    delete []heap;
    heap = nullptr;
    length = heap_size = 0;
}

template<typename T> 
void MaxHeap<T>::max_heapify(int i){
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest=0;
    if (l<=heap_size && heap[l]>heap[i]){
        largest = l;
    }else{
        largest = i;
    }

    if(r<=heap_size && heap[r]>heap[largest]){
        largest = r;
    }

    if(largest != i){
   //    swap(heap[i], heap[largest]); //swap??
        T tmp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = tmp;
        max_heapify(largest);
    }
}

template<typename T> 
void MaxHeap<T>::build_maxheap(){
//    heap_size = length;
    for(int i=(heap_size-1)/2;i>=0;i--){
        max_heapify(i);
    }
}

template<typename T>
void MaxHeap<T>::show_heap() const
{
    for(int i=0;i<heap_size;i++){
        cout<<heap[i]<<endl;
    }
}

template<typename T> 
void MaxHeap<T> ::heap_sort(){
/*    build_maxheap();
    for(int i= length;i>=2;i--){
        swap(heap[1],heap[i]);
        heap_size--;
        max_heapify(1);
    }*/
}


#endif
