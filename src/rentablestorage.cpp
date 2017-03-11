#include "rentablestorage.h"

RentableStorage::RentableStorage()
{
    //nothing?
}

RentableStorage::~RentableStorage()
{
    int length = rentables.size();

    for(int i = 0; i < length; i++)
    {
        int subLength = rentables[i].size();

        for(int j = 0; j< subLength; j++)
        {
            destructorHelper(rentables[i][j]);
            //delete (rentables[i][j]);
        }
    }
}

bool RentableStorage::insert(Rentable* object)
{

        if(object == nullptr)
            return false;

        int mainType = object->getType();
        int subType = object->getSubtype();


        //make sure that we can place the rentable somewhere

        std::vector<Node*> newVector;
        newVector.push_back(nullptr);

        int size = rentables.size();

        while(rentables.size() < mainType+1)
        {
            rentables.push_back(newVector);
        }

        while(rentables[mainType].size() < subType+1)
        {
            rentables[mainType].push_back(nullptr);
        }


        //check if the first node is a null

        if(rentables[mainType][subType] == nullptr)
        {
            rentables[mainType][subType] = new Node{object, nullptr, nullptr};
            return true;
        }
        else
        {
            return insertHelper(rentables[mainType][subType], object);
        }
}

// For Classic: if 0 in stock - go to next one, if < requested in stock, 
// retrieve all of current stock, retrieve rest from next actor.
// 
// if !classic, call retrieve, else call retrieveClassic
bool RentableStorage::retrieve(const Rentable* object, Rentable*& RetObject)
{
    if(object == nullptr)
        return false;

    int mainType = object->getType();
    int subType = object->getSubtype();

    if(rentables.size() < mainType)
        return false;

    if(rentables[mainType].size() < subType)
        return false;

    return retrieveHelper(rentables[mainType][subType], object, RetObject);
}

void RentableStorage::printInventory() const
{
    int length = rentables.size();

    for(int i = 0; i < length; i++)
    {

        //printing all "type"

        int subLength = rentables[i].size();

        for(int j = 0; j< subLength; j++)
        {

            //printing all "subtype"

            printHelper(rentables[i][j]);
        }
    }
}

void RentableStorage::destructorHelper(Node* node)
{
    if(node == nullptr)
            return;

    destructorHelper(node->left);
    destructorHelper(node->right);

    delete node;
    node = nullptr;
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

void RentableStorage::printHelper(const Node* node) const
{
    if(node == nullptr)
            return;

    printHelper(node->left);

    std::cout << *(node->object) << std::endl;

    printHelper(node->right);
}