#ifndef STORE_H
#define STORE_H

#include <vector>
#include <queue>
#include "avltree.h"

/*
 * The Store class describes the functions of a Media Rental Store
 * of some kind. It has a list of customers and rentable items, and
 * can process a set of commands that interacts with the customers,
 * the store's inventory, or both.
 */
class Store
{
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
    void loadCustomers(string file);

    /*
     * Load the file contianing all rentable items this store carries and
     * process them so they are added to the system.
     * 
     * Note: This function will send errors to std::cerr if a command cannot be
     * created with the information in some line.
     */
    void loadRentables(string file);

    /*
     * Load the file contianing the commands to run and add them into a queue
     * for later processing.
     * 
     * Note: This function will send errors to std::cerr if a command cannot be
     * created with the information in some line.
     */
    void loadCommands(string file);

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
    //A vector of vectors of AVL Trees for each kind of rentable.
    //This vector can be indexed with the RentableType and its subtype for
    //a given RentalType
    std::vector<std::vector<avltree>> rentables;

    HashTabe customers;

    int storeID;

    std::queue<Command> commandQueue;

}

#endif //STORE_H
