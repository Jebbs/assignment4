#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>

/*
 * AVL Tree is a balanced binary tree storing DVD's
 * Extendability: can be templatized
 */
template <class T>
class AVLTree
{
public:

    /*
     * Creates empty AVL tree with root node set to NULL
     */
    AVLTree()
    {
        root = nullptr;
    }

    ~AVLTree()
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
        if(insertHelper(root, object))
        {
            balanceTree();
            return true;
        }

        return false;
    }

    /*
     * Retrieves a DVD from tree, points to it
     */
    bool retrieve(const T& object, T*& RetObject)
    {
        return retrieveHelper(root, object, RetObject);
    }

    /*
     * Removes a DVD from the tree
     */
    bool removeObject(const T& object)
    {
        return removeHelper(root, object);
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

    //Returns height of the tree
    int getHeight();

    //Balances the tree {
    //compare node heights
    //if subtrees of any node differ in height more than 1 level
    //find the lowest unbalanced node
    //rotate node
    //}
    void balanceTree()
    {
        //check if tree is ok


        //if tree needs adjusting

        //find problem node

        //decide what kind of rotation is needed

        //perform correct rotation
    }

    //Helper function to balance tree
    void rotateLeft(Node *n);

    //Helper function to balance tree
    void rotateRight(Node *n);


    //--recursive helper functions--//

    /*
     * Recursively traverses the AVL tree post order, deleting the children
     * nodes first, then the parent node.
     */
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
                problemNode = nullptr;
            }
            else
            {
                problemNode = insertHelper(node->right, object);
            }

            
        }
        else
        {
            if(node->left == nullptr)
            {
                node->left = new Node<T>{object, nullptr, nullptr};
                problemNode = nullptr;
            }
            else
            {
                problemNode = insertHelper(node->left, object);
            }
        }




        if(problemNode == nullptr)
        {
            int left = getHeight(node->left);
            int right = getHeight(node->right);

            int diff = left - right;

            if(diff == -2 || diff == 2)
            {
                return node;
            }
            else
            {
                return nullptr;
            }
        }
        else
            return problemNode;
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

    bool removeHelper(Node<T>* node, const T& object)
    {

        //find the node

        //find correct replacement

        //delete node

        return false;
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


#endif //AVLTREE_H
