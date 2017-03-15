#include "rentablestorage.h"
#include "classic.h" 
#include <string>
#include <vector>

bool isNextEquivalent(const Classic* search, const Classic* test,
                      std::vector<std::string>& searchList);

std::string getRentableTypeName(int type);
std::string getSubTypeName(int type, int subtype);

RentableStorage::RentableStorage()
{
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
        }
    }
}

bool RentableStorage::insert(Rentable* object)
{
    if(object == nullptr)
    {
        return false;
    }

    int mainType = (int)object->getType();
    int subType = object->getSubtype();

    //make sure that we can place the rentable somewhere

    std::vector<Node *> newVector;
    newVector.push_back(nullptr);

    while (rentables.size() < mainType + 1)
    {
        rentables.push_back(newVector);
    }

    while (rentables[mainType].size() < subType + 1)
    {
        rentables[mainType].push_back(nullptr);
    }

    //check if the first node is a null

    if (rentables[mainType][subType] == nullptr)
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
    {
        return false;
    }

    int mainType = (int)object->getType();
    int subType = object->getSubtype();

    if(rentables.size() < mainType)
    {
        return false;
    }

    if(rentables[mainType].size() < subType)
    {
        return false;
    }

    return retrieveHelper(rentables[mainType][subType], object, RetObject);
}

bool RentableStorage::retrieveEquivalent(const Rentable* object,
    std::vector<std::string>& searchList, Rentable*& RetObject)
{
    const Classic* asClassic = dynamic_cast<const Classic*>(object);

    //only Classics have an equivalent movie
    if(asClassic == nullptr)
    {
        return false;
    }

    int mainType = (int)object->getType();
    int subType = object->getSubtype();

    //error checking doesn't need to be done because this function is only
    //called after an existing object of the same time was found?
    if(rentables.size() < mainType)
    {
        return false;
    }

    if(rentables[mainType].size() < subType)
        return false;

    return retrieveEquivalentHelper(rentables[mainType][subType], asClassic,
                                    searchList, RetObject);
}

void RentableStorage::printInventory() const
{
    int length = rentables.size();

    for(int i = 0; i < length; i++)
    {
        std::cout << "Printing all " << getRentableTypeName(i) << std::endl;

        int subLength = rentables[i].size();

        for(int j = 0; j< subLength; j++)
        {
            std::cout << getSubTypeName(i, j) << std::endl;

            printHelper(rentables[i][j]);
            std::cout << std::endl;
        }
    }
}

void RentableStorage::destructorHelper(Node* node)
{
    if(node == nullptr)
    {
        return;
    }

    destructorHelper(node->left);
    destructorHelper(node->right);

    delete node;
    node = nullptr;
}

bool RentableStorage::insertHelper(Node* node, Rentable* object)
{
    //exact match found, which should never happen
    if( *(node->object) == *(object))
    {
        return true;
    }

    if(*(node->object) < *(object))
    {
        if(node->right == nullptr)
        {
            node->right = new Node{object, nullptr, nullptr};
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
            node->left = new Node{object, nullptr, nullptr};
            return true;
        }
        else
        {
            return insertHelper(node->left, object);
        }
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
    {
        return retrieveHelper(node->right, object, RetObject);
    }

    return retrieveHelper(node->left, object, RetObject);
}

bool RentableStorage::retrieveEquivalentHelper(Node* node, const Classic* object,
std::vector<std::string>& searchList, Rentable*& RetObject)
{
    if(node == nullptr)
    {
        return false;
    }

    const Classic* testClassic = dynamic_cast<Classic*>(node->object);

    if( isNextEquivalent(object, testClassic, searchList))
    {
        RetObject = node->object;
        return true;
    }

    if(object->getMonth() < testClassic->getMonth()|| 
       (object->getMonth() == testClassic->getMonth() && 
        object->getReleaseYear() < testClassic->getReleaseYear()))
    {
        return retrieveEquivalentHelper(node->left, object, searchList, RetObject);
    }

    if(object->getMonth() > testClassic->getMonth()|| 
       (object->getMonth() == testClassic->getMonth() && 
        object->getReleaseYear() > testClassic->getReleaseYear()))
    {
        return retrieveEquivalentHelper(node->right, object, searchList, RetObject);
    }

    if(object->getMonth() == testClassic->getMonth() && 
        object->getReleaseYear() == testClassic->getReleaseYear())
    {
        if(retrieveEquivalentHelper(node->right, object, searchList, RetObject))
        {
            return true;
        }
        if(retrieveEquivalentHelper(node->left, object, searchList, RetObject))
        {
            return true;
        }
    }

    return false;
}

void RentableStorage::printHelper(const Node* node) const
{
    if(node == nullptr)
    {
        return;
    }

    printHelper(node->left);

    std::cout << *(node->object) << std::endl;

    printHelper(node->right);
}

bool isNextEquivalent(const Classic* search, const Classic* test,
                      std::vector<std::string>& searchList)
{
    if (search->getMonth() == test->getMonth() &&
    	search->getReleaseYear() == test->getReleaseYear() &&
        search->getTitle() == test->getTitle())
	{
        //found the "same" movie, let's make sure we haven't tried this one
        for(int i = 0; i < searchList.size(); i++)
        {
            if(test->getMajorActor() == searchList[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

std::string getRentableTypeName(int type)
{
    switch(type)
    {
        case 0:
        {
            return "DVDs";
        }
        default:
        {
            return "";
        }
    }
}

std::string getSubTypeName(int type, int subtype)
{
    switch(type)
    {
        case 0:
        {
            switch(subtype)
            {
                case 0:
                {
                    return "Comedy DVDs";
                }
                case 1:
                {
                    return "Drama DVDs";
                }
                case 2:
                {
                    return "Classic DVDs";
                }
                default:
                {
                    return "";
                }
            }
        }
        default:
        {
            return "";
        }
    }
}
