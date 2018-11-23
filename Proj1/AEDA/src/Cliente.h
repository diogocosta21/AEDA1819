/*
 * Cliente.h
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <string>
#include <sstream>
#include "Data.h"

using namespace std;

class Cliente {
private:
	/**
	 * @brief Nome do cliente
	 */
	string nome;
	/**
	 * @brief NIF do cliente
	 */
	unsigned int NIF;
	/**
	 * @brief Numero de reservas feitas pelo cliente
	 */
	unsigned int numRes;
public:
	//Cliente(){};
	Cliente(string n, unsigned int NIF, unsigned int nR);
	virtual ~Cliente();
	string getNome() const;
	unsigned int getNIF() const;
	unsigned int getNR() const;
	void incNR() ;
	string getInformacao() const;
	bool operator == (const Cliente &Cl1) const;
	friend ostream &operator << (ostream &os, Cliente &c1);
};



#endif /* CLIENTE_H_ */
