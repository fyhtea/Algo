/*************************************************************************
	> File Name: disjiontsetTest.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月01日 星期四 11时03分00秒
 ************************************************************************/

#include<stdio.h>
#include<iostream>
#include"disjiontset.h"

#define nodeNums 20
using NodeType =  DisjointSetNode<int>;


int main(){

    // create nodes
    std::shared_ptr<NodeType> node[nodeNums];
    for(int i=0;i<nodeNums;i++){
        node[i] = std::make_shared<NodeType>(i); 
        NodeType::make_set(node[i]);
    }

//    NodeType::make_set(node[5]);
//    NodeType::make_set(node[6]);
    

    NodeType::union_set(node[5], node[6]);
    NodeType::union_set(node[1], node[5]);

    std::shared_ptr<NodeType> testnode =  NodeType::find_set(node[1]);
    std::cout<<testnode->value<<std::endl;
    return 0;
}
