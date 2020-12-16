#include <iostream>
#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "booking.h"



int main()
{
	// QUESTION 6A
	std::cout << "On crée notre hôtel" << std::endl << std::endl;
	hotels::Hotel monHotel("OCEAN11", "Le Bellagio", "Las Vegas");

	// Création des chambres SINGLE
	hotels::Chambre chambre0(0, hotels::Single, 100);
	monHotel.addRoom(chambre0);
	hotels::Chambre chambre1(1, hotels::Single, 100);
	monHotel.addRoom(chambre1);
	hotels::Chambre chambre2(2, hotels::Single, 100);
	monHotel.addRoom(chambre2);

	// Création des chambres DOUBLE
	hotels::Chambre chambre3(3, hotels::Double, 125);
	monHotel.addRoom(chambre3);
	hotels::Chambre chambre4(4, hotels::Double, 125);
	monHotel.addRoom(chambre4);
	hotels::Chambre chambre5(5, hotels::Double, 125);
	monHotel.addRoom(chambre5);
	hotels::Chambre chambre6(6, hotels::Double, 125);
	monHotel.addRoom(chambre6);
	hotels::Chambre chambre7(7, hotels::Double, 125);
	monHotel.addRoom(chambre7);

	// Création des chambres SUITE
	hotels::Chambre chambre8(8, hotels::Suite, 210);
	monHotel.addRoom(chambre8);
	hotels::Chambre chambre9(9, hotels::Suite, 210);
	monHotel.addRoom(chambre9);

	std::cout << "Nombre de chambres: " << monHotel.getRoomList().size() << std::endl << std::endl;


	// QUESTION 6B
	std::cout << chambre0 << std::endl;
	std::cout << monHotel << std::endl;


	// QUESTION 6C
	std::vector <hotels::Client> customersList;
	customersList.push_back(hotels::Client(0, "Robert", "Lafondu"));
	customersList.push_back(hotels::Client(1, "Jeannine", "Lafondu"));
	customersList.push_back(hotels::Client(2, "Fatal", "Bazooka"));
	customersList.push_back(hotels::Client(3, "Hugo", "Alexandre"));
	customersList.push_back(hotels::Client(4, "Martin", "Fourcade"));
	customersList.push_back(hotels::Client(5, "James", "Bond"));
	customersList.push_back(hotels::Client(6, "Harry", "Potter"));
	customersList.push_back(hotels::Client(7, "Jean", "Bon"));
	customersList.push_back(hotels::Client(8, "Emmanuel", "Macron"));
	customersList.push_back(hotels::Client(9, "Donald", "Trump"));

	// Book ID int
	int bookID = 0;

	// On crée des résas en avance pour les tests
	date::Date sd1(2020,12,10);
	date::Date ed1(2020,12,12);
	hotels::Booking myBook(bookID, sd1, ed1, 9, 9, 2000.0);
	monHotel.bkManager.addBooking(myBook);


	// QUESTION 6D
	std::cout << customersList[4];

	std::cout << std::endl << "___________________________________" << std::endl << std::endl;


	// Boucle infinie du programme pour entrer constamment des résas
	while(true)
	{
		std::cout << std::endl << "___________________________________" << std::endl << std::endl;

		// QUESTION 7A

		// Début séjour
		int year1;
		int month1;
		int day1;

		// Fin séjour
		int year2;
		int month2;
		int day2;

		int tailleSejourComplet;

		date::Date startDate;
		date::Date endDate;

		bool flag = true;
		while (flag == true)
		{
			// Paramètres début séjour
			std::cout << "Entrer une année de début de séjour : ";
			std::cin >> year1;
			std::cout << "Entrer un mois de début de séjour : ";
			std::cin >> month1;
			std::cout << "Entrer une journée de début de séjour : ";
			std::cin >> day1;

			//paramètres fin séjour
			std::cout << "Entrer une année de fin de séjour : ";
			std::cin >> year2;
			std::cout << "Entrer un mois de fin de séjour : ";
			std::cin >> month2;
			std::cout << "Entrer une journée de fin de séjour : ";
			std::cin >> day2;

			startDate.setYear(year1);
			startDate.setMonth(month1);
			startDate.setDay(day1);

			endDate.setYear(year2);
			endDate.setMonth(month2);
			endDate.setDay(day2);

			// QUESTION 7B

			tailleSejourComplet = endDate - startDate;

			if (endDate.checkDate(month1,day1) && startDate.checkDate(month2,day2) && tailleSejourComplet > 0)
			{
				flag = false;
				std::cout << "Taille du séjour: " << tailleSejourComplet << " jours" << std::endl;
			}
			else
			{
				std::cout << "Dates invalides, veuillez recommencer la saisie avec des dates valides." << std::endl;
			}
		}


		// QUESTION 8A
		int numChambreSelected;
		bool typeChambreBool = false;

		while (typeChambreBool == false)
		{
			std::cout << "Saisissez le type de chambre souhaité (0 = simple, 1 = double, 2 = suite): ";
			int typeChambre;
			std::cin >> typeChambre;

			if (typeChambre <= 2 && typeChambre >= 0)
			{








				// QUESTION 8B

				int trouve = 0;
				// On parcourt les chambres pour savoir si elles sont dispos
				for (int i = 0; i < monHotel.getRoomList().size(); i++)
				{
					if (monHotel.getRoomList()[i].getType() == typeChambre)
					{
						bool test = monHotel.bkManager.checkBooking(monHotel.getRoomList()[i].getId(), startDate, endDate);

						if (test == true)
						{
							// La chambre est dispo
							std::cout << "La chambre " << monHotel.getRoomList()[i].getId() << " est disponible." << std::endl;
							trouve = 1;
							typeChambreBool = true;
						}
					}
				}












				// QUESTION 8C
				if (trouve == 0)
				{
					std::cout << "Le type de chambre n'est pas disponible." << std::endl;
				} else
				{
					std::cout << "Sélectionner le numéro de chambre souhaité: ";
					std::cin >> numChambreSelected;
					std::cout << "Vous avez sélectionné la chambre " << numChambreSelected << std::endl;
				}
			
			}
		}


		// QUESTION 9A
		std::string nomClient;
		std::cout << "Saisissez le nom du client: ";
		std::cin >> nomClient;


		// QUESTION 9B

		// On parcourt les clients et on affiche ceux qui ont le même nom
		std::vector<int> clientOkID;
		int clientOk = 0;

		for (int i = 0; i < customersList.size(); i++)
		{
			if (customersList[i].getLastName() == nomClient)
			{
				std::cout << clientOk << ". " << customersList[i].getFullName() << std::endl;
				clientOkID.push_back(i);
				clientOk++;
			}
		}

		int selectedClient;
		std::cout << "Choisir un client: ";
		std::cin >> selectedClient;


		// QUESTION 9C
		std::cout << std::endl << customersList[clientOkID[selectedClient]];



		// QUESTION 10A
		float price = tailleSejourComplet * monHotel.getRoomList()[numChambreSelected].getPrice();
		std::cout << "Prix total du séjour: " << price << "€" << std::endl;


		// On ajoute la résa à la liste de réservations de l'hôtel
		bookID++;
		hotels::Booking myNewBook(bookID, startDate, endDate, numChambreSelected, customersList[clientOkID[selectedClient]].getID(), price);
		monHotel.bkManager.addBooking(myNewBook);

		std::cout << std::endl;

		monHotel.bkManager.showBookings();

	}

	


























	







	





















































	return 0;
}