#ifndef CHAMBRE
#define CHAMBRE

#include <string>

namespace hotels
{
	enum roomType { Single , Double , Suite , Cave };

	class Chambre
	{
	public:
		//Constructeur
		Chambre(int id, roomType type, float price);
		//Getters
		int getId() const;
		roomType getType() const;
		float getPrice() const;
		//Setters
		void setId(const int id);
		void setType(const roomType type);
		void setPrice(const float price);

	private:
		//Varibales Membres
		int _id;
		roomType _type;
		float _price;
	};
	std::ostream& operator<<(std::ostream& os, const Chambre& chambre);
}
#endif