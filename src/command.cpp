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
