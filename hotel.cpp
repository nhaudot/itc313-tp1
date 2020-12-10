#include "hotel.h"
#include <iostream>


namespace hotels
{
	Hotel::Hotel(const std::string id, const std::string name, const std::string city)
	: _uniqueID(id), _name(name), _city(city) 
	{

	}

	std::string Hotel::getID() const
	{
		return _uniqueID;
	}

	std::string Hotel::getName() const
	{
		return _name;
	}

	std::string Hotel::getCity() const
	{
		return _city;
	}

	std::vector<hotels::Chambre> Hotel::getRoomList() const
	{
		return _roomListIDs;
	}

	void Hotel::setName(const std::string name)
	{
		_name = name;
	}

	void Hotel::setCity(const std::string city)
	{
		_city = city;
	}

	void Hotel::addRoom(const hotels::Chambre newRoom)
	{
		_roomListIDs.push_back(newRoom);
	}

	void Hotel::removeRoom(const std::string room)
	{
		
	}

	std::ostream& operator<<(std::ostream& os, const Hotel& hotel)
	{
		os << "Hotel " << hotel.getName() << " (" << hotel.getID() << ") - " << hotel.getCity() << std::endl;

		return os;
	}
}