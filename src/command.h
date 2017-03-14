/*******************************************************************************
 * Command
 * 
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * The Command class defines a template for all
 * types of commands and then sends them to be processed
 *
 ******************************************************************************/
#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>//debug

//forward decl
class Store;
class HashTable;
class RentableStorage;
class Rentable;

class Command
{
    //so that a store can give a command an instance of itself when creating
    friend class Store;

public:

    /*
     * The command class process the command for this Command
     */
    virtual bool processCommand() = 0;
    virtual ~Command() = 0;

protected:

    HashTable& getHashTable();
    RentableStorage& getRentableStorage();
    Rentable* buildRentable(char type, char subtype, std::string data);


private:
    //the instance of the store this command will operate on
    Store* storeInst;
};

#endif //COMMAND_H
