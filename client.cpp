#include <iostream>
#include "client.h"


namespace hotels
{
// Constructeur
	Client::Client(int id, std::string firstName, std::string lastName, int booking)
	: _id(id) , _firstName(firstName) , _lastName(lastName) , _booking(booking)
	{

	}

// Getters
	int Client::getID() const
	{
		return _id;
	}

	std::string Client::getFirstName() const
	{
		return _firstName;
	}

	std::string Client::getLastName() const
	{
		return _lastName;
	}

	std::string Client::getFullName() const
	{
		std::string fullName = _firstName + " " + _lastName;
		return fullName;
	}

	int Client::getBooking() const
	{
		return _booking;
	}

// Setters
	void Client::setFirstName(const std::string firstName)
	{
		_firstName = firstName;
	}

	void Client::setLastName(const std::string lastName)
	{
		_lastName = lastName;
	}

	void Client::addBooking(const int bookingNumber)
	{
		_booking += bookingNumber;
	}

	std::ostream& operator<<(std::ostream& os, const Client& client)
	{
		os << "Client n." << client.getID() << " : " << client.getFullName() << " - Réservations: " << client.getBooking() << std::endl;

		return os;
	}
}