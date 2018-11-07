/*
 * Cliente.cpp
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#include "Cliente.h"
#include <iostream>

using namespace std;

static unsigned int ID = 1;


Cliente::Cliente(string n, unsigned int NIF, Data uR): nome(n)
{
	this->NIF = NIF;
	this->ultimaReserva = uR;
	id = ID;
	ID++;
}


Cliente::~Cliente(){}


string Cliente::getNome() const
{
	return nome;
}


unsigned int Cliente::getNIF() const
{
	return NIF;
}


unsigned int Cliente::getId() const
{
	return id;
}


Data Cliente::getUltimaReserva() const
{
	return ultimaReserva;
}

void Cliente::setUltimaReserva(const Data &d)
{
	this->ultimaReserva = d;
}


string Cliente::getInformacao() const
{
	stringstream ss;

	ss << " " << getNome() << ", " << getNIF();

	return ss.str();
}


bool Cliente::operator == (const Cliente &Cl1) const
{
	if(this->nome == Cl1.getNome()) return true;
	return false;
}


ostream &operator << (ostream &os, Cliente &c1)
{
	os << c1.getId() << ", " << c1.getNome() << ", " << c1.getNIF() << ", "
			<< c1.getUltimaReserva().getDia() << "/" << c1.getUltimaReserva().getMes() << "/" << c1.getUltimaReserva().getAno();
	return os;
}


//============================================================================================================


