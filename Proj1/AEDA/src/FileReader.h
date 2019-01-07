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
#include "Hotel.h"
#include "Restaurante.h"

class FileReader
{
private:
	static vector<string> readLines(string file);
public:
	static vector<Cliente *> readClientes(string file);
	static vector<Quarto *> readQuartos(string file);
	static vector<SalaReuniao *> readSalasReuniao(string file);
	static vector<Funcionario *> readFuncionarios (string file);
	static vector<Supervisor *> readSupervisores (string file);
	static vector<Restaurante *> readRestaurantes(string file);
};




#endif /* FILEREADER_H_ */
