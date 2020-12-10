#include "bookingManager.h"
#include <iostream>


namespace hotels
{
	BookingManager::BookingManager()
	{

	}

	void BookingManager::showBookings() const
	{
		std::cout << "Show bookings" << std::endl << std::endl;

		for(int i = 0; i < bookingList.size(); i++)
		{
			std::cout << bookingList[i].getID() << " - " << bookingList[i].getBeginDate().toString() << " - " << bookingList[i].getLeftDate().toString() << " - " << bookingList[i].getRoomID() << " - " << bookingList[i].getClientID() << " - " << bookingList[i].getPrice() << " - " << std::endl;
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
		bool check = false;

		for(int i = 0; i < bookingList.size(); i++)
		{
        	if (bookingList[i].getRoomID() == numChambreSelected)
        	{
        		if (bookingList[i].getBeginDate() > endDate)
        		{
        			check = true;
        		}
        		else if (startDate > bookingList[i].getLeftDate())
        		{
        			check = true;
        		}
        	}
        	else
        	{
        		// La chambre n'est pas dans les résas de l'hôtel
        		check = true;
        	}
		}

		return check;
	}



}