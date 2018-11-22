/*
 * Excecoes.h
 *
 *  Created on: 20/11/2018
 *      Author: up201505198
 */

#ifndef AEDA_SRC_EXCECOES_H_
#define AEDA_SRC_EXCECOES_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * Called when the user inserts an invalid option in a menu.
 */
class OpcaoInvalida
{
private:
	int opcao;
public:
	/**
	 * The constructor
	 * @param o invalid option inserted.
	 */
	OpcaoInvalida(int o)
	{
		this->opcao = o;
	}
	/**
	 * @return option.
	 */
	int getOpcao() const
	{
		return opcao;
	}
};

class OpcaoInvalidast
{
private:
	string opcao;
public:
	/**
	 * The constructor
	 * @param o invalid option inserted.
	 */
	OpcaoInvalidast(string o)
	{
		this->opcao = o;
	}
	/**
	 * @return option.
	 */
	string getOpcao() const
	{
		return opcao;
	}
};

/**
 * Chamada quando tipo de quarto � invalido
 */
class TipoInvalido {
	/**
	 * @param string invalida inserida
	 */
	string tipo;
public:
	TipoInvalido(string tipo)
	{
		this->tipo = tipo;
	}
};

class CapacidadeInvalida{
	int capacidade;
public:
	CapacidadeInvalida(int capacidade) {
		this->capacidade = capacidade;
		if(capacidade > 50)
		{
			cout << "Capacidade tem de ser menor que 50" << endl;
		}
		else
			cout << "Capacidade invalida" << endl;
	}
};



#endif /* AEDA_SRC_EXCECOES_H_ */
