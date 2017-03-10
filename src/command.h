/*******************************************************************************
 * Command
 * 
 * Author: 
 * Jeremy DeHaan, Chantel Frizzell
 *
 * Date Last Modified: 
 * 2017-03-10
 *
 * The Command class defines a template for all
 * types of commands and then sends them to be processed
 *
 ******************************************************************************/

#ifndef COMMAND_H
#define COMMAND_H

//forward decl
class Store;

class Command
{
    //so that a store can give a command an instance of itself when creating
    friend class Store;

public:

    /*
     * The command class process the command for this Command
     */
    virtual bool processCommand() = 0;

private:
    //the instance of the store this command will operate on
    Store* storeInst;
};

#endif //COMMAND_H
