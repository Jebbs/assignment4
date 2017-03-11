#include "inventorycommand.h"

#include "rentablestorage.h"

InventoryCommand::~InventoryCommand()
{
    
}

InventoryCommand::InventoryCommand()
{
    //nothing?
}

bool InventoryCommand::processCommand()
{
    RentableStorage& rentables = getRentableStorage();

    rentables.printInventory();
    
    return true;
}