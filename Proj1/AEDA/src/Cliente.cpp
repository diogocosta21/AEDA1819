/*
 * Cliente.cpp
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#include "Cliente.h"
#include <iostream>

using namespace std;

/**
 * Constructor
 * @param n - Nome do cliente
 * @param NIF - NIF do cliente
 * @param nR - Numero de reservas feitas pelo cliente
 */
Cliente::Cliente(string n, unsigned int NIF, unsigned int nR): nome(n), numRes(nR)
{
	this->NIF = NIF;

}

/**
 * Destructor
 */
Cliente::~Cliente(){}

/**
 * @return nome
 */
string Cliente::getNome() const
{
	return nome;
}

/**
 * @return NIF
 */
unsigned int Cliente::getNIF() const
{
	return NIF;
}

/**
 * @return numero de reservas feitas pelo cliente
 */
int Cliente::getNR() const
{
	return numRes;
}

/**
 * Incrementa o numero de reservas feitas
 */
void Cliente::incNr()
{

	numRes++;
}

/**
 * @return string com nome e NIF do cliente
 */
string Cliente::getInformacao() const
{
	stringstream ss;

	ss << " " << getNome() << ", " << getNIF() << ", " << getNR();

	return ss.str();
}

/**
 * @return true se cliente for o mesmo e falso no caso contrario
 */
bool Cliente::operator == (const Cliente &Cl1) const
{
	if(this->NIF == Cl1.getNIF()) return true;
	return false;
}

/**
 * Escreve para ofstream a informacao do cliente no formato usado no ficheiro de texto
 * @param os - ostream onde é guardada informacao
 * @param c1 - Cliente cuja informacao é lida
 */
ostream &operator << (ostream &os, Cliente &c1)
{
	os << c1.getNome() << ", " << c1.getNIF() << ", " << c1.getNR();
	return os;
}


//============================================================================================================


