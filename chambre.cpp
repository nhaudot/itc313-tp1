#include <iostream>
#include "chambre.h"

namespace hotels
{
	Chambre::Chambre(int ID, typeChambre type, float prix)
	: _ID(ID) , _type(type) , _prix(prix)
	{

	}
	
	int Chambre::ID() const
	{
		return _ID;
	}

	typeChambre Chambre::type() const
	{
		return _type;
	}

	float Chambre::prix() const
	{
		return _prix;
	}

	// Setters
	void Chambre::setID(int ID)
	{
		_ID = ID;
	}

	void Chambre::setType(typeChambre type)
	{
		_type = type;
	}

	void Chambre::setPrix(float prix)
	{
		_prix = prix;
	}

	std::ostream& operator<<(std::ostream& os, const Chambre& chambre)
	{
		std::string typeChambre;

		if (chambre.type() == 0)
		{
			typeChambre = "Single";
		}
		else if (chambre.type() == 1)
		{
			typeChambre = "Double";
		}
		else if (chambre.type() == 2)
		{
			typeChambre = "Suite";
		}

		os << "Chambre n." << chambre.ID() << " : " << typeChambre << " (" << chambre.prix() << "$)" << std::endl;

		return os;
	}
}