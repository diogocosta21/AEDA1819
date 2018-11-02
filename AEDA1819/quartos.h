/*
 * quartos.h
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#ifndef QUARTOS_H_
#define QUARTOS_H_

#include "string"

using namespace std;

class Quarto {
	string tipo;
	string local;
	int simples_preco = 75;
	int duplo_preco = 100;
public:
	Quarto() {};
	Quarto (string t, string l);
	string getTipo() const;
	string getLocal() const;
	int getPreco() const;

};




#endif /* QUARTOS_H_ */
