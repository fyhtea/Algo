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
    Node(const Node<T> &x):key(x.key),color(x.color),parent(x.parent),
                           left(x.left),right(x.right) {} 
    //~Node(){ }
};

template<typename T>
class RbTree{
    
    private:
    Node<T> *root;
    Node<T> *nil; 
    
    public:
    RbTree();
    //~RbTree();

    private:
    // (a, x, (b, y, c)) ===> ((a, x, b), y, c)
    void LeftRotate(Node<T> *x);
    // ((a, x, b), y, c) ===> (a, x, (b, y, c))
    void RightRotate(Node<T> *x);

    void InOrderWalk(Node<T> *x);
    void PreOrderWalk(Node<T> *x);
    void PostOrderWalk(Node<T> *x);

    void Transplant(Node<T> *u, Node<T> *v);


    //max & min
    
    Node<T>* TreeMax(Node<T> *x);
    Node<T>* TreeMin(Node<T> *x); 
    

    public:
    void InsertFix(Node<T> *x);
    void TreeInsert(T k);
    void Traverse();
    void TreeDelete(Node<T> *z);
    void DeleteFixup(Node<T> *x);
};

template<typename T>
inline RbTree<T>::RbTree(){
    nil = new Node<T>(0);
    nil->parent = nil;
    nil->left = nil;
    nil->right = nil;
    root = nil;
}

template<typename T>
inline void RbTree<T>::LeftRotate(Node<T> *x){
    Node<T> *y = x->right;
    x->right = y->left;
    if (y->left != nil){
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nil){
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
inline Node<T>* RbTree<T>::TreeMax(Node<T> *x){
    while(x->right != nil){
        x = x->right;
    }
    return x; 
}

template<typename T>
inline Node<T>* RbTree<T>::TreeMin(Node<T> *x){
    while(x->left != nil){
        x = x->left;
    }
    return x;
}

template<typename T>
inline void RbTree<T>::Transplant(Node<T> *u, Node<T> *v){
    if(u->parent == nil){
        root = v;
    }else if(u == u->parent->left){
        u->parent->left = v;
    }else{
        u->parent->right = v;
    }
    v->parent = u->parent;
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
        root = in_node;
    }else if(in_node->key < y->key){
        y->left = in_node;
    }else{
        y->right = in_node;
    }

    in_node->left = nil;
    in_node->right = nil;
    in_node->color = Color::RED;
    if(in_node->parent != nil){
        if(in_node->parent->parent != nil){
            if(in_node->parent->parent->parent != nil){
            InsertFix(in_node);
            }
        }
    }
    //InsertFix(in_node);
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

template<typename T>
inline void RbTree<T>::TreeDelete(Node<T> *z){
    Node<T> *y = z;
    Node<T> *x;
    Color y_origin_color = y->color;
    
    // if z has only one child node
    if (z->left == nil){
        x = z->right;
        Transplant(z, z->right);
    }else if(z->right == nil){
        x = z->left;
        Transplant(z, z->left);
    }else{
        //if z has two children, let y=z->successor take z's position
        y = TreeMin(z->right);           
        y_origin_color = y->color;        
        x = y->right;
        if(y->parent == z){
            x->parent = y;
        }else{
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if (y_origin_color == Color::BLACK){
        DeleteFixup(x);
    }
}

template<typename T>
inline void RbTree<T>::DeleteFixup(Node<T> *x){
    Node<T> *w;
    while(x != root && x->color==Color::BLACK){
        if(x == x->parent->left){
            w = x->parent->right;
            if(w->color = Color::RED){
                w->color = Color::BLACK;                    
                x->parent->color = Color::RED;
                LeftRotate(x->parent);
                w = x->parent->right;
            }
            if(w->left->color == Color::BLACK && w->right->color == Color::BLACK){
                w->color == Color::RED;
                x = x->parent;
            }
            else{
                if(w->right->color == Color::BLACK){
                    w->left->color = Color::BLACK;
                    w->color = Color::RED;
                    RightRotate(w);
                    w = x->parent->right;
                }else{
                    w->color = x->parent->color;
                    x->parent->color = Color::BLACK;
                    w->right->color = Color::BLACK;
                    LeftRotate(x->parent);
                    x = root;
                }
            }
        }else{
            w = x->parent->left;
            if(w->color == Color::RED){
                w->color = Color::BLACK;
                x->parent->color = Color::RED;
                RightRotate(x->parent);
                w = x->parent->left;                    // case1 
            }
            if(w->left->color == Color::BLACK && w->right->color == Color::BLACK){
                w->color = Color::RED;
                x = x->parent;                          // case2 
            }
            else{ 
                if(w->left->color == Color::BLACK){
                    w->right->color = Color::BLACK;
                    w->color = Color::RED;
                    LeftRotate(w);
                    w = x->parent->left;
                }else{
                    w->color = x->parent->color;
                    x->parent->color = Color::BLACK;
                    x->left->color = Color::BLACK;
                    RightRotate(w);
                    x = root;
                }    
            }
        }
    }
    x->color = Color::BLACK;
}

#endif
