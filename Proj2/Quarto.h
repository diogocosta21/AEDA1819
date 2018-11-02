/*
 * Quarto.h
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */


#ifndef QUARTO_H_
#define QUARTO_H_

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




#endif /* QUARTO_H_ */
