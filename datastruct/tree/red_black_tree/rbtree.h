/*************************************************************************
	> File Name: rbtree.h
	> Author: 
	> Mail: 
	> Created Time: 2017年11月29日 星期三 10时13分00秒
 ************************************************************************/

#ifndef _RBTREE_H
#define _RBTREE_H
#include<iostream>
using namespace std;

enum class Color {RED, BLACK, DOUBLE_BLACK};

template<typename T>
class Node{
public:
    T key;
    Color color;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;

    Node(T k, Color c=Color::RED):key(k),color(c),parent(nullptr),
                                  left(nullptr),right(nullptr) {}
    Node(const Node<T> &x):key(x.key),color(x.color),parent(x.parent)
                           left(x.left),right(x.right) {} 
    //~Node(){ }
}


template<typename T>
class RbTree{
    
    private:
    Node<T> *root;
    const Node<T> *nil=nullptr; 
    
    public:
    RbTree();
    ~BsTree();

    private:
    void LeftRotate(Node<T> *x);
    void RightRotate(Node<T> *x);

    public:
    void TreeInsert(Node<T> *x);
}



#endif
