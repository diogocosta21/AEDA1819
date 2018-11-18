/*
 * Funcionario.h
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <string>
#include <sstream>

using namespace std;

class Funcionario {
protected:
	/**
	 * Nome do funcionario
	 */
	string nome;
public:
	Funcionario(){};
	Funcionario(string nome);
	string getNome() const;
	string getInformacao() const;
};

class Supervisor: public Funcionario {
	/**
	 * Numero de quartos da responsabilidade do supervisor
	 */
	unsigned int numQuartos;
public:
	Supervisor(string nome, unsigned int numQuartos);
	unsigned int getNumQuartos() const;
	string getInformacao() const;
};


#endif /* FUNCIONARIO_H_ */
