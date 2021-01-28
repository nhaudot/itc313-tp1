#ifndef CHAMBRE
#define CHAMBRE

#include <string>

namespace hotels
{
	enum typeChambre { Single , Double , Suite };

	class Chambre
	{
	public:
		Chambre(int ID, typeChambre type, float prix);
		int ID() const;
		typeChambre type() const;
		float prix() const;
		void setID(const int ID);
		void setType(const typeChambre type);
		void setPrix(const float price);
	private:
		int _ID;
		typeChambre _type;
		float _prix;
	};

	std::ostream& operator<<(std::ostream& os, const Chambre& chambre);
}
#endif