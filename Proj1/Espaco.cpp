/*
 * Espaco.cpp
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */


#include "Espaco.h"
#include <iostream>

using namespace std;

void Espaco::setFuncionario(Funcionario *func)
{
	this -> func = func;
}

Funcionario *Espaco::getFuncionario() const
{
	return func;
}

//=============================================

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

//==========================================================================

SalaReuniao::SalaReuniao(int Capacidade) : capacidade (Capacidade) {
	if (capacidade <= 20)
		preco = 100;
	if (capacidade <= 50 && capacidade > 20)
		preco = 200;
};


int SalaReuniao::getPreco() const {

	int acrescimos = 0;
	if (video == true) {acrescimos += acres_video;}
	if (audio == true) {acrescimos += acres_audio;}
	if (capacidade <= 20)
		{
		int aux = preco + acrescimos;
		return aux;
		}
	else if (capacidade > 20 && capacidade <= 50) {
		int aux = preco + acrescimos;
		return aux;
	}
	else {return 0;}

	/* else if (capacidade > 50 ) {excecao demasiado}
	 * else excecao invalido
	 */
}



int SalaReuniao::getCapacidade() const {
	return capacidade;
}


