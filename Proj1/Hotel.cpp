/*
 * Hotel.cpp
 *
 *  Created on: 07/11/2018
 *      Author: joao_
 */


#include "Hotel.h"

Hotel::Hotel(vector<Cliente *> clientes, vector<Funcionario *> funcionarios, vector<Quarto *> quartos, vector<SalaReuniao *> salasreuniao)
{
	this->clientes=clientes;
	this->funcionarios=funcionarios;
	this->quartos=quartos;
	this->salasreuniao=salasreuniao;
	data = Data("16-11-2018");
}


Hotel::~Hotel(){}


void Hotel::exportClientes(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < clientes.size(); i++)
	{
		os << *clientes[i] << endl;
	}

	os.close();
}


void Hotel::exportFuncionarios(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < funcionarios.size(); i++)
	{
		os << funcionarios[i] << endl;
	}

	os.close();
}

void Hotel::exportQuartos(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < quartos.size(); i++)
	{
		os << quartos[i] << endl;
	}

	os.close();
}


void Hotel::exportSalasReuniao(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < salasreuniao.size(); i++)
	{
		os << salasreuniao[i] << endl;
	}

	os.close();
}


void Hotel::addCliente(string nome, int NIF)
{
	Cliente * cl = new Cliente(nome, NIF, Data("0-0-0000"));
	clientes.push_back(cl);
}


void Hotel::addFuncionario(string nome, bool supervisor)
{
	Funcionario * func = new Funcionario(nome, supervisor);
	funcionarios.push_back(func);
}


void Hotel::addQuarto(string tipo, string lugar)
{
	Quarto * quarto = new Quarto(tipo, lugar);
	quartos.push_back(quarto);
}


void Hotel::addSalaReuniao(int capacidade)
{
	SalaReuniao * sr = new SalaReuniao(capacidade);
	salasreuniao.push_back(sr);
}




