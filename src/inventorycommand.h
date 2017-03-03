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
	InventoryCommand(/*parameters to create inventory command*/);
	~InventoryCommand();

	/*
     * Inventory is printed out:
     * all Comedy movies: by Title, then Year of Release.
     * all Drama movies: by Director, then Title.
     * all Classics movies: by Release date, then Major Actor.
     */
    bool processCommand();

private:
	InventoryCommand();
};

#endif //INVENTORYCOMMAND_H