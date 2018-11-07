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
	string nome;
	unsigned int NIF;
	unsigned int id;
	Data ultimaReserva;
public:
	Cliente(){};
	Cliente(string n, unsigned int NIF, Data uR);
	virtual ~Cliente();
	string getNome() const;
	unsigned int getNIF() const;
	void setId() const;
	unsigned int getId() const;
	Data getUltimaReserva() const;
	void setUltimaReserva(const Data &d);
	virtual string getInformacao() const;
	bool operator == (const Cliente &Cl1) const;
	friend ostream &operator << (ostream &os, Cliente &c1);
};



#endif /* CLIENTE_H_ */
