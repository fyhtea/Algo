/*************************************************************************
	> File Name: graph.h
	> Author: 
	> Mail: 
	> Created Time: 2018年02月02日 星期五 11时14分45秒
 ************************************************************************/

#ifndef _GRAPH_H
#define _GRAPH_H

template<unsigned N, typename VType> struct Graph
{
    typedef int VIDType;
    typedef int EWeightType;
    typedef std::tuple<VIDType, VIDType,EWeightType> EdgeTupleType;
    typedef Vtype VertexType;
    static const unsigned NUM=N;

    std::array<std::shared_ptr<VertexType>, N> vertexes;
    std::size_t next_empty_vertex;
    ADJListGraph<N> adjList;

    Graph():next_empty_vertex(0) {}

    VIDType add_vertex(const typename VertexType::KeyType &key)
    {
        while(next_empty_vertex<N && vertexes.at(next_empty_vertex)){
            next_empty_vertex++;
        }
        if(next_empty_vertex>=N){
            throw std::invalid_argument("add_vertex error:Graph Vertex is full, can not add vertex.");
        }

        VIDType v_id = next_empty_vertex;
        vertexes.at(next_empty_vertex)=std::make_shared<VertexType>(key, v_id);
        next_empty_vertex++;
        return v_id;
    }

    VIDType add_vertex(const typename VertexType::KeyType &key, VIDType id)
    {
        if(id<0 || id>=N){
            throw std::invalid_argument("add_vertex error, id must>=0 || <N.");
        }
        if(vertexes.at(id)){
            throw std::invalid_argument("add_vertex error, vertex of id has existed.");
        }

        vertexes.at(id) = make_shared<VertexType>(key, id);
        return id;
    }

    void modify_vertex(const typename VertexType::KeyType &newkey, VIDType id)
    {
        if(id<0 || id>=N){
            throw  std::invalid_argument("modify_vertex error:id must >=0 and <N.");
        }
        if(vertexes.at(id)){
throw std::invalid_argument("modify_vertex error: vertex of id does not exist.");
        }
        vertexes.at(id)->key=newkey;
    }

    //add edge

};
#endif
