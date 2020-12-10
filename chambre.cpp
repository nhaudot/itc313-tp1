#include <iostream>
#include "chambre.h"

namespace hotels
{
	// Constructeur
	Chambre::Chambre(int id, roomType type, float price)
	: _id(id) , _type(type) , _price(price)
	{

	}
	
	// Getters
	int Chambre::getId() const
	{
		return _id;
	}

	roomType Chambre::getType() const
	{
		return _type;
	}

	float Chambre::getPrice() const
	{
		return _price;
	}

	// Setters
	void Chambre::setId(int id)
	{
		_id = id;
	}

	void Chambre::setType(roomType type)
	{
		_type = type;
	}

	void Chambre::setPrice(float price)
	{
		_price = price;
	}

	std::ostream& operator<<(std::ostream& os, const Chambre& chambre)
	{
		std::string typeChambre;

		if (chambre.getType() == 0)
		{
			typeChambre = "Single";
		}
		else if (chambre.getType() == 1)
		{
			typeChambre = "Double";
		}
		else if (chambre.getType() == 2)
		{
			typeChambre = "Suite";
		}

		os << "Chambre n." << chambre.getId() << " : " << typeChambre << " (" << chambre.getPrice() << ")" << std::endl;

		return os;
	}
}