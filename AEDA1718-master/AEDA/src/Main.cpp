/*
 * Main.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include <iostream>
#include <vector>

#include "Company.h"
#include "Menu.h"
#include "FileReader.h"

using namespace std;

#define rClientsFile "RegisteredClients.txt"
#define oClientsFile "OccasionalClients.txt"
#define suppliersFile "suppliers.txt"
#define offersFile "offers.txt"
#define reservationsFile "reservations.txt"

int main()
{
	vector <RegisteredClient *> rClients = FileReader::readRegisteredClients(rClientsFile);
	vector <OccasionalClient *> oClients = FileReader::readOccasionalClients(oClientsFile);
	vector <Supplier *> suppliers = FileReader::readSuppliers(suppliersFile);
	vector <Offer *> offers = FileReader::readOffers(offersFile);
	vector <Reservation > reservations = FileReader::readReservations(reservationsFile);


	Company c(rClients,oClients, suppliers, offers, reservations);

	CompanyMenu (&c);

	c.exportRegisteredClients (rClientsFile);
	c.exportOccasionalClients (oClientsFile);
	c.exportSuppliers (suppliersFile);
	c.exportOffers (offersFile);
	c.exportReservations(reservationsFile);

	return 0;
}
