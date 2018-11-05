/*
 * Cliente.cpp
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#include "Cliente.h"
#include <iostream>

using namespace std;

bool Cliente::operator == (const Cliente &Cl1) const
{
	if(nome == Cl1.nome) return true;
	return false;
}

bool Cliente::operator < (const Cliente &Cl1) const
{
	if(frequencia < Cl1.frequencia)
		return true;
	else if(frequencia > Cl1.frequencia)
		return false;
	else
		return (nome < Cl1.nome);
}

