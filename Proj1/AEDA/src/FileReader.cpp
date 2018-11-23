/*
 * FileReader.cpp
 *
 *  Created on: 16/11/2018
 *      Author: joao_
 */

#include "FileReader.h"

#include <iostream>


using namespace std;

Hotel *h;

/**
 * Lê linha do ficheiro e poe num vetor
 * @param file - ficheiro a ser lido
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
 * Lê inforfmaçao dos clientes
 * @param file - ficheiro dos clientes
 */
vector<Cliente *> FileReader::readClientes(string file)
{
	vector<Cliente *> clientes;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string nome, NIF, numRes;

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
 * Lê informaçao dos quartos
 * @param file - ficheiro dos quartos
 */
vector<Quarto *> FileReader::readQuartos(string file)
{
	vector<Quarto *> quartos;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string tipo, local, reserv, nome;

		nome = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		reserv = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		tipo = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		local = line.substr(0, line.find(';'));

		bool reservado = false;
		if (reserv == "Reservado"){
			reservado = true;
		}

		Quarto *q = new Quarto (tipo, local, reservado, nome);
		quartos.push_back (q);

	}

	return quartos;
}

/**
 * Lê informaçao das salas de reuniao
 * @param file - ficheiro das salas de reuniao
 */
vector<SalaReuniao *> FileReader::readSalasReuniao (string file)
{
	vector<SalaReuniao *> salasreuniao;
	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines[i];
		string capacidade, vid, aud, reserv, nome;
		int c;

		nome = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		reserv = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		capacidade = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		vid = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		aud = line.substr(0, line.find(';'));

		bool reservado = false;
		if (reserv == "Reservada"){
			reservado = true;
		}

		bool video = false;
		if(vid == "Com equipamento de video")
			video = true;

		bool audio = false;
		if(aud == "Com equipamento de audio")
			audio = true;

		c = stoi(capacidade.c_str());

		SalaReuniao *s = new SalaReuniao (c, video, audio, reservado, nome);
		salasreuniao.push_back(s);
	}

	return salasreuniao;
}

/**
 * Lê informaçao dos funcionarios
 * @param file - ficheiro dos funcionarios
 */
vector <Funcionario * > FileReader::readFuncionarios(string file)
{
	vector <Funcionario *> funcionarios;

	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines [i];
		string nome;

		nome = line.substr(0, line.find(';'));

		Funcionario *f = new Funcionario (nome);
		funcionarios.push_back(f);

	}

	return funcionarios;
}

/**
 * Lê informaçao dos supervisores
 * @param file - ficheiro dos supervisores
 */
vector <Supervisor * > FileReader::readSupervisores(string file)
{
	vector <Supervisor *> supervisores;

	vector<string> lines = FileReader::readLines(file);

	for (unsigned int i = 0; i < lines.size(); i++)
	{
		string line = lines [i];
		string nome, numQuartos;

		nome = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 2);
		numQuartos = line.substr(0 ,line.find(';'));

		Supervisor *s = new Supervisor (nome, stoi(numQuartos.c_str()));
		supervisores.push_back(s);

	}

	return supervisores;
}


