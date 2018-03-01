/*************************************************************************
	> File Name: disjiontset.h
	> Author: 
	> Mail: 
	> Created Time: 2018年03月01日 星期四 10时47分59秒
 ************************************************************************/

#ifndef _DISJIONTSET_H
#define _DISJIONTSET_H

#include <memory>
#include <vector>

template<typename KType> struct DisjointSetNode
{
    typedef KType keyType;

    keyType value;
    int rank;
    std::shared_ptr<DisjointSetNode> parent;

    explicit DisjointSetNode(keyType v):value(v) {}

    static std::shared_ptr<DisjointSetNode> find_set(std::shared_ptr<DisjointSetNode> node)
    {
        if(!node){
            throw std::invalid_argument("find_set error:node must not be nullptr!");
        }
        if(node != node->parent){
            node->parent = find_set(node->parent);
        }
        return node->parent;
    }

    static void make_set(std::shared_ptr<DisjointSetNode> node)
    {
        if(node){
            node->parent = node;
            node->rank = 0;
        }else{
            throw std::invalid_argument("make_set error:node must not be nullptr!");
        }
    }

    static void link_set(std::shared_ptr<DisjointSetNode> nodeX, std::shared_ptr<DisjointSetNode> nodeY)
    {
        if(!nodeX || !nodeY){
            return;
        }
        
        if(nodeX != nodeX->parent || nodeY != nodeY->parent){
            throw std::invalid_argument("link_set error: node must be root node of the set!");
        }

        if (nodeX->rank>nodeY->rank){
            nodeY->parent = nodeX;
        }else{
            nodeX->parent = nodeY;
            if(nodeX->rank == nodeY->rank){
                nodeY->rank++;
            }
        }
    }

    static void union_set(std::shared_ptr<DisjointSetNode> nodeX, std::shared_ptr<DisjointSetNode> nodeY)
    {
        link_set(find_set(nodeX), find_set(nodeY));
    }
};


#endif
