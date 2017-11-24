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

    bstree.Traverse();
    return 0;
}
