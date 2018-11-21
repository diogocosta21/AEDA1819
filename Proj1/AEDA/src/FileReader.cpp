/*
 * FileReader.cpp
 *
 *  Created on: 16/11/2018
 *      Author: joao_
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
		string nome, NIF, numRes;

		line = line.substr(line.find(',') + 2);
		nome = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		NIF = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		numRes = line.substr(0, line.find(';'));

		Cliente * cl = new Cliente (nome, stoi(NIF.c_str()), stoi(numRes.c_str()));
		clientes.push_back(cl);
	}


	return clientes;
}


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
		string capacidade, vid, aud, reserv;

		line = line.substr(line.find(',') + 2);
		capacidade = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		vid = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		aud = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		reserv = line.substr(line.find(';'));

		bool reservado = false;
		if (reserv == "reservada"){
			reservado = true;
		}

		bool video = false;
		if(vid == "com equipamento de video")
			video = true;

		bool audio = false;
		if(aud == "com equipamento de audio")
			audio = true;


		SalaReuniao *s = new SalaReuniao (stoi(capacidade.c_str()), video, audio, reservado);
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

		Funcionario *f = new Funcionario (nome);
		funcionarios.push_back(f);

	}

	return funcionarios;
}


