#include "bookingManager.h"
#include <iostream>


namespace hotels
{
	BookingManager::BookingManager()
	{

	}

	void BookingManager::showBookings() const
	{
		std::cout << "Liste des réservations: " << std::endl << std::endl;

		for(int i = 0; i < bookingList.size(); i++)
		{
			std::cout << "[" << bookingList[i].getID() << "] " << bookingList[i].getBeginDate().toString() << " -> " << bookingList[i].getLeftDate().toString() << " | Chambre n." << bookingList[i].getRoomID() << " | Client n." << bookingList[i].getClientID() << " | Prix total: " << bookingList[i].getPrice() << "€" << std::endl;
		}
	}

	void BookingManager::showBooking(int id) const
	{

	}

	void BookingManager::showClientBooking(std::string clientName) const
	{

	}

	void BookingManager::showClientBooking(int clientID) const
	{

	}

	void BookingManager::addBooking(Booking& newBooking)
	{
		bookingList.push_back(newBooking);
	}

	void BookingManager::editBooking(int id)
	{

	}

	void BookingManager::cancelBooking(int id)
	{

	}

	bool BookingManager::checkBooking(int numChambreSelected, date::Date& startDate, date::Date& endDate) const
	{
		bool checkResa = false;
		bool checkRoom = false;

		for (int i = 0; i < bookingList.size(); i++)
		{
			if (bookingList[i].getRoomID() == numChambreSelected)
			{
				checkRoom = true;

				if (bookingList[i].getBeginDate() > endDate)
				{
					checkResa = true;
				}
				else if (startDate > bookingList[i].getLeftDate())
				{
					checkResa = true;
				}
			}
		}

		if (checkRoom == false)
		{
			checkResa = true;
		}
 
        return checkResa;
	}
}