#ifndef RENTABLETREE_H
#define RENTABLETREE_H

#include <iostream>

/*
 * RentableTreee is a binary tree for storing some kind of rentable type.
 *
 *
 */
template <class T>
class RentableTree
{
public:

    /*
     * Creates empty AVL tree with root node set to NULL
     */
    RentableTree()
    {
        root = nullptr;
    }

    ~RentableTree()
    {
        if(root != nullptr)
        {
            destructorHelper(root);
        }

        root = nullptr;
    }

    /*
     * Inserts a DVD into tree, returns true if succeeded
     */
    bool insert(T* object)
    {
        return insertHelper(root, object);
    }

    /*
     * Retrieves a DVD from tree, points to it
     */
    bool retrieve(const T& object, T*& RetObject)
    {
        return retrieveHelper(root, object, RetObject);
    }

    /*
     * Returns true if no items are in the tree
     */
    bool isEmpty()
    {
        return (root == nullptr);
    }

    /*
     * Prints out the tree in order
     */
    void printTree()
    {
        printTreeHelper(root);
    }

private:
    template <class U>
    struct Node
    {
        U* object;
        Node<U> *right;
        Node<U> *left;
    };

    Node<T> *root;

    
    void destructorHelper(Node<T>* node)
    {
        if(node == nullptr)
            return;

        destructorHelper(node->left);
        destructorHelper(node->right);

        delete node;
        node = nullptr;
    }

    /*
     * Performs an in order traversal to find an empty place to insert a new
     * rentable object.
     *
     * Returns true if a place was found, false if the object already exists in
     * the AVL tree.
     */
    Node<T>* insertHelper(Node<T>* node, T* object)
    {
        if( *(node->object) == *(object))//keep?
            return false;

        
        Node<T>* problemNode;

        if(*(node->object) < *(object))
        {

            if(node->right == nullptr)
            {
                node->right = new Node<T>{object, nullptr, nullptr};
                return true;
            }
            else
            {
               return insertHelper(node->right, object);
            }

            
        }
        else
        {
            if(node->left == nullptr)
            {
                node->left = new Node<T>{object, nullptr, nullptr};
                return true;
            }
            else
            {
                return insertHelper(node->left, object);
            }
        }

    }

    bool retrieveHelper(Node<T>* node, const T& object, T*& RetObject)
    {
        if(node == nullptr)
        {
            return false;
        }

        if( *(node->object) == *(object))
        {
            RetObject = node->object;
            return true;
        }

        if(*(node->object) < *(object))
            return retrieveHelper(node->right, object, RetObject);

        return retrieveHelper(node->left, object, RetObject);
    }

    void printTreeHelper(Node<T>* node)
    {
        if(node == nullptr)
            return;

        printTreeHelper(node->left);

        std::cout << *(node->object) << std::endl;

        printTreeHelper(node->right);
    }

};




#endif //RENTABLETREE_H