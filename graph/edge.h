/*************************************************************************
	> File Name: edge.h
	> Author: 
	> Mail: 
	> Created Time: 2018年02月02日 星期五 10时43分17秒
 ************************************************************************/

#ifndef _EDGE_H
#define _EDGE_H
#include<tuple>
#include<memory>

template<typename VType> struct Edge
{
public:
    typedef int VIDType;
    typedef int EWeightType;
    typedef VType VertexType;
    typedef std::tuple<VIDType, VIDType, EWeightType> EdgeTupleType;

    std::shared_ptr<VertexType> vertex1;
    std::shared_ptr<VertexType> vertex2;
    EWeightType weight;

    Edge(std::shared_ptr<VertexType> v1, std::shared_ptr<VertexType> v2, EWeightType w):vertex1(v1),vertex2(v2),weight(w) {}

    virtual std::string to_string() const
    {
        std::ostringstream os;
        os<<"edge weight:"<<weight<<"\t vertex[id1"<<vertex1->id<<",id2"<<vertex2->id<<"]";
        return os.str();
    }

    const EdgeTupleType edge_tuple() const
    {
        return std::make_tuple(vertex1->id, vertex2->id, weight);
    }

};

#endif
