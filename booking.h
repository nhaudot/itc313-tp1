#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>
#include "date.h"



namespace hotels
{
	class Booking
	{
	public:
		Booking(const int id, const date::Date beginDate, const date::Date leftDate, const int roomID, const int clientID, const float price);

		int getID() const;
		date::Date getBeginDate() const;
		date::Date getLeftDate() const;
		int getRoomID() const;
		int getClientID() const;
		int getPrice() const;

		void setBeginDate(const date::Date beginDate);
		void getLeftDate(const date::Date leftDate);
		void setRoomID(const int id);
		void setClientID(const int id);
		void setPrice(const float price);

	private:
		int _uniqueID;
		date::Date _beginDate;
		date::Date _leftDate;
		int _roomID;
		int _clientID;
		float _price;
	};
}


#endif