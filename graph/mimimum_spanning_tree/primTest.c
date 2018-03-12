/*************************************************************************
	> File Name: primTest.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月12日 星期一 10时09分01秒
 ************************************************************************/

#include<stdio.h>
#include"prim.h"


int main(){

    int vertexNum;
    int edgeNum;
    int u,v,w;
    ifstream in("data.txt");
    in >> vertexNum >> edgeNum;
    graph_adj.assign(vertexNum, list<Node>());
    /*for(int i=0; i<vertexNum; i++){
        graph_adj[i].push_back(Node(i,0));   
    }*/
    for(int i=0; i<edgeNum; i++){
        in >> u >> v >> w;
        graph_adj[u].push_back(Node(v,w));
        graph_adj[v].push_back(Node(u,w));
    }
    MST_Prim(0);

    in.close();
    return 0;
}
