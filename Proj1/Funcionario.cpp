/*
 * Funcionario.cpp
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#include "Funcionario.h"
#include <iostream>

using namespace std;

Funcionario::Funcionario(string nome, int NIF, bool supervisor)
{
	this -> nome = nome;
	this -> NIF = NIF;
	this -> supervisor = supervisor;
}

string Funcionario::getNome() const
{
	return nome;
}

