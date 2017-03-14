/*******************************************************************************
 * HistoryCommand
 *
 * Author: 
 * Jeremy DeHaan, Chantel Frizzell
 *
 * Date Last Modified: 
 * 2017-03-10
 *
 * Returns the requested customer's history, in reverse-chronological order.
 ******************************************************************************/
#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "command.h"
#include "customer.h"

/*
 * Subclass of public Command.
 * HistoryCommand takes CustomerId as parameter and prints
 * out customer's Borrow- and Return- starting from the latest to the earliest.
 */
class HistoryCommand : public Command
{
public:
	/*
     * Creates a HistoryCommand
     */
	HistoryCommand(int customerID);
	~HistoryCommand();

	/*
     * Retrieve a customer by its Id. (If not found, return false)
     * Print out customers history of Borrows and Returns chronologically.
     */
	bool processCommand();

private:
	HistoryCommand();
	Customer searchCustomer;
};

#endif //HISTORYCOMMAND_H