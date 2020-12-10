#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include "chambre.h"



namespace hotels
{
	class Hotel
	{
	public:
		Hotel(const std::string id, const std::string name, const std::string city);

		std::string getID() const;
		std::string getName() const;
		std::string getCity() const;
		std::vector<hotels::Chambre> getRoomList() const;

		void setName(const std::string name);
		void setCity(const std::string city);

		void addRoom(const hotels::Chambre newRoom);
		void removeRoom(const std::string room);


	private:
		std::string _uniqueID;
		std::string _name;
		std::string _city;
		std::vector<hotels::Chambre> _roomListIDs;
	};
	std::ostream& operator<<(std::ostream& os, const Hotel& hotel);
}


#endif