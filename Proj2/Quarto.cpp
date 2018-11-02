/*
 * Quarto.cpp
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */


#include "Quarto.h"
#include <iostream>

using namespace std;

Quarto::Quarto(string t, string l)
{
	tipo = t;
	local = l;
}

string Quarto::getTipo() const
{
	return tipo;
}

string Quarto::getLocal() const
{
	return local;
}

int Quarto::getPreco() const
{
	if(getTipo() == "simples") {
		if(getLocal() == "frente")
			return simples_preco * 1.25;
		else if(getLocal() == "traseiras")
			return simples_preco;
		//else excecao
	}

	else if(getTipo() == "duplo") {
		if(getLocal() == "frente")
			return duplo_preco * 1.25;
		else if(getLocal() == "traseiras")
			return duplo_preco;
		//else excecao

		//else excecao
	}
}




