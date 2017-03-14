
/*******************************************************************************
 * Store
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * The store class models a movie rental store. It has rentables, customers, and 
 * a set of commands to perform. 
 ******************************************************************************/
#ifndef STORE_H
#define STORE_H

#include <vector>
#include <queue>
#include "customer.h"
#include "hashtable.h"
#include "rentable.h"
#include "rentabletype.h"
#include "rentablestorage.h"

#include <fstream>

/*
 * The Store class describes the functions of a Media Rental Store
 * of some kind. It has a list of customers and rentable items, and
 * can process a set of commands that interacts with the customers,
 * the store's inventory, or both.
 */
class Store
{
    //This allows the Command class to access store private members
    //Doing this prevents needing to create accessors for the store's
    //private data
    friend class Command;

public:

    /*
     * Create a new instance of the store with no customers and no
     * rentable items.
     *
     * The store must be created with a store id.
     */
    Store(int id);

    /*
     * Load the file contianing customers and process them so they are added
     * to the system.
     */
    void loadCustomers(std::ifstream& file);

    /*
     * Load the file containing all rentable items this store carries and
     * process them so they are added to the system.
     *
     * Note: This function will send errors to std::cerr if a command cannot be
     * created with the information in some line.
     */
    void loadRentables(RentableType type, std::ifstream& file);

    /*
     * Load the file contianing the commands to run and add them into a queue
     * for later processing.
     *
     * Note: This function will send errors to std::cerr if a command cannot be
     * created with the information in some line.
     */
    void loadCommands(std::ifstream& file);

    /*
     * Process all commands in the queue.
     *
     * Note: This function will send errors to std::cerr if a command cannot be
     * processed.
     */
    void processCommands();

    /*
     * Get the store's ID.
     */
    int getID() const;


private:
    //the storage container for all rentables this store carries
    RentableStorage rentables;

    HashTable customers;

    int storeID;

    std::queue<Command*> commandQueue;

    //interface used by commands
    void printInventory();
    void displayHistory(Customer& searchCustomer);
    void borrowRentable(Customer& searchCustomer, Rentable& searchRentable);
    void returnRentable(Customer& searchCustomer, Rentable& searchRentable);

    //given some data, build a rentable to be searched for for borrowing or returning
    static Rentable* buildRentable(char type, char subtype, std::string data);
};

#endif //STORE_H
