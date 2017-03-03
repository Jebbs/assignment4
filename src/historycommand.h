#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "command.h"
#include "customer.h"

/*
 * Subclass of public Command.
 * HistoryCommand takes CustomerId as parameter and prints 
 * out customer's Borrow- and Return- Commands chronologically.
 */
class HistoryCommand : public Command
{
public:
	/*
     * Creates a HistoryCommand
     */
	HistoryCommand(/*parameters to create classic movie*/);
	~HistoryCommand();

	/*
     * Retrieve a customer by its Id. (If not found, return false)
     * Print out customers history of Borrows and Returns chronologically.
     */
	bool processCommand();

private:
	HistoryCommand();
	Customer cust;
};

#endif //HISTORYCOMMAND_H