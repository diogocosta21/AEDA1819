/*
 * FileReader.h
 *
 *  Created on: 07/11/2018
 *      Author: joao_
 */

#ifndef FILEREADER_H_
#define FILEREADER_H_


#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

#include "Cliente.h"
#include "Espaco.h"
#include "Funcionario.h"
#include "Data.h"

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




#endif /* FILEREADER_H_ */
