/*
 * Funcionario.cpp
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#include "Funcionario.h"
#include <iostream>

using namespace std;

/**
 * Constructor
 * nome- nome do funcionario
 */
Funcionario::Funcionario(string nome)
{
	this->nome = nome;
}

/**
 * Retorna nome do funcionario
 */
string Funcionario::getNome() const
{
	return nome;
}

/**
 * Retorna string com nome e informacao se o funcionario é supervisor ou nao
 */
string Funcionario::getInformacao() const
{
	stringstream ss;
	ss << " " << getNome();
	return ss.str();
}

/**
 * Constructor
 * nome - Nome do supervisor
 * numQuartos - Numero de quartos da responsabilidde do supervisor
 */
Supervisor::Supervisor(string nome, unsigned int numQuartos)
{
	this->nome = nome;
	this->numQuartos = numQuartos;
}

/**
 * Retorna numero de quartos da responsabildade do supervisor
 */
unsigned int Supervisor::getNumQuartos() const
{
	return numQuartos;
}

/**
 * Retorna string com nome e numero de quartos da responsabilidade do supervisor
 */
string Supervisor::getInformacao() const
{
	stringstream ss;
	ss << " " << getNome() << ", " << getNumQuartos();
	return ss.str();
}



