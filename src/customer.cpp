#include "customer.h"
#include "classic.h"

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

bool Customer::operator==(const Customer& rhs) const
{
	return customerID== rhs.getCustomerID();
}

bool Customer::operator!=(const Customer& rhs) const
{
	return customerID != rhs.getCustomerID();
}

bool Customer::borrowRentable(int borrowCount, Rentable& rentable)
{
	//RentalDetails has a reference to a rentable, so this needs to be done
	//all at the same time.
	RentalDetails transaction = {&rentable, 0, borrowCount, false, "Borrow"};

	currentlyRenting.push_back(transaction);
	customerHistory.push_back(transaction);

	return true;
}

bool Customer::returnRentable(int returnCount, Rentable& rentable)
{
	for (int i = 0; i < currentlyRenting.size(); i++)
	{
		if (*(currentlyRenting[i].rental) == rentable ||
			currentlyRenting[i].rental->isEquivalent(rentable))
		{
			if(currentlyRenting[i].count >= returnCount)
			{
			    RentalDetails transaction = currentlyRenting[i];
			    transaction.count = returnCount;
			    transaction.returned = true;
			    transaction.action = "Return";

			    //update to reflect return
			    currentlyRenting[i].count -= returnCount;
				currentlyRenting[i].rental->addToStock(returnCount);

			    //need to check if count is reduced to zero
			    //if so, need to remove transaction from currentlyRenting
			    if (currentlyRenting[i].count == 0)
			    {
					// no more on hand, so remove from vector
					currentlyRenting.erase(currentlyRenting.begin() + i);
			    }
			    customerHistory.push_back(transaction);
			    return true;
			}
			else
			{
			    std::cerr << "ERROR: Invalid return request." << std::endl;
			    return false;
			}
		}
	}

	std::cerr << "ERROR: Customer not currently renting ";
	std::cerr << rentable.getTitle() << std::endl;
	return false;
}

void Customer::displayHistory() const
{
	std::cout << "Transaction History for: " << getCustomerLastName();
	std::cout << ", " << getCustomerFirstName();
	std::cout << "     Customer ID: "<< customerID << std::endl;

	if (customerHistory.size() == 0)
	{
		std::cout << "No history to display" << std::endl;
	}
	for (int i = customerHistory.size() -1 ; i >= 0 ; i--)
	{
		RentalDetails transaction = customerHistory[i];
		std::cout << transaction.action << "   ";
		std::cout << intToDVDType(transaction.rental->getSubtype()) << "  ";

		std::cout << transaction.rental->getReleaseYear() << "  ";
		std::cout << transaction.rental->getTitle();

		Classic* asClassic = dynamic_cast<Classic*>(transaction.rental);

		if(asClassic != nullptr)
		{
			std::cout << ", staring " << asClassic->getMajorActor();
		}

		
		std::cout << std::endl;



		
	}
	std::cout << std::endl;
}