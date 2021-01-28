#include "booking.h"
#include <iostream>


namespace hotels
{
	
	Booking::Booking(const int id, const date::Date beginDate, const date::Date leftDate, const int roomID, const int clientID, const float price, const bool canceled)
	: _uniqueID(id), _beginDate(beginDate), _leftDate(leftDate), _roomID(roomID), _clientID(clientID), _price(price), _canceled(canceled)
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

	int Booking::getCancel() const
	{
		return _canceled;
	}

	void Booking::setBeginDate(const date::Date beginDate)
	{
		_beginDate = beginDate;
	}

	void Booking::getLeftDate(const date::Date leftDate)
	{
		_leftDate = leftDate;
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

	void Booking::cancel()
	{
		_canceled = true;
	}

}