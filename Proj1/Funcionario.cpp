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
 * supervisor - verdade se for supervisor
 */
Funcionario::Funcionario(string nome, bool supervisor)
{
	this -> nome = nome;
	this -> supervisor = supervisor;
}

/**
 * Retorna nome do funcionario
 */
string Funcionario::getNome() const
{
	return nome;
}

/**
 * Retorna informacao sobre se o funcionario é supervisor ou nao
 */
string Funcionario::getSupervisor() const
{
	if(supervisor)
		return "Supervisor";
	else
		return "Nao Supervisor";
}

/**
 * Retorna string com nome e informacao se o funcionario é supervisor ou nao
 */
string Funcionario::getInformacao() const
{
	stringstream ss;
	ss << " " << getNome() << ", " << getSupervisor();
	return ss.str();
}
