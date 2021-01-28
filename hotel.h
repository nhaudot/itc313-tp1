#ifndef HOTEL_H
#define HOTEL_H

#include <string>
#include <vector>
#include "chambre.h"
#include "booking.h"



namespace hotels
{
	class Hotel
	{
	public:
		Hotel(const std::string ID, const std::string nom, const std::string ville);
		std::string ID() const;
		std::string nom() const;
		std::string ville() const;
		std::vector<hotels::Chambre> listeChambres() const;

		bool verifierReservation(int numChambreSelected, date::Date& startDate, date::Date& endDate) const;

		void setNom(const std::string nom);
		void setVille(const std::string ville);
		void ajouterChambre(const hotels::typeChambre type, const float prix);
		void supprimerChambre(const int id);
		void editerChambre(const int id, const int type, const float prix);

		int nombreReservations() const;
		void reservations() const;
		void reservations(int id) const;
		void reservationClient(int clientID) const;
		void ajouterReservation(Booking& newBooking);
		void annulerReservation(int id);

	private:
		std::string _ID;
		std::string _nom;
		std::string _ville;
		std::vector<hotels::Chambre> _IDChambres;
		std::vector<Booking> bookingList;
	};

	std::ostream& operator<<(std::ostream& os, const Hotel& hotel);
}


#endif