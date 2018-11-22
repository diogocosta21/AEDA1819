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
	 * @brief nome do funcionario
	 */
	string nome;
public:
	Funcionario(){};
	Funcionario(string nome);
	string getNome() const;
	string getInformacao() const;
	friend ostream &operator << (ostream &os, Funcionario &f1);
};

class Supervisor: public Funcionario {
	/**
	 * @breif numero de quartos da responsabilidade do supervisor
	 */
	unsigned int numQuartos;
public:
	Supervisor(string nome, unsigned int numQuartos);
	unsigned int getNumQuartos() const;
	string getInformacao() const;
	friend ostream &operator << (ostream &os, Supervisor &s1);
};


#endif /* FUNCIONARIO_H_ */
