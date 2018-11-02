/*
 * FileReader.h
 *
 *  Created on: 06/11/2017
 *      Author: ricar
 */

#ifndef SRC_FILEREADER_H_
#define SRC_FILEREADER_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Client.h"
#include "Supplier.h"
#include "Offer.h"
#include "Date.h"
#include "Reservation.h"
#include "BST.h"

class FileReader
{
private:
	static vector<string> readLines(string file);
public:
	static vector<RegisteredClient *> readRegisteredClients(string file);
	static vector<OccasionalClient *> readOccasionalClients(string file);
	static vector<Supplier *> readSuppliers(string file);
	static vector<Offer *> readOffers(string file);
	static vector <Reservation> readReservations (string file);
};



#endif /* SRC_FILEREADER_H_ */
