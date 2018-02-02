/*************************************************************************
	> File Name: adjlistgraph.h
	> Author: 
	> Mail: 
	> Created Time: 2018年02月02日 星期五 10时52分55秒
 ************************************************************************/

#ifndef _ADJLISTGRAPH_H
#define _ADJLISTGRAPH_H
#include<vector>
#include<array>

template<unsigned N> struct ADJListGraph
{
    typedef int VIDType;
    typedef int EWeightType;
    typedef std::tuple<VIDType, VIDType, EWeightType> EdgeTupleType;
    static const unsigned NUM = N;

    std::array<std::vector<std::pair<VIDType,EWeightType>>,N> array;



    void add_edge(const EdgeTupleType& edge_tuple)
    {
        auto id1=std::get<0>(edge_tuple);
        auto id2=std::get<1>(edge_tuple);
        auto wt=std::get<2>(edge_tuple);
        if(id1<0||id1>=N||id2<0||id2>=N)
            return;
        if(has_edge(id1,id2))
            throw std::invalid_argument("edge add error,edge has already exist.");
        array.at(id1).push_back(std::make_pair(id2,wt));
    }

    template<typename Iteator> void add_edges(const Iteator&begin ,const Iteator&end)
    {
        if(std::distance(begin,end)<=0)
            return;
        auto iter=begin;
        while(iter!=end)
        {
            add_edge(*iter);
            iter++;
        }
    }

void adjust_edge(VIDType id1,VIDType id2,EWeightType wt)
    {
        if(id1<0||id1>=N||id2<0||id2>=N)
            return;
        if(!has_edge(id1,id2))
            throw std::invalid_argument("edge adjust error,edge does not exist.");
        auto& vec=array.at(id1);  //这里必须用引用类型，因为要修改邻接表
        for(auto& pair:vec)
        {
            if(pair.first==id2)
            {
                pair.second=wt;
                break;
            }
        }
    } 

const std::vector<EdgeTupleType> edge_tuples() const
    {
        std::vector<EdgeTupleType> result;
        for(unsigned i=0;i<N;i++)
            for(const auto& pair:array.at(i))
            {
                result.push_back(std::make_tuple(i,pair.first,pair.second));
            }
        return result;
    }


const std::vector<EdgeTupleType> vertex_edge_tuples(VIDType id) const
{
    if(id<0||id>=N)
    {
        throw std::invalid_argument("vertex_edge_tuples: id must belongs [0,N),");
    }
    std::vector<EdgeTupleType> result;
    for(const auto& pair:array.at(id))
    {
        result.push_back(std::make_tuple(id,pair.first,pair.second));
    }
    return result;
}

bool has_edge(VIDType id_from,VIDType id_to) const
{
    if(id_from<0||id_from>=N||id_to<0||id_to>=N)
    {
        throw std::invalid_argument("has_edge: id_from  and id _to must belongs [0,N),");
    }
    const auto& vec=array.at(id_from);
    for(const auto& pair:vec)
    {
        if(pair.first==id_to)
            return true;
    }
    return false;
}

EWeightType weight(VIDType id_from,VIDType id_to) const
{
    if(has_edge(id_from,id_to))
    {
        const auto& vec=array.at(id_from);
        for(const auto& pair:vec)
        {
            if(pair.first==id_to)
                return pair.second;
        }
    }else
    {
        throw std::invalid_argument("weight error: the edge does not exist.");
    }
}

};
#endif
