#ifndef COMMAND_H
#define COMMAND_H

//forward declaration
class Store;


/*
 * The Command class defines a template for all
 * types of commands.
 */
class Command
{
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
