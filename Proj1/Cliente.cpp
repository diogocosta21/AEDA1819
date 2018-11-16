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
 * n - Nome do cliente
 * NIF - NIF do cliente
 * nR - Numero de reservas feitas pelo cliente
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
 * Retorna nome
 */
string Cliente::getNome() const
{
	return nome;
}

/**
 * Retorna NIF
 */
unsigned int Cliente::getNIF() const
{
	return NIF;
}

/**
 * Retorna numero de reservas feitas pelo cliente
 */
unsigned int Cliente::getNR() const
{
	return numRes;
}

/**
 * Retorna string com nome e NIF do cliente
 */
string Cliente::getInformacao() const
{
	stringstream ss;

	ss << " " << getNome() << ", " << getNIF() << ", " << getNR();

	return ss.str();
}

/**
 * Retorna true se cliente for o mesmo e falso no caso contrario
 */
bool Cliente::operator == (const Cliente &Cl1) const
{
	if(this->NIF == Cl1.getNIF()) return true;
	return false;
}

/**
 * Escreve para ofstream a informacao do cliente no formato usado no ficheiro de texto
 * os - ostream onde é guardada informacao
 * c1 - Cliente cuja informacao é lida
 */
ostream &operator << (ostream &os, Cliente &c1)
{
	os << c1.getNome() << ", " << c1.getNIF();
	return os;
}


//============================================================================================================


