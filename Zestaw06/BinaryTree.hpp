//############################################//
//                                            //
//    Jan Kwinta                09.12.2022    //
//                                            //
//                                            //
//    Zestaw06: Binarne drzewo poszukiwan     //
//    Plik: BinaryTree.hpp                    //
//                                            //
//    Zadanie 1. Drzewo binarne               //
//                                            //
//############################################//

#include <stdexcept>
#include <algorithm>
#include <iostream>

#ifndef BINARYTREE
#define BINARYTREE

template<class T>
struct BinaryNode
{
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
        treeDepth = 0;
    }

    ~BinaryTree()
    {
        deleteRecursive(root);
    }
    
    template<class U>
    void insert(U&& x)
    {
        if(treeSize == 0)
        {
            root = new BinaryNode<T>(std::forward<U>(x));
            treeSize++;
            treeDepth = 1;
            return;
        }

        insertRecursive(root, std::forward<U>(x), 2);
    }   
    
    node_ptr search(T x)
    {
        node_ptr v = root;

        while(true)
        {
            if(x == v->data)
                return v;
            else if(x < v->data && v->left != nullptr)
                v = v->left;
            else if(x > v->data && v->right != nullptr)
                v = v->right;
            else
                return nullptr;
        }
    }
    
    node_ptr searchRecursive(T x)
    {
        return searchRecursiveRecursion(x, root);
    }   
    
    int size()
    {
        return treeSize;
    }
    
    T minimum()
    {
        return recursiveMinimum(root);
    }
  
    T maximum()
    {
        return recursiveMaximum(root);
    }
    
    int depth()
    {
        return treeDepth;
    }
    
    void inorder()
    {
        outputRecursive(root, 2);
    }
    
    void preorder()
    {
        outputRecursive(root, 1);
    }
    
    void postorder()
    {
        outputRecursive(root, 3);
    }
    
private:
    void deleteRecursive(node_ptr v)
    {
        if(v->left != nullptr)
            deleteRecursive(v->left);
        if(v->right != nullptr)
            deleteRecursive(v->right);

        delete v;
    }

    template<class U>
    void insertRecursive(node_ptr v, U&& x, int currentDepth)
    {
        if(x < v->data)
        {
            if(v->left == nullptr)
            {
                v->left = new BinaryNode<T>(std::forward<U>(x));
                treeSize++;
                treeDepth = std::max(treeDepth, currentDepth);
                return;
            }

            insertRecursive(v->left, std::forward<U>(x), currentDepth + 1);
        }
        else
        {
            if(v->right == nullptr)
            {
                v->right = new BinaryNode<T>(std::forward<U>(x));
                treeSize++;
                treeDepth = std::max(treeDepth, currentDepth);
                return;
            }

            insertRecursive(v->right, std::forward<U>(x), currentDepth + 1);
        }
    }

    node_ptr searchRecursiveRecursion(T x, node_ptr v)
    {
        if(x == v->data)
            return v;

        if(x < v->data && v->left != nullptr)
            return searchRecursiveRecursion(x, v->left);

        if(x > v->data && v->right != nullptr)
            return searchRecursiveRecursion(x, v->right);

        return nullptr;
    }

    T recursiveMinimum(node_ptr v)
    {
        if(v->left == nullptr)
            return v->data;
        return recursiveMinimum(v->left);
    }

    T recursiveMaximum(node_ptr v)
    {
        if(v->right == nullptr)
            return v->data;
        return recursiveMaximum(v->right);
    }

    void outputRecursive(node_ptr v, const int mode)
    {
        if(mode == 1)
            std::cout << v->data << std::endl;

        if(v->left != nullptr)
            outputRecursive(v->left, mode);

        if(mode == 2)
            std::cout << v->data << std::endl;

        if(v->right != nullptr)
            outputRecursive(v->right, mode);
        
        if(mode == 3)
            std::cout << v->data << std::endl;
    }

    node_ptr root;
    int treeSize;
    int treeDepth;
};

#endif
