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
}

#endif //COMMANDFACTORY_H
