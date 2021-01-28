#include <iostream>
#include "client.h"

namespace hotels
{
	Client::Client(int id, std::string prenom, std::string nom, int reservations)
	: _id(id) , _prenom(prenom) , _nom(nom) , _reservations(reservations)
	{

	}

	int Client::ID() const
	{
		return _id;
	}

	std::string Client::prenom() const
	{
		return _prenom;
	}

	std::string Client::nom() const
	{
		return _nom;
	}

	std::string Client::nomComplet() const
	{
		std::string _nomComplet = _prenom + " " + _nom;
		return _nomComplet;
	}

	int Client::reservations() const
	{
		return _reservations;
	}

	void Client::setPrenom(const std::string prenom)
	{
		_prenom = prenom;
	}

	void Client::setNom(const std::string nom)
	{
		_nom = nom;
	}

	void Client::ajouterReservation(const int reservations)
	{
		_reservations += reservations;
	}

	std::ostream& operator<<(std::ostream& os, const Client& client)
	{
		os << "Client n." << client.ID() << " : " << client.nomComplet() << " - Bookings : " << client.reservations() << std::endl;

		return os;
	}
}