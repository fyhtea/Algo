/*************************************************************************
	> File Name: slist.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月17日 星期五 17时24分02秒
 ************************************************************************/

#include<iostream>
#include"slist.h"

using namespace std;


int main(){

    CSList<int> slist;

    slist.InsertAfter(slist.InsertAfter(slist.AddHead(1), 2), 3);
    slist.InsertAfter(slist.InsertAfter(slist.GetCount(), 4), 5);
    slist.InsertAfter(slist.GetCount(), 6);
    slist.AddTail(10);
    slist.InsertAfter(slist.InsertBefore(slist.GetCount(), 7), 8);
    slist.SetAt(slist.GetCount(), 9);
    slist.RemoveHead();
    slist.RemoveTail();

    int nCount=slist.GetCount();
    for(int i=0;i<nCount;i++){
        cout<<slist.GetAt(i+1)<<endl;
    }
}
