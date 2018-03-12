/*************************************************************************
	> File Name: prim.h
	> Author: 
	> Mail: 
	> Created Time: 2018年03月12日 星期一 10时08分51秒
 ************************************************************************/

#ifndef _PRIM_H
#define _PRIM_H

#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<queue>
//#include<../../disjiontset/disjiontset.h>

using namespace std;

struct Node{
    int u;
    int w;
    int key;
    int parent;
    bool isInQ;
    Node(int nodeId, int weight, int keyValue = 1000):u(nodeId),w(weight),key(keyValue),parent(-1),isInQ(true){};
    friend bool operator<(const Node &n1, const Node &n2)
    {
        return n1.key>n2.key;
    }
};

struct Edge{
    int u;
    int v;
    int w;
    Edge(int node1, int node2, int weight):u(node1), v(node2),w(weight){};
};

vector<list<Node>> graph_adj;
bool popQ[50]={0};
void MST_Prim(int root){

    vector<Edge> SpanTree;
    priority_queue<Node> Q;
    Q.push(Node(root, 0, 0));

    while(!Q.empty()){
        Node node = Q.top();
        Q.pop();
        if(popQ[node.u] == 1) continue;

        if(node.parent!=-1)
            SpanTree.push_back(Edge(node.u, node.parent, node.w));
        
        popQ[node.u] = 1;
        for(auto &it:graph_adj[node.u]){
            if(popQ[it.u]==0 && it.w < it.key){
                it.parent = node.u;
                it.key = it.w;
                Q.push(it);
            }
        }
    }

    /*
    for(int i=0;i<graph_adj.size();i++){
        for(auto it:graph_adj[i]){
            if(it.parent != -1){

            
            SpanTree.push_back(Edge(it.parent, it.u, it.w));
            }
        }
    }*/

    cout<<"Edges:\n";

    for(int i = 0; i<SpanTree.size(); i++){
        cout<<SpanTree[i].u << SpanTree[i].v << SpanTree[i].w<< endl;
    }


}

#endif
