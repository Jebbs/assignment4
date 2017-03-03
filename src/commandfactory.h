#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "command.h"

/*
 * The CommandFactory class generates commands.
 */
class CommandFactory
{
public:

/*
 * Creates a Commands based on a given line read from a file.
 */
static Command* createCommand(string line);
}

#endif //COMMANDFACTORY_H
