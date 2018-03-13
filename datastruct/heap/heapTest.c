/*************************************************************************
	> File Name: heapTest.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月13日 星期二 15时29分12秒
 ************************************************************************/

#include<stdio.h>
#include"heap.h"

int main(){
    int arr[10];
    arr[0] = 16;
    arr[1] = 4;
    arr[2] = 10;
    arr[3] = 14;
    arr[4] = 7;
    arr[5] = 9;
    arr[6] = 3;
    arr[7] = 2;
    arr[8] = 8;
    arr[9] = 1;
    
    MaxHeap<int> maxheap(arr, 10);
    maxheap.show_heap();
    return 0;
}
    
