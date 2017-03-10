#include "command.h"
#include "store.h"


HashTable& Command::getHashTable()
{
    return storeInst->customers;
}

RentableStorage& Command::getRentableStorage()
{
    return storeInst->rentables;
}

Rentable* Command::buildRentable(char type, char subtype, std::string data)
{
    return Store::buildRentable(type, subtype, data);
}
