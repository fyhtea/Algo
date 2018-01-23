/*************************************************************************
	> File Name: listGraph.h
	> Author:    fyhtea 
	> Mail:      fyhtea@hotmail.com
	> Created Time: 2018年01月22日 星期一 20时41分30秒
 ************************************************************************/

#ifndef _LISTGRAPH_H
#define _LISTGRAPH_H

#include <iostream>
#include <vector>
#include <array>
using namespace std;

template<unsigned N> 
struct AdjListGraph{
    typedef int VertexType;
    typedef int WeightType;
    typedef std:tuple<VertexType, VertexType, WeightType> EdgeType;
    typedef std::array<std::vector<std::pair<VertexType, WeightType>>,N> AdjGraphType;
    
    static const unsigned NUM = N;
    AdjGraphType array;

    
    void add_edge(const EdgeType &edge_tuple){
        auto id1 = std::get<0>(edge_tuple);
        auto id2 = std::get<1>(edge_tuple);
        auto w = std::get<2>(edge_tuple);
        if(id1<0||id1>=N||id2<0||id2>=N){
            return;
        }
        if(has_edge(id1, id2)){
            throw std::invalid_argument("edge add error,edge has already exist.");
        }
        array.at(id1).push_back(std::make_pair(id2, w));
    }

    void adjust_edge(VertexType id1, VertexType id2, WeightType w){
        if(id1<0||id1>=N||id2<0||id2>=N){
            return;
        }
        if(!has_edge(id1, id2)){
            throw std::invalid_argument("edge adjust error,edge dose not exist.");
        }
        auto &vec = array.at(id1); //应用类型，要修改。
        for(auto& pair:vec){
            if(pair.first == id2){
                pair.second=2;
                break;
            }
        }
    }

    bool has_edge(VertexType id_from, VertexType id_to) const 
    {
        if(id_from<0||id_from>=N||id_to<0||id_to>=N){
            throw std::invalid_argument("has_edge: id_from and id_to must belong to [1,N).");
        }
        const auto &vec = array.at(id_from);
        for(const auto &pair:vec){
            if(pair.first == id_to){
                return true;
            }
        }
        return false;
    }

    WeightType weight(VertexType id_from, VertexType id_to) const
    {
        if(has_edge(id_from, id_to)){
            const auto &vec = array.at(id_from);
            for(const auto &pair:vec){
                if(pair.first == id_to){
                    return pair.second;
                }
            }
        }else{
            throw std::invalid_argument("weight error:the edge dose not exist.");
        }
    }

    const std::vector<EdgeType> edge_tuples() const
    {
        std::vector<EdgeType> result;

        for(unsigned i = 0; i<N; i++){
            for(const auto& pair:array.at(i)){
                result.push_back(std::make_tuple(i, pair.first. pair.second));
            }
        }
        return result;
    }
    
    const std::vector<EdgeType> vertex_edge_tuples(VertexType id) const
    {
        if(id<0||id>=N){
            throw std::invalid_argument("vertex_edge_tuples error:id must belong to [0, N).");
        }
        std::vector<EdgeType> result;

        for(const auto &pair:array.at(id)){
            result.push_back(std::make_tuple(id, pair.first, pair.second));
        }
        return result;
    }
};

    

#endif
