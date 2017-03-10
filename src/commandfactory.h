 /******************************************************************************
 * Author: 
 * Chantel Frizzell, Jeremy DeHaan
 *
 * Date Last Modified: 
 * 2017-03-10
 *
 * The command factory is used to aid in code reusibilty. Generates commands for 
 * any type of command.
 *
 ******************************************************************************/

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"
#include <string>

/*
 * The CommandFactory class generates commands.
 */
class CommandFactory
{
public:

/*
 * Creates a Commands based on a given line read from a file.
 */
static Command* createCommand(std::string line);
};

#endif //COMMANDFACTORY_H
