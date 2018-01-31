/*************************************************************************
	> File Name: adjGraph.h
	> Author: 
	> Mail: 
	> Created Time: 2018年01月27日 星期六 13时55分09秒
 ************************************************************************/

#ifndef _ADJGRAPH_H
#define _ADJGRAPH_H

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<array>


using namespace std;

template<typename VertexIDType, typename EdgeType>
class graph_adj{
	
	typedef int WeightType;

	public:
	graph_adj(int nums_V);
	//~graph_adj();

	public:
	bool insert_vertex(const VertexIDType &vertex);
	bool insert_edge(const VertexIDType &start, const VertexIDType &end, const WeightType &weight);
	void print_graph();

    //traverse
    void bfs_search(VertexIDType sourceID);
    void dfs_search(VertexIDType sourceID);
    private:
    //void dfs_visit(VertexIDType sourceID, int* vertex_color);


	private:
	int num_vertices;
	int num_edges;
	vector<vector<pair<VertexIDType, WeightType>>> adj_list;
};

template<typename VertexIDType, typename EdgeType>
graph_adj<VertexIDType, EdgeType>::graph_adj(int nums_V){
		adj_list.reserve(nums_V);
		for(int i = 0;i<nums_V;i++){
			vector<pair<VertexIDType, WeightType>> vec;
            vec.push_back(make_pair(i,0));   //node itself shoud be added?
			adj_list.push_back(vec);
		}
		num_vertices = nums_V;
}
/*
template<typename VertexIDType, typename EdgeType>
bool graph_adj<VertexIDType, EdgeType>::insert_vertex(const V &vertex){

}
*/
template<typename VertexIDType, typename EdgeType>
bool graph_adj<VertexIDType, EdgeType>::insert_edge(const VertexIDType &start, const VertexIDType &end, const WeightType &weight){
	auto &vec = adj_list[start];
	vec.push_back(make_pair(end, weight));
}

template<typename VertexIDType, typename EdgeType>
void graph_adj<VertexIDType,EdgeType>::print_graph(){
	for(int i=0;i<num_vertices;i++){
		for(auto pair:adj_list[i]){
			cout<<pair.first<<' ';
		}
		cout<<endl;
	}
}

template<typename VertexIDType, typename EdgeType>
void graph_adj<VertexIDType, EdgeType>::bfs_search(VertexIDType sourceID){
    
    int vertex_color[num_vertices]={0}; 
    queue<int> vertex_que;
    vertex_que.push(sourceID);


    while(!vertex_que.empty()){
        VertexIDType vertex = vertex_que.front();
        vertex_que.pop();

        for(auto pair:adj_list[vertex]){
            if (vertex_color[pair.first] == 0){
                cout<<pair.first<<"--->"; 
                vertex_color[pair.first] = 1;
    //            vertex_dist[pair.first] += 1;
    //            vertex_pi[pair.first] == vertex;
                vertex_que.push(pair.first);
            }
        }           
        vertex_color[vertex] = 2;
    }

    cout<<endl;

}

template<typename VertexIDType, typename EdgeType>
void graph_adj<VertexIDType, EdgeType>::dfs_search(VertexIDType sourceID){
    
    int vertex_color[num_vertices]={0};
    stack<VertexIDType> vertex_stack;
    vertex_stack.push(sourceID);
    vertex_color[sourceID] = 1;
    while(!vertex_stack.empty()){
        VertexIDType vertex = vertex_stack.top();
        vertex_stack.pop();
        cout<<vertex<<' ';
        for(auto pair:adj_list[vertex]){
            if (vertex_color[pair.first] == 0){
                vertex_color[pair.first] = 1;
                vertex_stack.push(pair.first);
            }    
        }
        vertex_color[vertex] = 2;
    }
}

#endif
