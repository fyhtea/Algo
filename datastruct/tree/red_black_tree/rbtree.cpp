/*************************************************************************
	> File Name: bstree.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月24日 星期五 11时05分39秒
 ************************************************************************/

#include<iostream>
#include"rbtree.h"
using namespace std;

int main(){
    RbTree<int> rbtree;
    
    rbtree.TreeInsert(3); 
    rbtree.TreeInsert(1);
    rbtree.TreeInsert(4);
    rbtree.TreeInsert(2);
    rbtree.TreeInsert(5);
    rbtree.TreeInsert(7);
//    rbtree.TreeInsert(15);
//    rbtree.TreeInsert(3);
//    rbtree.TreeInsert(6);

    rbtree.Traverse();
    
    //Node<int> *x=bstree.Search(5);
    //if(x==nullptr){
    //    cout<<"search error!"<<endl;
    //}else{
    //    cout<<"find:"<<x->key<<endl;
    //    cout<<"predecessor"<<bstree.TreePredecessor(x)->key<<endl;
    //    cout<<"successor"<<bstree.TreeSuccessor(x)->key<<endl;
    //}
    
    //cout<<"TreeMax:"<<bstree.Max()->key<<endl;
    //cout<<"TreeMin:"<<bstree.Min()->key<<endl;

    //bstree.TreeDelete(x);
    
    //bstree.Traverse();
    return 0;
}
