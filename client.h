#ifndef CLIENT
#define CLIENT

#include <string>

namespace hotels
{
	class Client
	{
	public:
		Client(int id, std::string prenom, std::string nom, int reservations=0);
		int ID() const;
		std::string prenom() const;
		std::string nom() const;
		std::string nomComplet() const;
		int reservations() const;
		void setPrenom(const std::string firstName);
		void setNom(const std::string lastName);
		void ajouterReservation(const int bookingNumber);
	private:
		int _id;
		std::string _prenom;
		std::string _nom;
		int _reservations;
	};

	std::ostream& operator<<(std::ostream& os, const Client& client);
}

#endif