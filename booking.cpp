#include "booking.h"
#include <iostream>


namespace hotels
{
	
	Booking::Booking(const int id, const date::Date beginDate, const date::Date leftDate, const int hotelID, const int roomID, const int clientID, const float price)
	: _uniqueID(id), _beginDate(beginDate), _leftDate(leftDate), _hotelID(hotelID), _roomID(roomID), _clientID(clientID), _price(price)
	{

	}

	int Booking::getID() const
	{
		return _uniqueID;
	}

	date::Date Booking::getBeginDate() const
	{
		return _beginDate;
	}

	date::Date Booking::getLeftDate() const
	{
		return _leftDate;
	}

	int Booking::getHotelID() const
	{
		return _hotelID;
	}

	int Booking::getRoomID() const
	{
		return _roomID;
	}

	int Booking::getClientID() const
	{
		return _clientID;
	}

	int Booking::getPrice() const
	{
		return _price;
	}

	float Booking::getTotalPrice() const
	{
		return _price * 2;
	}

	void Booking::setBeginDate(const date::Date beginDate)
	{
		_beginDate = beginDate;
	}

	void Booking::getLeftDate(const date::Date leftDate)
	{
		_leftDate = leftDate;
	}

	void Booking::setHotelID(const int id)
	{
		_hotelID = id;
	}

	void Booking::setRoomID(const int id)
	{
		_roomID = id;
	}

	void Booking::setClientID(const int id)
	{
		_clientID = id;
	}

	void Booking::setPrice(const float price)
	{
		_price = price;
	}

}