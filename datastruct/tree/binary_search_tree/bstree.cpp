/*************************************************************************
	> File Name: bstree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月24日 星期五 11时05分39秒
 ************************************************************************/

#include<iostream>
#include"bstree.h"
using namespace std;

int main(){
    BsTree<int> bstree;

    
    bstree.TreeInsert(3);
    bstree.TreeInsert(1);
    bstree.TreeInsert(4);
    bstree.TreeInsert(2);
    bstree.TreeInsert(5);
    bstree.TreeInsert(7);
    bstree.TreeInsert(15);
    bstree.TreeInsert(3);
    bstree.TreeInsert(6);

    bstree.Traverse();
    
    Node<int> *x=bstree.Search(5);
    if(x==nullptr){
        cout<<"search error!"<<endl;
    }else{
        cout<<"find:"<<x->key<<endl;
        cout<<"predecessor"<<bstree.TreePredecessor(x)->key<<endl;
        cout<<"successor"<<bstree.TreeSuccessor(x)->key<<endl;
    }
    
    cout<<"TreeMax:"<<bstree.Max()->key<<endl;
    cout<<"TreeMin:"<<bstree.Min()->key<<endl;

    bstree.TreeDelete(x);
    
    bstree.Traverse();
    return 0;
}
