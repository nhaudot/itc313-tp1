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
			std::cout << "[" << bookingList[i].getID() << "] " << bookingList[i].getBeginDate().toString() << " -> " << bookingList[i].getLeftDate().toString() << " | Chambre n." << bookingList[i].getRoomID() << " | Client n." << bookingList[i].getClientID() << " | Prix total: " << bookingList[i].getPrice() << "€ | Annulé: " << bookingList[i].getCancel() << std::endl;
		}
	}

	void BookingManager::showBooking(int id) const
	{
		for (int i = 0; i < bookingList.size(); i++)
		{
			if (bookingList[i].getID() == id)
			{
				std::cout << "[" << bookingList[i].getID() << "] " << bookingList[i].getBeginDate().toString() << " -> " << bookingList[i].getLeftDate().toString() << " | Chambre n." << bookingList[i].getRoomID() << " | Client n." << bookingList[i].getClientID() << " | Prix total: " << bookingList[i].getPrice() << "€ | Annulé: " << bookingList[i].getCancel() << std::endl;
			}
		}
	}

	void BookingManager::showClientBooking(std::string clientName) const
	{
		
	}

	void BookingManager::showClientBooking(int clientID) const
	{
		for (int i = 0; i < bookingList.size(); i++)
		{
			if (bookingList[i].getClientID() == clientID)
			{
				std::cout << "[" << bookingList[i].getID() << "] " << bookingList[i].getBeginDate().toString() << " -> " << bookingList[i].getLeftDate().toString() << " | Chambre n." << bookingList[i].getRoomID() << " | Client n." << bookingList[i].getClientID() << " | Prix total: " << bookingList[i].getPrice() << "€ | Annulé: " << bookingList[i].getCancel() << std::endl;
			}
		}
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
		for (int i = 0; i < bookingList.size(); i++)
		{
			if (bookingList[i].getID() == id)
			{
				bookingList[i].cancel();
			}
		}
	}

	bool BookingManager::checkBooking(int numChambreSelected, date::Date& startDate, date::Date& endDate) const
	{
		bool checkResa = false;
		bool checkRoom = false;

		for (int i = 0; i < bookingList.size(); i++)
		{
			if (bookingList[i].getRoomID() == numChambreSelected && bookingList[i].getCancel() == false)
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