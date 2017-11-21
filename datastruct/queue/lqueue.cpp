/*************************************************************************
	> File Name: lqueue.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月21日 星期二 20时22分48秒
 ************************************************************************/

#include<iostream>
#include"lqueue.h"
using namespace std;

int main(){
    CLQueue<int> queue;

    queue.EnQueue(1);
    queue.EnQueue(2);
    queue.EnQueue(3);

    while(!queue.IsEmpty()){
        cout<<queue.DeQueue()<<endl;
    }
}

