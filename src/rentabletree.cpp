#include "rentabletree.h"

    RentableTree::RentableTree()
    {
        root = nullptr;
    }

    RentableTree::~RentableTree()
    {
        if(root != nullptr)
        {
            destructorHelper(root);
        }

        root = nullptr;
    }

    bool RentableTree::insert(Rentable* object)
    {
        if(insertHelper(root, object))
        {
            balanceTree();
            return true;
        }

        return false;
    }

    bool RentableTree::retrieve(const Rentable* object, Rentable*& RetObject)
    {
        return retrieveHelper(root, object, RetObject);
    }

    bool RentableTree::isEmpty()
    {
        return (root == nullptr);
    }

    void RentableTree::printTree()
    {
        printTreeHelper(root);
    }

    /*
     * Recursively traverses the AVL tree post order, deleting the children
     * nodes first, then the parent node.
     */
    void RentableTree::destructorHelper(Node* node)
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
    bool RentableTree::insertHelper(Node* node, T* object)
    {
        if( *(node->object) == *(object))//keep?
            return false;

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

    bool RentableTree::retrieveHelper(Node* node, const T& object, T*& RetObject)
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

    void RentableTree::printTreeHelper(Node* node)
    {
        if(node == nullptr)
            return;

        printTreeHelper(node->left);

        std::cout << *(node->object) << std::endl;

        printTreeHelper(node->right);
    }