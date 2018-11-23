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
 * Chamada quando o utilizar insere op�ao invalida no menu
 */
class OpcaoInvalida
{
private:
	int opcao;
public:
	/**
	 * Construtor
	 * @param o - op�ao invalida inserida
	 */
	OpcaoInvalida(int o)
	{
		this->opcao = o;
	}
	/**
	 * @return op�ao
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
	 * Constructor
	 * @param o - op�ao invalida inserida
	 */
	OpcaoInvalidast(string o)
	{
		this->opcao = o;
	}
	/**
	 * @return op�ao
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
	 * @brief string invalida inserida
	 */
	string tipo;
public:
	/**
	 * Construtor
	 * @param tipo - tipo invalido inserido
	 */
	TipoInvalido(string tipo)
	{
		this->tipo = tipo;
		cout << "Tipo invalido" <<endl;
	}
};

/**
 * Chamada quando capacidade da sala inserida � invalida
 */
class CapacidadeInvalida{
	/**
	 * @brief int invalido inserido
	 */
	int capacidade;
public:
	/**
	 * Construtor
	 * @param capacidade invalida inserida
	 */
	CapacidadeInvalida(int capacidade) {
		this->capacidade = capacidade;
	}

	int getCapacidade() const
	{
		return capacidade;
	}
};



#endif /* AEDA_SRC_EXCECOES_H_ */
