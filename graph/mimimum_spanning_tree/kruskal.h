/*************************************************************************
	> File Name: kruskal.h
	> Author: 
	> Mail: 
	> Created Time: 2018年03月06日 星期二 10时01分09秒
 ************************************************************************/

#ifndef _KRUSKAL_H
#define _KRUSKAL_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "../../disjiontset/disjiontset.h"

using namespace std;

struct Edge{
    int u;
    int v;
    int w;
    friend bool operator<(const Edge &e1, const Edge &e2)
    {
        return e1.w < e2.w;
    }
};
using NodeType = DisjointSetNode<int>;

void kruskal(vector<Edge> &edges, int n)
{
    shared_ptr<NodeType> node[n];
    vector<Edge> SpanTree;
    
    for(int i=0; i<n; i++){
        node[i] = make_shared<NodeType>(i);  
        NodeType::make_set(node[i]);
    }

    sort(edges.begin(), edges.end());
/*    for (int i=0; i<edges.size(); i++){
        cout<<edges[i].w;
    }
    cout<<endl;*/

    for(int i=0; i<edges.size(); i++ ){
        if(NodeType::find_set(node[edges[i].u]) != NodeType::find_set(node[edges[i].v])){
            cout<<"edges["<<i<<"]"<<endl;
            SpanTree.push_back(edges[i]);
            NodeType::union_set(node[edges[i].u], node[edges[i].v]);
        }
    }
    
    cout<<"Edges:\n";

    for(int i = 0; i<SpanTree.size(); i++){
        cout<<SpanTree[i].u << SpanTree[i].v << SpanTree[i].w<< endl;
    }
    
}


#endif
