/*
 * FileReader.cpp
 *
 *  Created on: 09/11/2018
 *      Author: up201505198
 */


/*
 * FileReader.cpp
 *
 *  Created on: 06/11/2017
 *      Author: ricar
 */

#include "FileReader.h"

#include <iostream>


using namespace std;

/**
 * Gets line from file and puts it in a vector.

 * @param file file to be read.
 */
vector<string> FileReader::readLines(string file) {
	vector<string> lines;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		string line;

		while (getline(inFile, line)) {
			lines.push_back(line);
		}

		inFile.close();
	}

	return lines;
}

/**
 * Reads information from registered clients.
 * @param file registered clients' file.
 */
vector<Cliente *> FileReader::readClientes(string file)
{
	vector<Cliente *> clientes;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string nome, NIF, dia, mes, ano;

		line = line.substr(line.find(',') + 2);
		nome = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		dia = line.substr(0, line.find('/'));
		line = line.substr(line.find('/') + 1);
		mes = line.substr(0,line.find('/'));
		line = line.substr(line.find('/') + 1);
		ano = line.substr (0, line.find(';'));


		Data d = Data (stoi(dia.c_str()), stoi(mes.c_str()), stoi(ano.c_str()) );
		Cliente * cl = new Cliente (nome, stoi(NIF.c_str()), d);
		clientes.push_back(cl);
	}


	return clientes;
}

/**
 * Reads information from occasional clients.
 * @param file occasional clients' file.
 */
/*
vector<OccasionalClient*> FileReader::readOccasionalClients(string file)
{
	vector<OccasionalClient *> oClients;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string name, NIF, day, address, month, year;

		line = line.substr(line.find(',') + 2);
		name = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		day = line.substr(0, line.find('/'));
		line = line.substr(line.find('/') + 1);
		month = line.substr(0,line.find('/'));
		line = line.substr(line.find('/') + 1);
		year = line.substr (0, line.find(','));
		line = line.substr(line.find(',') + 2);
		address = line.substr(0, line.find(';'));

		Date d = Date(stoi(day.c_str()), stoi(month.c_str()), stoi(year.c_str()) );

		OccasionalClient *oc = new OccasionalClient(name, stoi(NIF.c_str()), d, address);
		oClients.push_back(oc);
	}


	return oClients;
}
*/

/**
 * Reads information from suppliers.
 * @param file suppliers' file.
 */
vector<Quarto *> FileReader::readQuartos(string file)
{
	vector<Quarto *> quartos;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string tipo, local, reserv;

		line = line.substr(line.find(',') + 2);
		tipo = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		local = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		reserv = line.substr(line.find(';'));

		bool reservado = false;
		if (reserv == "reservado"){
			reservado = true;
		}

		Quarto *q = new Quarto (tipo, local, reservado);
		quartos.push_back (q);

	}

	return quartos;
}

/**
 * Reads information from offers.
 * @param file offers' file.
 */
vector<SalaReuniao *> FileReader::readSalasReuniao (string file)
{
	vector<SalaReuniao *> salasreuniao;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string nome, capacidade, reserv;

		line = line.substr(line.find(',') + 2);
		nome = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		capacidade = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		reserv = line.substr(line.find(';'));

		bool reservado = false;
		if (reserv == "reservado"){
			reservado = true;
		}


		SalaReuniao *s = new SalaReuniao (stoi(capacidade.c_str()), reservado);
		salasreuniao.push_back(s);
	}

	return salasreuniao;
}

/**
 * Reads information from the reservation.
 * @param file reservations' file.
 */
vector <Funcionario * > FileReader::readFuncionarios(string file)
{
	vector <Funcionario *> funcionarios;

	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines [i];
		string nome, NIF, sup;

		line = line.substr(line.find(',') + 2);
		nome = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0 ,line.find(','));
		line = line.substr(line.find(',') + 2);
		sup = line.substr(0 ,line.find(';'));

		bool supervisor = false;
		if (sup == "supervisor") {
			supervisor = true;
		}

		Funcionario *f = new Funcionario (nome, stoi(NIF.c_str()), supervisor);
		funcionarios.push_back(f);

	}

	return funcionarios;
}
