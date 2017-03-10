#include "inventorycommand.h"

#include "store.h"

InventoryCommand::InventoryCommand()
{
    //nothing?
}

bool InventoryCommand::processCommand()
{
    //check store here?
    //if store == nullptr

    storeInst->printInventory();

    return true;

}