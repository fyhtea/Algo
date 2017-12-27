/*************************************************************************
	> File Name: bstree.h
	> Author: 
	> Mail: 
	> Created Time: 2017年11月23日 星期四 10时41分53秒
 ************************************************************************/

#ifndef _BSTREE_H
#define _BSTREE_H

#include<iostream>
using namespace std;

template<typename T>
class Node{

public:
    T key;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;

    Node(T key):key(key),parent(nullptr),left(nullptr),right(nullptr) {}
    Node(const Node<T>& x):key(x.key),parent(x.parent),left(x.left),right(x.right) {}
    /*~Node(){
        delete left;
        delete right;
    }*/
};

template<typename T>
class BsTree{
    
    private:
    Node<T> *root;

    public:
    BsTree();
    ~BsTree();

    private:
    void DestroyNode(Node<T> *x);
    void Destroy();
    
    void Transplant(Node<T> *u, Node<T> *v);
    void RemoveNode(Node<T> *x);
    
    private:
    //traverse
    void InOrderWalk(Node<T> *x);
    void PreOderWalk(Node<T> *x);
    void PostOderWalk(Node<T> *x);
    
    //search
    private:
    Node<T>* TreeSearch(Node<T> *x, T k);
    public:
    Node<T>* Search(T k);
    //max & min
    private:
    Node<T>* TreeMax(Node<T> *x);
    Node<T>* TreeMin(Node<T> *x);
    public:
    Node<T>* Max();
    Node<T>* Min();

    //successor & predecessor 
    Node<T>* TreeSuccessor(Node<T> *x);
    Node<T>* TreePredecessor(Node<T> *x); 
    

    public:
    void Traverse();


    //insertion & deletion
    void TreeInsert(T k);
    void TreeDelete(Node<T> *x);
};
template<typename T>
inline Node<T>* BsTree<T>::Max(){
    return TreeMax(root);
}

template<typename T>
inline Node<T>* BsTree<T>::Min(){
    return TreeMin(root);
}


template<typename T>
inline BsTree<T>::BsTree():root(nullptr) {}

template<typename T>
inline BsTree<T>::~BsTree(){
    Destroy();
}

template<typename T>
inline void BsTree<T>::DestroyNode(Node<T> *x){
    if(x){
        DestroyNode(x->left);
        DestroyNode(x->right);
        delete x;
    }
}

template<typename T>
inline void BsTree<T>::Destroy(){
    DestroyNode(root);
    //root = nullptr;
}

template<typename T>
inline void BsTree<T>::Transplant(Node<T> *u, Node<T> *v){
    if(u->parent == nullptr){
       // root=v;
    }else if(u->parent->left == u){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    if(v != nullptr){
        v->parent = u->parent;
    }
}

template<typename T>
inline void BsTree<T>::RemoveNode(Node<T> *x){
    if(x){
        x->left=nullptr;
        x->right=nullptr;
        x->parent=nullptr;
    }
    delete x;
}

template<typename T>
inline void BsTree<T>::InOrderWalk(Node<T> *x){
    if(x!=nullptr){
        InOrderWalk(x->left);
        cout<<x->key<<endl;
        InOrderWalk(x->right);
    }else{
        return;
    }
}

template<typename T>
inline void BsTree<T>::PreOderWalk(Node<T> *x){
    if(x!=nullptr){
        cout<<x->key<<endl;
        PreOderWalk(x->left);
        PreOderWalk(x->right);
    }else{
        return;
    }
}

template<typename T>
inline void BsTree<T>::PostOderWalk(Node<T> *x){
    if(x!=nullptr){
        PostOderWalk(x->left);
        PostOderWalk(x->right);
        cout<<x->key<<endl;
    }else{
        return;
    }
}

template<typename T>
inline Node<T>* BsTree<T>::TreeSearch(Node<T> *x, T k){
    if(x==nullptr || x->key==k){
        return x;
    }
    else if(k<x->key){
        return TreeSearch(x->left, k);
    }else{
        return TreeSearch(x->right, k);
    }
}

template<typename T>
inline Node<T>* BsTree<T>::Search(T k){
    return TreeSearch(root,k);
}

template<typename T>
inline Node<T>* BsTree<T>::TreeMax(Node<T> *x){
    while(x->right != nullptr){
        x = x->right;
    }
    return x; 
}

template<typename T>
inline Node<T>* BsTree<T>::TreeMin(Node<T> *x){
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}

template<typename T>
inline Node<T>* BsTree<T>::TreeSuccessor(Node<T> *x){
    if(x->right != nullptr){
        return TreeMin(x->right);
    }else{
        Node<T> *tmp = x->parent;
        while(tmp != nullptr && tmp->right == x){
            x = tmp;
            tmp = tmp->parent;
        }
        return tmp;
    }
}

template<typename T>
inline Node<T>* BsTree<T>::TreePredecessor(Node<T> *x){
    if(x->left != nullptr){
        return TreeMax(x->left);
    }else{
        Node<T> *tmp = x->parent;
        while(tmp != nullptr && tmp->left == x){
            x = tmp;
            tmp = tmp->parent;
        }
        return tmp;
    }
}

template<typename T>
inline void BsTree<T>::Traverse(){
    cout<<"InOrderWalk:"<<endl;
    InOrderWalk(root);

    cout<<"PreOderWalk:"<<endl;
    PreOderWalk(root);

    cout<<"PostOderWalk:"<<endl;
    PostOderWalk(root);
}


template<typename T>
inline void BsTree<T>::TreeInsert(T k){

    Node<T> *in_node = new Node<T>(k);
    Node<T> *y = nullptr;
    Node<T> *x = root;

    while(x!=nullptr){
        y = x;
        if(x->key > in_node->key){
            x = x->left;
        }else{
            x = x->right;
        }    
    }

    in_node->parent = y;

    if(y==nullptr){
        root = in_node;
    }else if(in_node->key<y->key){
        y->left = in_node;
    }else{
        y->right = in_node;
    }
}

template<typename T>
inline void BsTree<T>::TreeDelete(Node<T> *x){
    if(x->left ==nullptr){
        Transplant(x, x->right);
    }else if(x->right == nullptr){
        Transplant(x, x->left);
    }else{
        Node<T> *y = TreeMin(x->right);

        if(y->parent != x){
            Transplant(y, y->right);
            y->right = x->right;
            y->right->parent = y;
        }
        Transplant(x, y);
        y->left = x->left;
        y->left->parent = y;
    }
    RemoveNode(x);
}
#endif
