/*******************************************************************************
 * RentableStorage
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * This wrapper exists to help make sure that all of the rentables are stored
 * in an easy to access place, but ensures that typed inforation is kept when
 * items are inserted and accessed.
 ******************************************************************************/
#ifndef RENTABLESTORAGE_H
#define RENTABLESTORAGE_H

#include <vector>
#include <string>
#include "rentable.h"

class Classic;

//REMEMEBER: Add the classics next actor logic

/*
 * RentableStorage models a multi-dimensional array structure storing every
 * rentable a store will carry.
 */
class RentableStorage
{

public:

    RentableStorage();
    ~RentableStorage();

    bool insert(Rentable* object);

    bool retrieve(const Rentable* object, Rentable*& RetObject);

    bool retrieveEquivalent(const Rentable* object,
    std::vector<std::string>& searchList, Rentable*& RetObject);

    void printInventory() const;

private:
    struct Node
    {
        Rentable* object;
        Node* left;
        Node* right;

        ~Node()
        {
            delete object;
        }
    };


    //multi-dimensional array of root nodes of binary trees
    std::vector<std::vector<Node*>> rentables;

    void destructorHelper(Node* node);

    bool insertHelper(Node* node, Rentable* object);

    bool retrieveHelper(Node* node, const Rentable* object, Rentable*& RetObject);

    bool retrieveEquivalentHelper(Node* node, const Classic* object,
                    std::vector<std::string>& searchList, Rentable*& RetObject);

    void printHelper(const Node* node) const;

};

#endif //RENTABLESTORAGE_H