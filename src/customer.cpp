#include "customer.h"

Customer::Customer(int id, std::string lastName, std::string firstName)
{
	this->customerID = id;
	this->lastName = lastName;
	this->firstName = firstName;
}

int Customer::getCustomerID() const
{
	return customerID;
}

void Customer::setCustomerID(int newID)
{
	customerID = newID;
}

std::string Customer::getCustomerFirstName() const
{
	return firstName;
}

void Customer::setCustomerFirstName(std::string newFirstName)
{
	firstName = newFirstName;
}

std::string Customer::getCustomerLastName() const
{
	return lastName;
}

void Customer::setCustomerLastName(std::string newLastName)
{
	lastName = newLastName;
}

/*
void Customer::displayHistory() const
{
	for (int i = 0; i < customerHistory.size(); i++)
	{
		std::cout << customerHistory[i];
	}
}
*/

bool Customer::operator==(const Customer& rhs) const  // do we need these? 
{
	return customerID== rhs.getCustomerID();
}

bool Customer::operator!=(const Customer& rhs) const  // do we need these? 
{
	return customerID != rhs.getCustomerID();
}

bool Customer::borrowRentable(int borrowCount, Rentable& rentable)
{
	//RentalDetails transaction = new RentalDetails();
	// or 

	//RentalDetails has a reference to a rentable, so this needs to be done
	//all at the same time.
	RentalDetails transaction = {rentable, 0, borrowCount, false, "Borrow"};
	

	currentlyRenting.push_back(transaction);
	//customerHistory;//push_back what? the same transaction?


	//Each rentable has its rentalPeriodInDays set during construction
	//I think below is not needed since it will always be set, so we don't have to set it manually

	/*
	// to set return date - NOT fully implemented, since out of the scope for this assignment.
	switch (type)
	{
	case 0: 
		//rental is a DVD
		currentlyRenting[i].setRentalPeriodInDayse = DVD_RENTAL_PERIOD;
		break;
	case 1:
		// this (and any other case) is for future implementation of other rentable types.
		break;
	}
	*/
}

bool Customer::returnRentable(int returnCount, Rentable& rentable)
{
	for (int i = 0; i < currentlyRenting.size(); i++)
	{
		if (currentlyRenting[i].rental == rentable && 
			currentlyRenting[i].count >= returnCount)
		{

			//need to check if count is reduced to zero
			//if so, need to remove transaction from currentlyRenting

			RentalDetails transaction = currentlyRenting[i];
			transaction.count -= returnCount;//minus equals and not  just equals?
			transaction.returned = true;
			transaction.action = "Return";

			//addToCustomerHistory(transaction);

			//update to reflect return 
			currentlyRenting[i].count -= returnCount;
			currentlyRenting[i].returned = true;
			currentlyRenting[i].action = "Return";
			
			customerHistory.push_back(transaction);
			//customerHistory;
			break;
		}
		else
		{
			std::cerr << "INVALID RETURN REQUEST" << std::endl;
		}
	}

	//emit error here

	//"customer not renting this movie" or something like that.

}

void Customer::displayHistory() const
{
	std::cout << "Transaction History for: " << getCustomerLastName();
	std::cout << ", " << getCustomerFirstName();
	std::cout << "  Customer ID: "<< customerID << std::endl;
	
	//RentalDetails transaction = new RentalDetails();
	// or 
	
	for (int i = customerHistory.size() - 1; i >= 0; i--)
	{



		RentalDetails transaction = customerHistory[i];
		std::cout << transaction.action << "     ";
		std::cout << transaction.rental.getType() << "     ";
		// cout << transaction.rental.subtypestuff
		std::cout << transaction.rental.getTitle() << "     ";
		//if (transaction.rental.getType() == classic)
		// {
		//     do the date thats necessary here 
		//     do the actors necessary here
		// else 
		// {
		std::cout << transaction.rental.getReleaseYear();
		// }
		std::cout << std::endl;
	}
}