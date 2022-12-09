//############################################//
//                                            //
//    Jan Kwinta                04.11.2022    //
//                                            //
//                                            //
//    Zestaw06: Binarne drzewo poszukiwań     //
//    Plik: BinaryTree.hpp                    //
//                                            //
//    Zadanie 1. Drzewo binarne               //
//                                            //
//############################################//

#include <stdexcept>
#include <iostream>

#ifndef BINARYTREE
#define BINARYTREE

template<class T>
struct BinaryNode
{
    BinaryNode(): data{NULL}, left{nullptr}, right{nullptr}
    {
    }

    BinaryNode(const T& x): data{x}, left{nullptr}, right{nullptr}
    {
    }
    
    T data;
    BinaryNode<T> *left;
    BinaryNode<T> *right;
};

template<class T>
class BinaryTree
{    
using node_ptr = BinaryNode<T> *;
public:
    BinaryTree()
    {
        root = nullptr;
        treeSize = 0;
    }
    
    template<class U>
    void insert(U&& x)
    {
    }
    
    node_ptr search(T x)
    {
        return nullptr;
    }
    
    node_ptr searchRecursive(T x)
    {
        return nullptr;
    }
    
    int size()
    {
        return treeSize;
    }
    
    T minimum()
    {
    }
    
    T maximum()
    {
    }
    
    int depth()
    {
        return 0;
    }
    
    void inorder()
    {
    }
    
    void preorder()
    {
    }
    
    void postorder()
    {
    }
    
private:
    node_ptr root;
    int treeSize;
};

#endif
