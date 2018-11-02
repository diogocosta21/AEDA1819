/*
 * Menu.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Menu.h"

using namespace std;



bool CompanyMenu(Company *c)
{
	unsigned int optionCM = 0;
	bool flag = false;
	Date d = c->getDate();

	while (!flag)
	{
		cout << "Date : " << d.getDay() << "-" << d.getMonth() << "-" << d.getYear() << endl;

		cout << "***********************" << endl;
		cout << "|     Porto Rivers    |" << endl;
		cout << "***********************" << endl << endl;


		cout << "1 Make reservation"   << endl;
		cout << "2 Cancel reservation" << endl;
		cout << "3 Work with us"     << endl;
		cout << "4 View files"         << endl;
		cout << "5 Check bank"		   << endl;
		cout << "6 Exit"               << endl;
		cout << "Insert the desired option: ";

		cin >> optionCM;
		cin.clear();
		cout << endl;

		switch (optionCM)
		{
			case 1:
			{
				MakeReservation (c);
				break;
			}

			case 2:
			{
				CancelReservation (c);
				break;
			}

			case 3:
			{
				unsigned int optionCM3 = 0;
				bool flag2 = false;
				while (!flag2)
				{
					cout << "***********************" << endl;
					cout << "|     Work with us    |" << endl;
					cout << "***********************" << endl << endl;

					cout << "1 Become a supplier" << endl;
					cout << "2 Add offer" << endl;
					cout << "3 Back" << endl;
					cout << "Insert the desired option: ";

					cin >> optionCM3;
					cin.clear();
					cin.ignore(10000,'\n');

					switch (optionCM3)
					{
						case 1:
						{
							AddSupplier(c);
							break;
						}

						case 2:
						{
							AddOffer(c);
							break;
						}

						case 3:
						{
							flag2 = true;
							break;
						}

						default:
						{
							try
							{
								throw InvalidOption(optionCM3);
							}
							catch (InvalidOption &e)
							{
								std::cout << endl <<  e.getOption() << " is not a valid option"<< std::endl;
								break;
							}
						}
					}
				}
				break;
			}

			case 4:
			{
				ViewFilesMenu (c);
				break;
			}

			case 5:
			{
				cout << "Bank: " << c->getBank() << "€" << endl << endl;
				break;
			}
			case 6:
			{
				flag= true;
				break;
			}
			default:
			{
				try{
					throw InvalidOption(optionCM);
				}
				catch(InvalidOption &e)
				{
					std::cout << e.getOption() <<  " is not a valid option"  <<  std::endl;
					break;
				}
			}
		}
	}

	return true;
}

bool MakeReservation (Company *c)
{
	unsigned int optionMR = 0;
	bool flag = false;

	while (!flag)
	{
		cout << "***********************" << endl;
		cout << "|   Make Reservation  |" << endl;
		cout << "***********************" << endl << endl;

		cout << "What type of client are you?" << endl;
		cout << "1 Registered Client" << endl;
		cout << "2 Occasional Client" << endl;
		cout << "3 First time user" << endl;
		cout << "4 Back" << endl;
		cout << "Insert the desired option: ";

		cin >> optionMR;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << endl;

		switch (optionMR)
		{
			case 1:
			{
				unsigned int idClient;

				c->printRegisteredClients();

				bool verifier = false;
				while (!verifier)
				{

					cout << endl << "Insert your id: ";
					cin >> idClient;
					cin.clear();
					cin.ignore(10000, '\n');
					cout << endl;

					if (idClient > c->getRegisteredClients().size() || idClient <= 0)
						cout << "Invalid id";
					else
						verifier = true;
				}

				MakeReservation_Registered(c, idClient);
				break;
			}

			case 2:
			{
				unsigned int optionMR2 = 0;
				cout << "Would you like to register? " << endl;
				cout << "1 Yes" << endl;
				cout << "2 No" << endl;
				cout << "Insert the desired option: ";
				cin >> optionMR2;
				cin.clear();
				cin.ignore(10000, '\n');
				cout << endl;

				if( optionMR2 == 2)
				{
					unsigned int idClient;

					c->printOccasionalClients();

					while (1)
					{
						cout << endl << "Insert your id: ";
						cin >> idClient;
						cin.clear();
						cin.ignore(10000, '\n');

						if (idClient > c->getOccasionalClients().size() || idClient <= 0 )
							cout << endl << "Invalid id";
						else
							break;
					}

					MakeReservation_Occasional(c, idClient);
					break;
				}
				else if (optionMR2 == 1)
				{
					unsigned int idOc;
					c->printOccasionalClients();

					bool verifier = false;

					while (!verifier)
					{
						cout << endl << "Insert your id: ";
						cin >> idOc;
						cin.clear();
						cin.ignore(10000, '\n');

						if (idOc <= 0 || idOc > c->getOccasionalClients().size())
							cout << "Invalid id" << endl << endl;
						else
							verifier = true;
					}
					string name = c->getOccasionalClients()[idOc-1]->getName();
					int NIF = c->getOccasionalClients()[idOc-1]->getNIF();
					string address = c->getOccasionalClients()[idOc-1]->getAddress();

					int idReg = c->RegisterClient(name, NIF, address);
					c->removeOccasionalClient(idOc);

					cout << "Your new client id is: " << idReg << endl << endl;

					MakeReservation_Registered(c, idReg);
					break;
				}
				else
				{
					try{
						throw InvalidOption(optionMR2);
					}
					catch(InvalidOption &e)
					{
						std::cout << e.getOption() <<  " is not a valid option"  <<  std::endl;
						break;
					}
				}
				break;
			}

			case 3:
			{
				unsigned int optionMR3 = 0;
				cout << "Would you like to register? " << endl;
				cout << "1 Yes" << endl;
				cout << "2 No" << endl;
				cout << "Insert the desired option: ";
				cin >> optionMR3;
				cin.clear();
				cin.ignore(10000, '\n');


				if (optionMR3 != 1 && optionMR3 != 2)
				{
					try
					{
						throw InvalidOption(optionMR3);
					}
					catch (InvalidOption &e)
					{
						std::cout << endl << e.getOption() << " is not a valid option"<< std::endl;
						break;
					}
				}

				string name, address;
				int NIF;
				cout << "Please enter your name: ";
				getline (cin, name);

				while (1)
				{
					cout << "Please enter your NIF: ";
					cin >> NIF;
					cin.clear();
					cin.ignore(10000, '\n');

					if (NIF >= 100000000 && NIF <= 999999999)
						break;
					else
						cout << "Invalid NIF" << endl << endl;
				}

				cout << "Please enter your address: ";
				cin >> address;
				cin.clear();
				cin.ignore(10000, '\n');
				cout << endl;

				if( optionMR3 == 2)
				{
					c->addOccasionalClient(name,NIF, address);
					cout << "Your new client id is: " << c->getOccasionalClients().size() << endl;
					MakeReservation_Occasional(c, c->getOccasionalClients().size());
				}
				else if (optionMR3 == 1)
				{
					int id = c->RegisterClient(name, NIF, address);
					cout << "Your new client id is: " << id << endl << endl;
					MakeReservation_Registered(c, id);
				}

				break;
			}
			case 4:
			{
				flag = true;
				break;
			}

			default:
			{
				try {
					throw InvalidOption(optionMR);
				} catch (InvalidOption &e) {
					std::cout << e.getOption() << " is not a valid option"<< std::endl;
					break;
				};
			}
		}
	}
	return true;
}

bool MakeReservation_Registered (Company *c, unsigned int idClient)
{
	unsigned int idOffer=0, nTick;
	string d1, d2;

	cout << c->getRegisteredClients()[idClient-1]->getInformation() << endl << endl;

	cout << "Enter the range of dates you're interested in " << endl;
	cout << "Initial date (format DD-MM-YYYY): ";
	cin >> d1;
	cin.clear();
	cin.ignore(10000, '\n');
	Date date1 = Date(d1);
	while (date1.validateDate() == false)
	{
		cout << "The date that you have entered is not valid, please enter a new initial date (format DD-MM-YYYY):";
		cin >> d1;
		cin.clear();
		cin.ignore(10000, '\n');
		date1 = Date (d1);
	}

	cout << "Final date (format DD-MM-YYYY): ";
	cin >> d2;
	cin.clear();
	cin.ignore(10000, '\n');
	Date date2 = Date (d2);
	while (date2.validateDate() == false)
	{
		cout << "The date that you have entered is not valid, please enter a new final date (format DD-MM-YYYY):";
		cin >> d2;
		cin.clear();
		cin.ignore(10000, '\n');
		date2 = Date (d2);
	}
	cout << endl;

	vector <int> v = c->printOfferbyDate(d1,d2);

	while(1)
	{
		cout << "Insert the id of the corresponding offer (enter 0 to exit): ";
		cin >> idOffer;
		cin.clear();
		cin.ignore(10000, '\n');

		if (idOffer > c->getOffers().size() || idOffer < 0)
				cout << endl << "Invalid offer id" << endl << endl;

		else if(idOffer == 0)
			return true;

		else
		{
			bool v_flag = false;
			for (unsigned int i = 0; i < v.size(); i++)
			{
				if (idOffer == v[i])
				{
					v_flag = true;
					break;
				}
			}
			if (v_flag)
				break;
			else
				cout << endl << "That offer is not on the range you inserted. Return to make reservation menu to enter a different range." << endl << endl;
		}
	}


	Offer * offer = c->getOffers()[idOffer-1];

	cout << "How many tickets do you desire: ";
	cin >> nTick;
	cin.clear();
	cin.ignore(10000, '\n');

	if(nTick > offer->getVacancies())
		try{
			throw NoSeatsAvailable (idOffer);
		}
		catch (NoSeatsAvailable &e)
		{
			std::cout << std::endl << "Sorry, the offer #" << e.getId() << " doesn't have enough seats available." << std::endl;
			return false;
		}

	unsigned int optionMR_R;

	unsigned int price = ( offer->getPrice() - offer->getPrice() * offer->getDiscount() ) * nTick;

	cout << endl << "Total: " << price << "€,  Points Won: " << offer->getPoints() * nTick << endl <<endl;


	while (1)
	{
		cout << "Want to confirm your reservation?: " << endl;
		cout << "1 Yes" << endl;
		cout << "2 No (return to make reservation menu)" << endl;
		cout << "Insert the desired option: ";
		cin >> optionMR_R;
		cin.clear();
		cin.ignore(10000, '\n');

		if(optionMR_R == 1)
		{
			RegisteredClient * client = c->getRegisteredClients()[idClient-1];
			Reservation r (offer, client, offer->getDate());
			r.setTickets(nTick);
			c->addReservation(r,nTick);

			client->setPoints(client->getPoints() + offer->getPoints()*nTick);
			client->setLastReservation(c->getDate());

			offer->setVacancies( offer->getVacancies() - nTick);
			offer->setLastReservation(c->getDate());
			offer->setDiscount(0);

			c->removeInactiveClient(client->getName());
			c->removeUnpopularOffer(offer->getId());
			c->setBank (offer->getPercentage() * price );

			return true;
		}

		else if (optionMR_R == 2)
		{
			cout << endl;
			return true;
		}

		else
			cout << endl << "Invalid Option." << endl;
	}

}

bool MakeReservation_Occasional (Company *c, unsigned int idClient)
{
	int idOffer = 0, nTick;
	string d1,d2;

	cout << endl;
	cout << c->getOccasionalClients()[idClient-1]->getInformation() << endl << endl;

	cout << "Enter the range of dates you're interested in: " << endl;
	cout << "Initial date (format DD-MM-YYYY): ";
	cin >> d1;
	Date date1 = Date(d1);
	while (date1.validateDate() == false)
	{
		cout << "The date that you have entered is not valid, please enter a new initial date (format DD-MM-YYYY):";
		cin >> d1;
		cin.clear();
		cin.ignore(10000, '\n');
		date1 = Date (d1);
	}


	cout << "Final date (format DD-MM-YYYY): ";
	cin >> d2;
	Date date2 = Date (d2);
	while (date2.validateDate() == false)
	{
		cout << "The date that you have entered is not valid, please enter a new final date (format DD-MM-YYYY):";
		cin >> d2;
		cin.clear();
		cin.ignore(10000, '\n');
		date2 = Date (d2);
	}
	cout << endl;

	vector <int> v = c->printOfferbyDate(d1,d2);

	while(1)
	{
		cout << "Insert the id of the corresponding offer (enter 0 to exit): ";
		cin >> idOffer;
		cin.clear();
		cin.ignore(10000, '\n');

		if (idOffer > c->getOffers().size() || idOffer < 0)
				cout << "Invalid offer id" << endl << endl;

		else if (idOffer == 0)
			return true;

		else
		{
			bool v_flag = false;
			for (unsigned int i = 0; i < v.size(); i++)
			{
				if (idOffer == v[i])
				{
					v_flag = true;
					break;
				}
			}
			if (v_flag)
				break;
			else
				cout << "That offer is not on the range you inserted. Return to make reservation menu to enter a different range." << endl << endl;
		}
	}

	Offer * offer = c->getOffers()[idOffer-1];

	cout << "How many tickets do you desire: ";
	cin >> nTick;
	cin.clear();
	cin.ignore(10000, '\n');

	if(nTick > offer->getVacancies())
		try
		{
			throw NoSeatsAvailable (idOffer);
		}
		catch (NoSeatsAvailable &e)
		{
			std::cout << std::endl << "Sorry, the offer #" << e.getId() << " doesn't have enough seats available." << std::endl;
			return false;
		}

	unsigned int optionMR_O;
	unsigned int price = ( offer->getPrice() - offer->getPrice() * offer->getDiscount() ) * nTick;

	cout << endl << "Total: " << price << "€" << endl << endl;

	while (1)
	{
		cout << "Want to confirm your reservation?: " << endl;
		cout << "1 Yes" << endl;
		cout << "2 No (return to make reservation menu)" << endl;
		cout << "Insert the desired option: ";
		cin >> optionMR_O;
		cin.clear();
		cin.ignore(10000, '\n');

		if(optionMR_O == 1)
		{
			OccasionalClient * client = c->getOccasionalClients()[idClient-1];
			Reservation r (offer, client, offer->getDate());
			r.setTickets(nTick);
			c->addReservation(r,nTick);

			client->setLastReservation(c->getDate());

			offer->setVacancies( offer->getVacancies() - nTick);
			offer->setLastReservation(c->getDate());
			offer->setDiscount(0);

			c->removeInactiveClient(client->getName());
			c->removeUnpopularOffer(offer->getId());

			c->setBank (offer->getPercentage() * offer->getPrice() * nTick );
			return true;
		}

		else if (optionMR_O == 2)
		{
			cout << endl;
			return true;
		}
		else
		{
			cout << endl << "Invalid Option." << endl;
		}
	}
}

bool CancelReservation (Company *c)
{
	unsigned int optionC = 0;
	bool flag = false;

	while (!flag)
	{
		cout << "************************" << endl;
		cout << "|  Cancel Reservation  |" << endl;
		cout << "************************" << endl << endl;

		cout << "What type of client are you?" << endl;
		cout << "1 Registered Client" << endl;
		cout << "2 Occasional Client" << endl;
		cout << "3 Back" << endl;
		cout << "Insert the desired option: ";
		cin >> optionC;
		cin.clear();
		cin.ignore(10000, '\n');

		switch(optionC)
			{
				case 1:
				{
					CancelReservationRegClient(c);
					break;
				}
				case 2:
				{
					CancelReservationOccClient(c);
					break;
				}
				case 3:
					return true;
				default:
					try{
						throw InvalidOption(optionC);
					}
					catch(InvalidOption &e)
					{
						std::cout << e.getOption() <<  " is not a valid option"  <<  std::endl << endl;
						break;
					}
			}
	}
}

bool CancelReservationRegClient(Company *c)
{
	int idClient, idOffer, nTick;

	cout << endl;
	c->printRegisteredClients();
	cout << endl;

	cout << "Insert your client id? ";
	cin >> idClient;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl;

	if (idClient > c->getRegisteredClients().size() || idClient <= 0)
	{
		cout << "Invalid client id" << endl <<endl;
		return true;
	}
	cout << c->getRegisteredClients()[idClient-1]->getInformation() << endl << endl;

	bool result = c->printOffersByClient(c->getRegisteredClients()[idClient-1]->getName() );

	if (!result)
		return true;

	Offer * offer;

	do
	{
		while (1)
		{
			cout << "Insert the id of the corresponding offer (enter 0 to exit): ";
			cin >> idOffer;
			cin.clear();
			cin.ignore(10000, '\n');

			if (idOffer == 0)
			{
				cout << endl;
				return true;
			}
			else if (idOffer >0 && idOffer < c->getOffers().size())
				break;
			else
				cout << endl << "Invalid id" << endl;
		}

		 offer = c->getOffers()[idOffer-1];


		cout << "How many tickets do you want to cancel? " ;
		cin >> nTick;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << endl;


		RegisteredClient * client = c->getRegisteredClients()[idClient-1];
		Reservation r (offer, client, offer->getDate());
		int result = c->removeReservation(r,nTick);

		if (result == 2)
			cout << "You didn't make that much reservations." << endl << endl;
		else if (result == 0)
			cout << "You don't have any reservation for this offer. Try again" << endl << endl;
		else
		{
			unsigned int newPoints = c->getRegisteredClients()[idClient-1]->getPoints() - nTick*offer->getPoints();
			c->getRegisteredClients()[idClient-1]->setPoints( newPoints) ;


			cout << "Your cancelation was successful!" << endl;

			offer->setVacancies(offer->getVacancies() + nTick);

			break;
		}

	}while (1);

	Date d2 = offer->getDate();

	unsigned int diffDates = c->getDate().daysBetween(d2);

	if (diffDates >=7 )
		{
			unsigned int devol = (offer->getPrice() * nTick);
			c->setBank( (-1) * offer->getPercentage() * devol);
			cout << "The refund amount is: " << devol << "€" << endl;
		}
	else if (7 > diffDates && diffDates > 2)
		{
			unsigned int devol = (offer->getPrice() * nTick * 0.5);
			c->setBank( (-1) * offer->getPercentage() * devol);
			cout << "The refund amount is: " << devol << "€" << endl;
		}
	else
		{
			cout << "Your cancelation was done too late. You have no refund." << endl;
		}
	cout << endl;
	return true;
}

bool CancelReservationOccClient(Company *c)
{

	int idClient, idOffer, nTick;

	cout << endl;
	c->printOccasionalClients();
	cout << endl;

	cout << "What's you client id? ";
	cin >> idClient;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl;

	if (idClient > c->getOccasionalClients().size() || idClient <= 0)
	{
			cout << "Invalid client id" << endl <<endl;
			return true;
	}
	cout << c->getOccasionalClients()[idClient-1]->getInformation() << endl << endl;

	bool result = c->printOffersByClient(c->getOccasionalClients()[idClient-1]->getName() );

	if (!result)
		return true;

	Offer * offer;

	do
	{
		while (1)
		{
			cout << endl << "Insert the id of the corresponding offer (enter 0 to exit): ";
			cin >> idOffer;
			cin.clear();
			cin.ignore(10000, '\n');

			if (idOffer == 0)
			{
				cout << endl;
				return true;
			}

			else if (idOffer >0 && idOffer < c->getOffers().size())
				break;
			else
				cout << endl << "Invalid id" << endl;
		}

		offer = c->getOffers()[idOffer-1];

		cout << "How many tickets do you want to cancel? " ;
		cin >> nTick;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << endl;

		OccasionalClient * client = c->getOccasionalClients()[idClient-1];
		Reservation r (offer, client, offer->getDate());
		int result = c->removeReservation(r,nTick);

		if (result == 2)
			cout << "You didn't make that much reservations." << endl;
		else if (result == 0)
			cout << "You don't have any reservation for this offer. Try again" << endl;

		else
		{
			offer->setVacancies(offer->getVacancies() + nTick);
			break;
		}
	} while (1);

	Date d2 = offer->getDate();

	unsigned int diffDates = c->getDate().daysBetween(d2);

	if (diffDates >=7 )
	{
		unsigned int devol = offer->getPrice() * nTick;
		c->setBank( (-1) * offer->getPercentage() * devol);
		cout << "The refund amount is: " << devol << "€ " << endl;
	}

	else if (7 > diffDates && diffDates > 2)
	{
		unsigned int devol = offer->getPrice() * nTick * 0.5;
		c->setBank( (-1) * offer->getPercentage() * devol);
		cout << "The refund amount is: " << devol << "€ " << endl;
	}
	else
	{
		cout << "Your cancelation was done too late. You have no refund." << endl;
	}
	cout << endl;
	return true;
}

bool ViewFilesMenu (Company *c)
{
	unsigned int optionVFM;
	bool flag = false;

	while (!flag)
	{
		cout << "************************" << endl;
		cout << "|      View Files      |" << endl;
		cout << "************************" << endl << endl;

		cout << "1 Clients" << endl;
		cout << "2 Suppliers" << endl;
		cout << "3 Offers" << endl;
		cout << "4 Reservations" << endl;
		cout << "5 Back" << endl;
		cout << "Insert the desired option: ";
		cin >> optionVFM;
		cin.clear();
		cin.ignore(10000, '\n');

		switch(optionVFM)
		{
			case 1:
			{
				int optionVFM1;
				bool flag2 = false;

				while (!flag2)
				{
					cout << endl;
					cout << "************************" << endl;
					cout << "|        Clients       |" << endl;
					cout << "************************" << endl << endl;

					cout << "1 View all clients" << endl;
					cout << "2 View clients by points" << endl;
					cout << "3 View inactive clients" << endl;
					cout << "4 Back" << endl;
					cout << "Insert the desired option: " << endl;
					cin >> optionVFM1;
					cin.clear();
					cin.ignore(10000, '\n');

					switch (optionVFM1)
					{
						case 1:
						{

							cout << endl << "Registered Clients:" <<  endl << endl;
							c->printRegisteredClients();

							cout << endl << "Occasional Clients:" << endl << endl;
							c->printOccasionalClients();

							cout << endl ;
							break;
						}

						case 2:
						{
							cout << endl;
							c->printRegisteredClientByPoints();
							cout << endl;

							break;
						}
						case 3:
						{
							c->printInactiveClients();

							do
							{
								string name;

								cout << endl << "Enter the name of the client whose address you want to change (enter 'exit' to exit): ";
								getline (cin,name);

								if (name == "exit")
									break;

								bool result = c->searchInactiveClient(name);

								if (!result)
									cout << "That name is not valid." << endl;
								else
								{
									string address;
									cout << "Enter the new address: ";
									getline (cin, address);

									c->updateAddressClient(name, address);
									break;
								}
							} while (1);

							break;
						}
						case 4:
						{
							flag2 = true;
							break;
						}
						default:
							try
							{
								throw InvalidOption(optionVFM1);
							}
							catch (InvalidOption &e)
							{
								std::cout << endl << e.getOption() << " is not a valid option"<< std::endl;
								break;
							}
					}
				}
				break;
			}

			case 2:
			{
				cout <<endl;
				c->printSuppliers();
				cout << endl;
				break;
			}

			case 3:
			{
				int optionVFM3;
				bool flag2 = false;

				while (!flag2)
				{
					cout << endl;
					cout << "************************" << endl;
					cout << "|        Offers        |" << endl;
					cout << "************************" << endl << endl;

					cout << "1 View all offers" << endl;
					cout << "2 View offers by suppliers" << endl;
					cout << "3 View unpopular offers" << endl;
					cout << "4 Back" << endl;
					cout << "Insert the desired option: " ;
					cin >> optionVFM3;
					cin.clear();
					cin.ignore(10000, '\n');

					switch (optionVFM3)
					{
						case 1:
						{
							int idOffer;
							c->printOffers();
							cout << endl << endl << "Enter the id of the offer to see who bought the tickets (enter 0 to exit): ";
							cin >> idOffer;

							if( idOffer == 0){
								break;
							}
							else if (idOffer < 0 || idOffer > c->getOffers().size() )
							{
								try
								{
									throw InvalidOption(optionVFM3);
								}
								catch (InvalidOption &e)
								{
									std::cout << endl << e.getOption() << " is not a valid option"<< std::endl;
									break;
								}
							}
							else
								c->printClientsByOffer(idOffer);
							break;
						}

						case 2:
						{
							int idSupplier;
							c->printSuppliers();
							cout << endl  << "Enter the id of the desired supplier: ";
							cin >> idSupplier;
							cin.clear();
							cin.ignore(10000, '\n');

							cout << endl;
							c->printOffersBySuppliers( c->getSuppliers()[idSupplier-1]->getName());
							break;
						}
						case 3:
						{
							c->printUnpopularOffers();
							break;
						}

						case 4:
						{
							flag2 = true;
							cout << endl;
							break;
						}
						default:
						{
							try
							{
								throw InvalidOption(optionVFM3);
							}
							catch (InvalidOption &e)
							{
								std::cout <<  endl << e.getOption() << " is not a valid option"<< std::endl;
								break;
							}
						}
					}
				}
				break;
			}
			case 4:
			{
				cout << endl;
				c->printReservations();
				cout << endl;
				break;
			}

			case 5:
				return true;

			default:
			{
				try
				{
					throw InvalidOption(optionVFM);
				}
				catch (InvalidOption &e)
				{
					std::cout << endl << e.getOption() << " is not a valid option"<< std::endl;
					break;
				}
			}
		}
	}
}

bool AddSupplier(Company *c)
{
	string name;
	int NIF;
	string address;

	cout << "Please enter the supplier's name: ";
	getline(cin, name);
	cin.clear();

	while (1)
	{
		cout << "Please enter the supplier's NIF: ";
		cin >> NIF;
		cin.clear();
		cin.ignore(10000, '\n');

		if (NIF >= 100000000 && NIF <= 999999999)
			break;
		else
			cout << "Invalid NIF" << endl << endl;
	}

	cout << "Please enter the supplier's address: ";
	getline(cin, address);
	cin.clear();

	c->AddSupplier(name, NIF, address);

	unsigned int option;

	while (1)
	{
		while(1)
		{
			cout << "Want to add offers?" << endl;
			cout << "1 Yes" << endl;
			cout << "2 No " << endl;
			cout << "Enter the desired option: ";
			cin >> option;

			if(option != 1 && option != 2)
				cout << "Invalid option" << endl;
			else
				break;
		}
		if (option == 2)
		{
			return true;
			break;
		}
		else
		{
			unsigned int cap, dist, pri, points;
			double perc;
			string dest, bT, date;
			int b_option, d_option;

			do
			{
				cout << endl << "Enter the destination: " << endl;
				cout << "1 Régua" << endl;
				cout << "2 Barca d'Alva " << endl;
				cout << "3 Pinhão" << endl;
				cout << "Enter the desired option: ";
				cin >> d_option;

				if (d_option < 1 || d_option > 3)
					cout << "Invalid option. Try again" << endl;
				else
					switch (d_option)
					{
						case 1:
							dest = "Régua";
						case 2:
							dest = "Barca d'Alva";
						case 3:
							dest = "Pinhão";
					}
			} while (d_option < 1 || d_option > 3);

			do
			{

				cout << endl << "Enter the type of boat: " << endl;
				cout << "1 Veleiro" << endl;
				cout << "2 Barco Rabelo" << endl;
				cout << "3 Iate" << endl;
				cout << "Enter the desired option: ";
				cin >> b_option;

				if (b_option < 1 || b_option > 3)
					cout << "Invalid option. Try again" << endl;

				else
					switch(b_option)
					{
						case 1:
							bT = "Veleiro";
						case 2:
							bT = "Barco Rabelo";
						case 3:
							bT = "Iate";
					}
			} while (b_option < 1 || b_option > 3);

			cout << "Enter the boat's capacity: ";
			cin >> cap;

			cout << "Enter the distance to travel: ";
			cin >> dist;

			cout << "Enter the price: ";
			cin >> pri;

			cout << "Enter the points/ticket available for registered clients: ";
			cin >> points;

			cout << "Enter the percentage of each ticket that goes to 'Porto Rivers': ";
			cin >> perc;

			cout << "Enter the date of this offer (format DD-MM-YYYY): ";
			cin >> date;
			Date d(date);
			while (d.validateDate() == false)
				{
					cout << "The date that you have entered is not valid, please enter a new final date (format DD-MM-YYYY):";
					cin >> date;
					cin.clear();
					cin.ignore(10000, '\n');
					d= Date (date);
				}


			c->addOffer(pri, dist, cap, points, perc, bT, dest, name,d);
		}
	}
	cout << endl;
	return true;
}

bool AddOffer(Company *c)
{
	unsigned int option;
	unsigned int idSupplier;
	string name;

	c->printSuppliers();

	while(1)
	{
		cout <<  "Please enter the supplier's id: ";
		cin >> idSupplier;
		cin.clear();
		cin.ignore(10000, '\n');
		if (idSupplier > 0 && idSupplier <= c->getSuppliers().size())
		{
			break;
		}
		else
			cout << "Invalid id." << endl << endl;
	}

	Supplier * sup = c->getSuppliers()[idSupplier-1];

	name = sup->getName();

	while (1)
	{
		unsigned int cap, dist, pri, points;
		double perc;
		string dest, bT, date;
		int b_option, d_option;

		do
		{
			cout << endl << "Enter the destination: " << endl;
			cout << "1 Régua" << endl;
			cout << "2 Barca d'Alva " << endl;
			cout << "3 Pinhão" << endl;
			cout << "Enter the desired option: ";
			cin >> d_option;

			if (d_option < 1 || d_option > 3)
				cout << "Invalid option. Try again" << endl;

			else
				switch (d_option)
				{
					case 1:
						dest = "Régua";
					case 2:
						dest = "Barca d'Alva";
					case 3:
						dest = "Pinhão";
				}
			} while (d_option < 1 || d_option > 3);

			do
			{
				cout << endl << "Enter the type of boat: " << endl;
				cout << "1 Veleiro" << endl;
				cout << "2 Barco Rabelo" << endl;
				cout << "3 Iate" << endl;
				cout << "Enter the desired option: ";
				cin >> b_option;

				if (b_option < 1 || b_option > 3)
					cout << "Invalid option. Try again" << endl;

				else
					switch(b_option)
					{
						case 1:
							bT = "Veleiro";
						case 2:
							bT = "Barco Rabelo";
						case 3:
							bT = "Iate";
					}
			} while (b_option < 1 || b_option > 3);

			cout << "Enter the boat's capacity: ";
			cin >> cap;

			cout << "Enter the distance to travel (km): ";
			cin >> dist;

			cout << "Enter the price (€): ";
			cin >> pri;

			cout << "Enter the points/ticket available for registered clients: ";
			cin >> points;

			cout << "Enter the percentage of each ticket that goes to 'Porto Rivers': ";
			cin >> perc;

			cout << "Enter the date of this offer (format DD-MM-YYYY): ";
			cin >> date;
			Date d(date);
			while (d.validateDate() == false)
			{
				cout << "The date that you have entered is not valid, please enter a new final date (format DD-MM-YYYY):";
				cin >> date;
				cin.clear();
				cin.ignore(10000, '\n');
				d = Date (date);
			}

			do
			{
				unsigned int option2;

				cout << endl << "Want to confirm your reservation?: " << endl;
				cout << "1 Yes" << endl;
				cout << "2 No (return to Work with us menu)" << endl;
				cout << "Insert the desired option: ";
				cin >> option2;
				cin.clear();
				cin.ignore(10000, '\n');

				if(option2 != 1 && option2 != 2)
					cout << "Invalid option. Try again" << endl;
				else if (option2 == 1)
				{
					c->addOffer(pri, dist, cap, points, perc, bT, dest, name,d);
					break;
				}
				else
					break;
			}while(1);

			cout << endl;
			return true;
		}
}


