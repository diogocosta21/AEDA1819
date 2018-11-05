/*
 * Cliente.h
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "string"
#include "vector"

using namespace std;

class Cliente {
public:
	string nome;
	bool presente;
	int frequencia;
	bool operator == (const Cliente &Cl1) const;
	bool operator < (const Cliente &Cl1) const;
};


#endif /* CLIENTE_H_ */
