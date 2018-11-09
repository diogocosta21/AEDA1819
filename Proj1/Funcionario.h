/*
 * Funcionario.h
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#ifndef FUNCIONARIO_H_
#define FUNCIONARIO_H_

#include <string>

using namespace std;

class Funcionario {
	string nome;
	int NIF;
	bool supervisor;
public:
	Funcionario(string nome, int NIF, bool supervisor);
	string getNome() const;
};


#endif /* FUNCIONARIO_H_ */
