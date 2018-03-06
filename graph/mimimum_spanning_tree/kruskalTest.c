/*************************************************************************
	> File Name: kruskalTest.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月06日 星期二 10时38分15秒
 ************************************************************************/

#include<stdio.h>
#include"kruskal.h"
#include<fstream>

int main(){

    vector<Edge> edges;
    int vertexNum;
    int edgeNum;
    
    ifstream in("data.txt");
    in >> vertexNum >> edgeNum;
    edges.assign(edgeNum, Edge());

    for(int i=0; i<vertexNum; i++){
        in >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    kruskal(edges, vertexNum);

    return 0;
}
