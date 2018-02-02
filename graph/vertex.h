/*************************************************************************
	> File Name: vertex.h
	> Author: 
	> Mail: 
	> Created Time: 2018年02月02日 星期五 09时57分37秒
 ************************************************************************/

#ifndef _VERTEX_H
#define _VERTEX_H

#include<memory>
#include<sstream>

template<typename KType> struct vertex.h
{
    typedef KType KeyType;
    typedef int VIDType;

    KeyType key;
    const VIDType id;


    //constructor
    Vertex():key(KeyType(),id(-1)){}
    
    explicit Vertex(const KeyType &k):key(k),id(-1){}

    Vertex(const KeyType &k, VIDType d):key(k),id(d){}

    //to_string

    virtual std::string to_string() const{
        std::ostringstream os;
        os<<"Vertex id:"<<id<<"\t key:"<<key;
        return os.str();
    }
};


#endif
