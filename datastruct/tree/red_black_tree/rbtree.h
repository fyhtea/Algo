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
};


template<typename T>
class RbTree{
    
    private:
    Node<T> *root;
    const Node<T> *nil; 
    
    public:
    RbTree();
    ~BsTree();

    private:
    // (a, x, (b, y, c)) ===> ((a, x, b), y, c)
    void LeftRotate(Node<T> *x);
    // ((a, x, b), y, c) ===> (a, x, (b, y, c))
    void RightRotate(Node<T> *x);

    void InOrderWalk(Node<T> *x);
    void PreOrderWalk(Node<T> *x);
    void PostOrderWalk(Node<T> *x);



    public:
    void InsertFix(Node<T> *x);
    void TreeInsert(T k);
    void Traverse();

};

template<typename T>
inline void RbTree<T>::LeftRotate(Node<T> *x){
    Node<T> *y = x->right;
    x->right = y->left;
    if (y->left != nil){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if x->parent== nil{
        root = y;
    }else if(x == x->parent->left){
        x->parent->left = y;
    }else{
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

template<typename T>
inline void RbTree<T>::RightRotate(Node<T> *x){
    Node<T> *y = x->parent;
    
    y->left = x->right;
    if (x->left != nil){
        x->left->parent = y;
    }
    
    x->parent = y->parent;
    if(y->parent == nil){
        root = x;
    }else if(y == y->parent->left){
        y->parent->left = x;
    }else{
        y->parent->right = x;
    }

    x->right = y;
    y->parent = x;
}

template<typename T>
inline void RbTree<T>::InOrderWalk(Node<T> *x){
    if(x!=nil){
        InOrderWalk(x->left);
        cout<<x->key<<endl;
        InOrderWalk(x->right);
    }else{
        return;
    }
}

template<typename T>
inline void RbTree<T>::PreOrderWalk(Node<T> *x){
    if(x != nil){
        cout<<x->key<<endl;
        PreOrderWalk(x->left);
        PreOrderWalk(x->right);
    }else{
        return;
    }
}

template<typename T>
inline void RbTree<T>::PostOrderWalk(Node<T> *x){
    if(x != nil){
        PostOrderWalk(x->left);
        PostOrderWalk(x->right);
        cout<<x->key<<endl;
    }else{
        return;
    }
}


template<typename T>
inline void RbTree<T>::Traverse(){
    cout<<"InOrderWalk:"<<endl;
    InOrderWalk(root);

    cout<<"PreOrderWalk:"<<endl;
    PreOrderWalk(root);

    cout<<"PostOrderWalk:"<<endl;
    PostOrderWalk(root);
}

template<typename T>
inline void RbTree<T>::TreeInsert(T k){
    
    Node<T> *in_node = new Node<T>(k);
    Node<T> *y = nil;
    Node<T> *x = root;

    while(x != nil){
        y = x;
        if (in_node->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    in_node->parent = y;

    if(y == nil){
        root = x;
    }else if(x->key < y->key){
        y->left = x;
    }else{
        y->right = x;
    }

    x->left = nil;
    x->right = nil;
    x->color = Color::RED;

    InsertFix(x);
}

template<typename T>
inline void RbTree<T>::InsertFix(Node<T> *x){
    Node<T> *y;
    while(x->parent->color == Color::RED){
        
        if(x->parent == x->parent->parent->left){
            y = x->parent->parent->right;
            
            if(y->color == Color::RED){                      //
                x->parent->color = Color::BLACK;             //
                y->color = Color::BLACK;                     //
                x->parent->parent->color = Color::RED;       //
                x = x->parent->parent;                       //  case1
            }else{

                if(x == x->parent->right){
                    x = x->parent;                           //
                    LeftRotate(x);                           //  case2->3
                }

                x->parent->color = Color::BLACK;             //
                x->parent->parent->color = Color::RED;       //
                RightRotate(x->parent->parent);              //  case3
            }
        
        }else{
            y = x->parent->parent->left;

            if(y->color == Color::RED){
                y->parent->color = Color::BLACK;
                y->color = Color::BLACK;
                x->parent->parent->color = Color::RED;
                x = x->parent->parent;
            }else{
                
                if(x == x->parent->left){
                    x = x->parent;
                    RightRotate(x);
                }

                x->parent->color = Color::BLACK;
                x->parent->parent->color = Color::RED;
                LeftRotate(x->parent->parent);
            }
        }
    }
    root->color = Color::BLACK;
}

#endif
