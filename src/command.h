#ifndef COMMAND_H
#define COMMAND_H




/*
 * The Command class defines a template for all
 * types of commands.
 */
class Command
{
    //so that a store can give a command an instance of itself when creating
    friend class Store;
public:

    /*
     * Process the command for this Command.
     */
    virtua bool processCommand();

private:
    //the instance of the store this command will operate on
    Store* storeInst;

}

#endif //COMMAND_H
