#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
    
    Node<T> *insertHelper(int val, Node<T> *root);

    std::vector<T> *inorderHelper(std::vector<T> *v, Node<T> *node);

    std::vector<T> *postorderHelper(std::vector<T> *v, Node<T> *node);
    
    std::vector<T> *preorderHelper(std::vector<T> *v, Node<T> *node);
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;
    inorderHelper(vec, root);
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    preorderHelper(vec, root);
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;
    postorderHelper(vec, root);
    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
    root = insertHelper(new_data, root);
}


template<class T>
Node<T> *BST<T>::search(T val)
{

}



template<class T>
void BST<T>::remove(T val)
{

}



template<class T>
int BST<T>::get_size()
{
    return node_count;
}

template<class T>
Node<T> *BST<T>::insertHelper(int val, Node<T> *node)
{
    if(node == NULL){
        Node<T> *tmp = new Node<T>;
        tmp->set_data(val);
        tmp->set_left(NULL);
        tmp->set_right(NULL);
        node_count++;
        return tmp;
    } else if(val < node->get_data()){
        node->set_left(insertHelper(val, node->get_left()));
    } else if(val > node->get_data()){
        node->set_right(insertHelper(val, node->get_right()));
    }
    return node;
}

template <class T>
std::vector<T> *BST<T>::inorderHelper(std::vector<T> *v, Node<T> *node)
{
    if(node == NULL){
        return NULL;
    }
    inorderHelper(v, node->get_left());
    v->push_back(node->get_data());
    inorderHelper(v, node->get_right());
    return v;
}

template <class T>
std::vector<T> *BST<T>::preorderHelper(std::vector<T> *v, Node<T> *node)
{
    if(node == NULL){
        return NULL;
    }
    v->push_back(node->get_data());
    preorderHelper(v, node->get_left());
    preorderHelper(v, node->get_right());
    return v;
}

template <class T>
std::vector<T> *BST<T>::postorderHelper(std::vector<T> *v, Node<T> *node)
{
    if(node == NULL){
        return NULL;
    }
    postorderHelper(v, node->get_left());
    postorderHelper(v, node->get_right());
    v->push_back(node->get_data());
    return v;
}        