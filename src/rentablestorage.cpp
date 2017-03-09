#include "rentablestorage.h"

RentableStorage::RentableStorage()
{
    //nothing?
}

RentableStorage::~RentableStorage()
{
    int length = rentables.length();

    for(int i = 0; i < length; i++)
    {
        int subLength = rentables[i].length();

        for(int j = 0; j< subLength; j++)
        {
            destructorHelper(rentables[i][j]);
            delete (rentables[i][j]);
        }
    }
}

bool RentableStorage::insert(Rentable* object)
{
        int mainType = object->getType();
        int subType = object->getSubtype();


        //make sure that we can place the rentable somewhere

        std::vector<Rentable*> newVector;
        newVector.push_back(nullptr);

        while(rentables.length() < mainType)
        {
            rentables.push_back(newVector);
        }

        while(rentables[mainType].length() < subType)
        {
            rentables[mainType].pushback(nullptr);
        }


        //check if the first node is a null

        if(rentables[mainType][subType] == nullptr)
        {
            rentables[mainType][subType] = new Node{object, null, null};
            return true;
        }
        else
        {
            return insertHelper(rentables[mainType][subType], object);
        }
}

bool RentableStorage::retreive(const Rentable* object, Rentable*& RetObject)
{
    int mainType = object->getType();
    int subType = object->getSubtype();

    if(rentables.length() < mainType)
        return false;

    if(rentables[mainType].length() < subType)
        return false;

    return retrieveHelper(rentables[mainType][subType], object, RetObject);
}

void RentableStorage::printInventory() const
{
    int length = rentables.length();

    for(int i = 0; i < length; i++)
    {
        int subLength = rentables[i].length();

        for(int j = 0; j< subLength; j++)
        {
            printHelper(rentables[i][j]);
        }
    }
}


bool RentableStorage::insertHelper(Node* node, Rentable* object)
{
    if( *(node->object) == *(object))//keep?
            return false;


    if(*(node->object) < *(object))
    {
        if(node->right == nullptr)
        {
            node->right = new Node{object, nullptr, nullptr};
            return true;
        }
        else
            return insertHelper(node->right, object);
    }
    else
    {
        if(node->left == nullptr)
        {
            node->left = new Node{object, nullptr, nullptr};
            return true;
        }
        else
            return insertHelper(node->left, object);
    }
}

bool RentableStorage::retrieveHelper(Node* node, const Rentable* object, Rentable*& RetObject)
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

void RentableStorage::printHelper(Node* node)
{
    if(node == nullptr)
            return;

    printHelper(node->left);

    std::cout << *(node->object) << std::endl;

    printHelper(node->right);
}