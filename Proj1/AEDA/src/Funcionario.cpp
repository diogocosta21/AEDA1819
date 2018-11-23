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
 * @param nome- nome do funcionario
 */
Funcionario::Funcionario(string nome)
{
	this->nome = nome;
}

/**
 * @return nome do funcionario
 */
string Funcionario::getNome() const
{
	return nome;
}

/**
 * @return string com nome e informacao se o funcionario é supervisor ou nao
 */
string Funcionario::getInformacao() const
{
	stringstream ss;
	ss << " " << getNome();
	return ss.str();
}

/**
 * Escreve para ofstream a informacao do funcionario no formato usado no ficheiro de texto
 * @param os - ostream onde é guardada informacao
 * @param f1 - Funcionario cuja informacao é lida
 */
ostream &operator << (ostream &os, Funcionario &f1)
{
	os << f1.getNome();
	return os;
}

/**
 * Constructor
 * @param nome - Nome do supervisor
 * @param numQuartos - Numero de quartos da responsabilidde do supervisor
 */
Supervisor::Supervisor(string nome, unsigned int numQuartos)
{
	this->nome = nome;
	this->numQuartos = numQuartos;
}

/**
 * @return numero de quartos da responsabildade do supervisor
 */
unsigned int Supervisor::getNumQuartos() const
{
	return numQuartos;
}

/**
 * Incrementa o numero de quartos do supervisor
 */
void Supervisor::incNr() {
 	numQuartos++;
}


/**
 * @return string com nome e numero de quartos da responsabilidade do supervisor
 */
string Supervisor::getInformacao() const
{
	stringstream ss;
	ss << " " << getNome() << ", " << getNumQuartos();
	return ss.str();
}

/**
 * Escreve para ofstream a informacao do supervisor no formato usado no ficheiro de texto
 * @param os - ostream onde é guardada informacao
 * @param f1 - Supervisor cuja informacao é lida
 */
ostream &operator << (ostream &os, Supervisor &s1)
{
	os << s1.getNome() << ", " << s1.getNumQuartos();
	return os;
}



