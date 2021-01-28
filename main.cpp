#include <iostream>
#include "date.h"
#include "hotel.h"
#include "client.h"
#include "booking.h"

using namespace hotels;

int main()
{
	system("clear");

	// Variables console
	std::vector<Hotel> listeHotels;
	std::vector<Client> listeClients;
	bool boucle = true;
	std::string commande;
	std::string hotelSelectionne = std::to_string(-1);
	int bookID = 0;

	std::cout << "HOSTEL MANAGER" << std::endl << std::endl;

	while (boucle == true)
	{
		std::cout << ">";
		std::getline(std::cin, commande);

		// Supprime les espaces en trop
		bool trimEnd = false;
		while (trimEnd == false)
		{
			if (commande.back() == ' ')
			{
				commande = commande.substr(0, commande.size()-1);
			}
			else
			{
				trimEnd = true;
			}
		}

		// ### LISTE DES COMMANDES ###
		// Quitter
		if (commande == "exit")
		{
			std::cout << "Good bye !" << std::endl;
			boucle = false;
		}
		// Ajouter un hôtel
		else if (commande == "hostel add")
		{
			std::string nom;
			std::string id;
			std::string ville;

			std::cout << "Hostel's name : ";
			std::getline(std::cin, nom);
			std::cout << "Hostel's ID : ";
			std::getline(std::cin, id);
			std::cout << "City : ";
			std::getline(std::cin, ville);

			Hotel nouvelHotel(id, nom, ville);
			listeHotels.push_back(nouvelHotel);

			std::cout << "Hostel added!" << std::endl << std::endl;
		}
		// Lister les hôtels
		else if (commande == "hostel list")
		{
			if (listeHotels.size() == 0)
			{
				std::cout << "No hostel available" << std::endl << std::endl;
			}
			else
			{
				for (int i = 0; i < listeHotels.size(); i++)
				{
					std::cout << i << " - " << listeHotels[i] << std::endl;
				}
				std::cout << std::endl;
			}
		}
		// Supprimer un hôtel
		else if (commande == "hostel remove")
		{
			if (listeHotels.size() == 0)
			{
				std::cout << "No hostel available" << std::endl << std::endl;
			}
			else
			{
				for (int i = 0; i < listeHotels.size(); i++)
				{
					std::cout << i << " - " << listeHotels[i] << std::endl;
				}
				std::cout << std::endl << "Select an hostel by its ID : ";

				std::string hotelToRemove;
				std::getline(std::cin, hotelToRemove);
				listeHotels.erase(listeHotels.begin() + std::stoi(hotelToRemove));
				hotelSelectionne = std::to_string(-1);

				std::cout << "Hostel removed." << std::endl << "No selected hostel" << std::endl << std::endl;
			}
		}
		// Sélectionner un hôtel
		else if (commande == "hostel select")
		{
			if (listeHotels.size() == 0)
			{
				std::cout << "No hostel available" << std::endl << std::endl;
			}
			else
			{
				for (int i = 0; i < listeHotels.size(); i++)
				{
					std::cout << i << " - " << listeHotels[i] << std::endl;
				}
				std::cout << std::endl << "Select an hostel by its ID : ";
				std::getline(std::cin, hotelSelectionne);
				std::cout << "Hostel n." << hotelSelectionne << " selected." << std::endl << std::endl;
			}
		}
		// Retourne l'hôtel sélectionné
		else if (commande == "hostel current")
		{
			if (std::stoi(hotelSelectionne) == -1)
			{
				std::cout << "No selected hostel" << std::endl << std::endl;
			}
			else
			{
				std::cout << "Selected hostel : " << hotelSelectionne << std::endl << std::endl;
			}
		}
		// Ajouter une chambre
		else if (commande == "room add")
		{
			if (std::stoi(hotelSelectionne) == -1)
			{
				std::cout << "No selected hostel" << std::endl;
			}
			else
			{
				std::cout << "0 - Single" << std::endl;
				std::cout << "1 - Double" << std::endl;
				std::cout << "2 - Suite" << std::endl << std::endl;
				std::cout << "Room's type (number) : ";
				std::string type;
				std::getline(std::cin, type);

				std::string prix;
				std::cout << "Room's price : ";
				std::getline(std::cin, prix);

				if (std::stoi(type) == 0)
				{
					listeHotels[std::stoi(hotelSelectionne)].ajouterChambre(hotels::typeChambre::Single, std::stoi(prix));
					std::cout << "Room added!" << std::endl;
				}
				else if (std::stoi(type) == 1)
				{
					listeHotels[std::stoi(hotelSelectionne)].ajouterChambre(hotels::typeChambre::Double, std::stoi(prix));
					std::cout << "Room added!" << std::endl;
				}
				else if (std::stoi(type) == 2)
				{
					listeHotels[std::stoi(hotelSelectionne)].ajouterChambre(hotels::typeChambre::Suite, std::stoi(prix));
					std::cout << "Room added!" << std::endl;
				}
				else
				{
					std::cout << "Please select a valid type room" << std::endl;
				}
			}
			std::cout << std::endl;
		}
		// Lister les chambres
		else if (commande == "room list")
		{
			if (std::stoi(hotelSelectionne) == -1)
			{
				std::cout << "No selected hostel" << std::endl;
			}
			else if (listeHotels[std::stoi(hotelSelectionne)].listeChambres().size() == 0)
			{
				std::cout << "No room available" << std::endl;
			} 
			else
			{
				for (int i = 0; i < listeHotels[std::stoi(hotelSelectionne)].listeChambres().size(); i++)
				{
					std::cout << i << " - " << listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i];
				}
			}
			std::cout << std::endl;
		}
		// Editer une chambre
		else if (commande == "room edit")
		{
			if (std::stoi(hotelSelectionne) == -1)
			{
				std::cout << "No selected hostel" << std::endl;
			}
			else if (listeHotels[std::stoi(hotelSelectionne)].listeChambres().size() == 0)
			{
				std::cout << "No room available" << std::endl;
			} 
			else
			{
				for (int i = 0; i < listeHotels[std::stoi(hotelSelectionne)].listeChambres().size(); i++)
				{
					std::cout << i << " - " << listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i];
				}
			}
			std::cout << std::endl << "Select a room by its ID : ";

			std::string roomToEdit;
			std::getline(std::cin, roomToEdit);

			std::string type;
			std::string prix;

			
			bool validType = false;
			while (validType == false)
			{
				std::cout << std::endl << "0 - Single" << std::endl;
				std::cout << "1 - Double" << std::endl;
				std::cout << "2 - Suite" << std::endl << std::endl;
				std::cout << "New room's type (number) : ";
				std::getline(std::cin, type);

				if (std::stoi(type) == 0 || std::stoi(type) == 1 || std::stoi(type) == 2)
				{
					validType = true;
				}
				else
				{
					std::cout << std::endl << "Please select a valid type room." << std::endl;
				}
			}
			
			std::cout << "New room's price : ";
			std::getline(std::cin, prix);

			listeHotels[std::stoi(hotelSelectionne)].editerChambre(std::stoi(roomToEdit), std::stoi(type), std::stof(prix));
			std::cout << "Room edited!" << std::endl << std::endl;
		}
		// Supprimer une chambre
		else if (commande == "room remove")
		{
			if (std::stoi(hotelSelectionne) == -1)
			{
				std::cout << "No selected hostel" << std::endl;
			}
			else if (listeHotels[std::stoi(hotelSelectionne)].listeChambres().size() == 0)
			{
				std::cout << "No room available." << std::endl;
			} 
			else
			{
				for (int i = 0; i < listeHotels[std::stoi(hotelSelectionne)].listeChambres().size(); i++)
				{
					std::cout << i << " - " << listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i];
				}
				std::cout << std::endl << "Select a room by its ID : ";
				std::string roomToRemove;
				std::getline(std::cin, roomToRemove);
				listeHotels[std::stoi(hotelSelectionne)].supprimerChambre(std::stoi(roomToRemove));

				std::cout << "Room removed." << std::endl;
			}
			std::cout << std::endl;
		}
		// Ajouter un client
		else if (commande == "client add")
		{
			std::string nom;
			std::string prenom;

			std::cout << "First name : ";
			std::getline(std::cin, nom);
			std::cout << "Last name : ";
			std::getline(std::cin, prenom);

			Client nouveauClient(listeClients.size() + 1, nom, prenom);
			listeClients.push_back(nouveauClient);

			std::cout << "Client added!" << std::endl << std::endl;
		}
		// Lister les clients
		else if (commande == "client list")
		{
			if (listeClients.size() == 0)
			{
				std::cout << "No client available" << std::endl << std::endl;
			}
			else
			{
				for (int i = 0; i < listeClients.size(); i++)
				{
					std::cout << i << " - " << listeClients[i];
				}
				std::cout << std::endl;
			}
		}
		// Editer un client
		else if (commande == "client edit")
		{
			if (listeClients.size() == 0)
			{
				std::cout << "No client available" << std::endl << std::endl;
			}
			else
			{
				for (int i = 0; i < listeClients.size(); i++)
				{
					std::cout << i << " - " << listeClients[i];
				}
				std::cout << std::endl << "Select a client by its ID : ";

				std::string clientToEdit;
				std::getline(std::cin, clientToEdit);

				std::string prenom;
				std::string nom;

				std::cout << "First name : ";
				std::getline(std::cin, prenom);
				std::cout << "Last name : ";
				std::getline(std::cin, nom);

				listeClients[std::stoi(clientToEdit)].setNom(nom);
				listeClients[std::stoi(clientToEdit)].setPrenom(prenom);

				std::cout << "Client edited!" << std::endl << std::endl;
			}
		}
		// Supprimer un client
		else if (commande == "client remove")
		{
			if (listeClients.size() == 0)
			{
				std::cout << "No client available" << std::endl << std::endl;
			}
			else
			{
				for (int i = 0; i < listeClients.size(); i++)
				{
					std::cout << i << " - " << listeClients[i];
				}
				std::cout << std::endl << "Select a client by its ID : ";

				std::string clientToRemove;
				std::getline(std::cin, clientToRemove);
				listeClients.erase(listeClients.begin() + std::stoi(clientToRemove));

				std::cout << "Client removed." << std::endl << std::endl;
			}
		}
		// Faire une réservation
		else if (commande == "booking make")
		{
			if (std::stoi(hotelSelectionne) == -1)
			{
				std::cout << "No selected hostel" << std::endl;
			}
			else if (listeHotels[std::stoi(hotelSelectionne)].listeChambres().size() == 0)
			{
				std::cout << "No room available for the selected hostel." << std::endl;
			} 
			else
			{
				// Paramètres de la réservation
				std::string yearBegin, monthBegin, dayBegin, yearEnd, monthEnd, dayEnd;
				int tailleSejourComplet;

				// Création des dates
				date::Date beginDate;
				date::Date endDate;

				bool dateValide = false;
				while (dateValide == false)
				{
					std::cout << "Enter a year of start of stay : ";
					std::getline(std::cin, yearBegin);
					beginDate.setYear(std::stoi(yearBegin));
					std::cout << "Enter a month of start of stay : ";
					std::getline(std::cin, monthBegin);
					beginDate.setMonth(std::stoi(monthBegin));
					std::cout << "Enter a day of start of stay : ";
					std::getline(std::cin, dayBegin);
					beginDate.setDay(std::stoi(dayBegin));

					std::cout << "Enter a year of end of stay : ";
					std::getline(std::cin, yearEnd);
					endDate.setYear(std::stoi(yearEnd));
					std::cout << "Enter a month of end of stay : ";
					std::getline(std::cin, monthEnd);
					endDate.setMonth(std::stoi(monthEnd));
					std::cout << "Enter a day of end of stay : ";
					std::getline(std::cin, dayEnd);
					endDate.setDay(std::stoi(dayEnd));

					tailleSejourComplet = endDate - beginDate;

					// Calcul nombre de nuits
					if (endDate.checkDate(std::stoi(monthEnd), std::stoi(dayEnd)) && beginDate.checkDate(std::stoi(monthBegin), std::stoi(dayBegin)) && endDate > beginDate)
					{
						dateValide = true;
						std::cout << std::endl << "Stay size : " << tailleSejourComplet << " days" << std::endl << std::endl;
					}
					else
					{
						std::cout << "Invalid dates, please retype them." << std::endl;
					}
				}

				// Recherche si chambre dispo
				std::string numChambreSelected;
				bool typeChambreBool = false;
				while (typeChambreBool == false)
				{
					std::cout << "Enter the desired room type (0 = Simple, 1 = Double, 2 = Suite) : ";
					std::string typeDeChambre;
					std::getline(std::cin, typeDeChambre);

					std::cout << std::endl;

					if (std::stoi(typeDeChambre) <= 2 && std::stoi(typeDeChambre) >= 0)
					{
						int trouve = 0;
						// On parcourt les chambres pour savoir si elles sont dispos
						for (int i = 0; i < listeHotels[std::stoi(hotelSelectionne)].listeChambres().size(); i++)
						{
							if (std::stoi(typeDeChambre) == 0)
							{
								if (listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i].type() == hotels::typeChambre::Single)
								{
									bool test = listeHotels[std::stoi(hotelSelectionne)].verifierReservation(listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i].ID(), beginDate, endDate);

									if (test == true)
									{
										// La chambre est dispo
										std::cout << "The room n." << listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i].ID() << " is available." << std::endl;
										trouve = 1;
										typeChambreBool = true;
									}
								}
							}
							else if (std::stoi(typeDeChambre) == 1)
							{
								if (listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i].type() == hotels::typeChambre::Double)
								{
									bool test = listeHotels[std::stoi(hotelSelectionne)].verifierReservation(listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i].ID(), beginDate, endDate);

									if (test == true)
									{
										// La chambre est dispo
										std::cout << "The room n." << listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i].ID() << " is available." << std::endl;
										trouve = 1;
										typeChambreBool = true;
									}
								}
							}
							else if (std::stoi(typeDeChambre) == 2)
							{
								if (listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i].type() == hotels::typeChambre::Suite)
								{
									bool test = listeHotels[std::stoi(hotelSelectionne)].verifierReservation(listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i].ID(), beginDate, endDate);

									if (test == true)
									{
										// La chambre est dispo
										std::cout << "The room n." << listeHotels[std::stoi(hotelSelectionne)].listeChambres()[i].ID() << " is available." << std::endl;
										trouve = 1;
										typeChambreBool = true;
									}
								}
							}
						}

						if (trouve == 0)
						{
							std::cout << "Room type is not available." << std::endl;
						}
						else
						{
							std::cout << std::endl << "Select a room by its number : ";
							std::getline(std::cin, numChambreSelected);
							std::cout << "You selected the room n. " << std::stoi(numChambreSelected) << std::endl;
						}
			
					}
				}

				// On chosit le client
				std::string nomClient;
				std::cout << std::endl << "Enter client's last name : ";
				std::getline(std::cin, nomClient);

				// On parcourt les clients et on affiche ceux qui ont le même nom
				std::vector<int> clientOkID;
				int clientOk = 0;

				for (int i = 0; i < listeClients.size(); i++)
				{
					if (listeClients[i].nom() == nomClient)
					{
						std::cout << clientOk << " - " << listeClients[i].nomComplet() << std::endl;
						clientOkID.push_back(i);
						clientOk++;
					}
				}

				std::string selectedClient;
				std::cout << std::endl << "Select a client by its ID : ";
				std::getline(std::cin, selectedClient);

				float price = tailleSejourComplet * listeHotels[std::stoi(hotelSelectionne)].listeChambres()[std::stoi(numChambreSelected) - 1].prix();

				std::cout << std::endl << "Total price : " << price << "$" << std::endl << std::endl << "Room reservation done!" << std::endl;

				// On ajoute la réservation à la liste de réservations de l'hôtel
				bookID++;
				hotels::Booking maNouvelleReservation(bookID, beginDate, endDate, std::stoi(numChambreSelected), listeClients[clientOkID[std::stoi(selectedClient)]].ID(), price, false);
				listeHotels[std::stoi(hotelSelectionne)].ajouterReservation(maNouvelleReservation);
				listeClients[clientOkID[std::stoi(selectedClient)]].ajouterReservation(bookID);
			}
		}
		// Faire une réservation
		else if (commande == "booking list")
		{
			if (std::stoi(hotelSelectionne) == -1)
			{
				std::cout << "No selected hostel" << std::endl;
			}
			else if (listeHotels[std::stoi(hotelSelectionne)].nombreReservations() == 0)
			{
				std::cout << "No booking is available." << std::endl;
			}
			else
			{
				listeHotels[std::stoi(hotelSelectionne)].reservations();
			}
			std::cout << std::endl;
		}
		// Faire une réservation
		else if (commande == "booking cancel")
		{
			if (std::stoi(hotelSelectionne) == -1)
			{
				std::cout << "No selected hostel" << std::endl;
			}
			else if (listeHotels[std::stoi(hotelSelectionne)].nombreReservations() == 0)
			{
				std::cout << "No booking is available." << std::endl;
			}
			else
			{
				listeHotels[std::stoi(hotelSelectionne)].reservations();
				std::cout << std::endl << "Select a booking by its ID : ";
				std::string resaSelectionnee;
				std:getline(std::cin, resaSelectionnee);

				listeHotels[std::stoi(hotelSelectionne)].annulerReservation(std::stoi(resaSelectionnee));

				std::cout << "Booking canceled." << std::endl << std::endl;
			}
		}
		// Efface la console
		else if (commande == "clear")
		{
			system("clear");
			std::cout << "HOSTEL MANAGER" << std::endl << std::endl;
		}
		// Affiche le menu d'aide
		else if (commande == "help")
		{
			std::cout << "HELP MENU" << std::endl << std::endl;
			std::cout << "hostel add     - Add an hostel" << std::endl;
			std::cout << "hostel select  - Select an hostel" << std::endl;
			std::cout << "hostel current - Show selected hostel" << std::endl;
			std::cout << "hostel list    - List hostels" << std::endl;
			std::cout << "hostel remove  - Remove an hostel" << std::endl << std::endl;
			
			std::cout << "room add       - Add a room" << std::endl;
			std::cout << "room list      - List rooms" << std::endl;
			std::cout << "room edit      - Edit a specific room" << std::endl;
			std::cout << "room remove    - Remove a room" << std::endl << std::endl;

			std::cout << "client add     - Add a client" << std::endl;
			std::cout << "client list    - List clients" << std::endl;
			std::cout << "client edit    - Edit a specific client" << std::endl;
			std::cout << "client remove  - Remove a client" << std::endl << std::endl;

			std::cout << "booking make   - Add a booking" << std::endl;
			std::cout << "booking list   - List bookings" << std::endl;
			std::cout << "booking cancel - Cancel a booking" << std::endl << std::endl;

			std::cout << "clear          - Clear the console" << std::endl << std::endl;
			
			std::cout << "exit           - Leave Hostel Manager" << std::endl << std::endl;
		}
		// Commande introuvable
		else
		{
			std::cout << "Command not found. Type \"help\" for help." << std::endl;
		}
	}

	return 0;
}
