#include "./adjGraph.h"




int main(){
    graph_adj<int, int> graph(6);

    graph.insert_edge(0,1,1);
    graph.insert_edge(0,3,1);
    graph.insert_edge(3,1,1);
    graph.insert_edge(1,4,1);
    graph.insert_edge(4,3,1);
    graph.insert_edge(2,4,1);
    graph.insert_edge(2,5,1);
    graph.insert_edge(5,5,1);

    graph.print_graph();
    graph.bfs_search(0);
    graph.bfs_search(1);
}
