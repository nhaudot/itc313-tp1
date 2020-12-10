#ifndef CLIENT
#define CLIENT

#include <string>


namespace hotels
{
	class Client
	{
	
	public:
		// Constructeurs
		Client(int id, std::string firstName, std::string lastName, int booking=0);
		//Geters
		int getID() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getFullName() const;
		int getBooking() const;
		// Setters (pas de setId , on est pas censé le modifier)
		void setFirstName(const std::string firstName);
		void setLastName(const std::string lastName);
		void addBooking(const int bookingNumber);
	
	private:
		//variables membres
		int _id;
		std::string _firstName;
		std::string _lastName;
		int _booking;
	};
	std::ostream& operator<<(std::ostream& os, const Client& client);

}

#endif