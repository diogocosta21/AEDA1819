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
	/**
	 * Nome do funcionario
	 */
	string nome;
	/**
	 * Verdade se o funcionario for supervisor
	 */
	bool supervisor;
public:
	Funcionario(string nome, bool supervisor);
	string getNome() const;
	string getSupervisor() const;
	string getInformacao() const;
};


#endif /* FUNCIONARIO_H_ */
