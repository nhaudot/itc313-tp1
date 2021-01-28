#include <iostream>
#include "hotel.h"

namespace hotels
{
	Hotel::Hotel(const std::string ID, const std::string nom, const std::string ville)
	: _ID(ID), _nom(nom), _ville(ville) 
	{

	}

	std::string Hotel::ID() const
	{
		return _ID;
	}

	std::string Hotel::nom() const
	{
		return _nom;
	}

	std::string Hotel::ville() const
	{
		return _ville;
	}

	std::vector<hotels::Chambre> Hotel::listeChambres() const
	{
		return _IDChambres;
	}

	bool Hotel::verifierReservation(int numChambreSelected, date::Date& startDate, date::Date& endDate) const
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

	void Hotel::setNom(const std::string nom)
	{
		_nom = nom;
	}

	void Hotel::setVille(const std::string ville)
	{
		_ville = ville;
	}

	void Hotel::ajouterChambre(const hotels::typeChambre type, const float prix)
	{
		hotels::Chambre nouvelleChambre(_IDChambres.size() + 1, type, prix);
		_IDChambres.push_back(nouvelleChambre);
	}

	void Hotel::supprimerChambre(const int id)
	{
		_IDChambres.erase(_IDChambres.begin() + id);
	}

	void Hotel::editerChambre(const int id, const int type, const float prix)
	{
		if (type == 0)
		{
			_IDChambres[id].setType(hotels::typeChambre::Single);
		}
		else if(type == 1)
		{
			_IDChambres[id].setType(hotels::typeChambre::Double);
		}
		else if (type == 2)
		{
			_IDChambres[id].setType(hotels::typeChambre::Suite);
		}

		_IDChambres[id].setPrix(prix);
	}

	int Hotel::nombreReservations() const
	{
		return bookingList.size();
	}
	
	void Hotel::reservations() const
	{
		for(int i = 0; i < bookingList.size(); i++)
		{
			std::cout << "[" << bookingList[i].getID() << "] " << bookingList[i].getBeginDate().toString() << " -> " << bookingList[i].getLeftDate().toString() << " | Room n." << bookingList[i].getRoomID() << " | Client n." << bookingList[i].getClientID() << " | Total price : " << bookingList[i].getPrice() << "$ | Canceled : " << bookingList[i].getCancel() << std::endl;
		}
	}

	void Hotel::reservations(int id) const
	{
		for(int i = 0; i < bookingList.size(); i++)
		{
			if (bookingList[i].getID() == id)
			{
				std::cout << "[" << bookingList[i].getID() << "] " << bookingList[i].getBeginDate().toString() << " -> " << bookingList[i].getLeftDate().toString() << " | Room n." << bookingList[i].getRoomID() << " | Client n." << bookingList[i].getClientID() << " | Total price : " << bookingList[i].getPrice() << "$ | Canceled : " << bookingList[i].getCancel() << std::endl;
			}
		}
	}

	void Hotel::reservationClient(int clientID) const
	{
		for (int i = 0; i < bookingList.size(); i++)
		{
			if (bookingList[i].getClientID() == clientID)
			{
				std::cout << "[" << bookingList[i].getID() << "] " << bookingList[i].getBeginDate().toString() << " -> " << bookingList[i].getLeftDate().toString() << " | Room n." << bookingList[i].getRoomID() << " | Client n." << bookingList[i].getClientID() << " | Total price : " << bookingList[i].getPrice() << "$ | Canceled : " << bookingList[i].getCancel() << std::endl;
			}
		}
	}

	void Hotel::ajouterReservation(Booking& newBooking)
	{
		bookingList.push_back(newBooking);
	}

	void Hotel::annulerReservation(int id)
	{
		for (int i = 0; i < bookingList.size(); i++)
		{
			if (bookingList[i].getID() == id)
			{
				bookingList[i].cancel();
			}
		}
	}

	std::ostream& operator<<(std::ostream& os, const Hotel& hotel)
	{
		os << hotel.nom() << " (" << hotel.ID() << ") | " << hotel.ville();

		return os;
	}
}