/*******************************************************************************
 * InventoryCommand
 *
 * Authors: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-13
 *
 * Prints the entire inventory of the store as follows:
 * 
 * 1) Comedy movies: by Title, then Year of Release.
 * 2) Drama movies: by Director, then Title.
 * 3) Classics movies: by Release date, then Major Actor.
 ******************************************************************************/
#ifndef INVENTORYCOMMAND_H
#define INVENTORYCOMMAND_H

#include "command.h"

/*
 * Subclass of public Command.
 * InventoryCommand prints out all items in store.
 */
class InventoryCommand : public Command
{
public:
	InventoryCommand();
    ~InventoryCommand();

	/*
     * Inventory is printed out:
     */
    bool processCommand();

private:
	//InventoryCommand();
};

#endif //INVENTORYCOMMAND_H