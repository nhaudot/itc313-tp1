#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H

#include <string>
#include <vector>
#include "booking.h"



namespace hotels
{
	class BookingManager
	{
	public:
		BookingManager();
		void showBookings() const;
		void showBooking(int id) const;
		void showClientBooking(std::string clientName) const;
		void showClientBooking(int clientID) const;
		void addBooking(Booking& newBooking);
		void editBooking(int id);
		void cancelBooking(int id);
		bool checkBooking(int numChambreSelected, Date& startDate, Date& endDate);
	private:
		std::vector<Booking> bookingList;
	};
}


#endif