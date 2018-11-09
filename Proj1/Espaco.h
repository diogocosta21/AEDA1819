/*
 * Espaco.h
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#ifndef ESPACO_H_
#define ESPACO_H_

#include "Funcionario.h"
#include <string>

using namespace std;

class Espaco {
protected:
	Funcionario *func;
public:
	void setFuncionario(Funcionario *func);
	Funcionario *getFuncionario() const;
};

//===================================================

class Quarto: public Espaco {
	string tipo;
	string local;
	int simples_preco = 75;
	int duplo_preco = 100;
	bool reservado = false;
public:
	Quarto();
	Quarto (string t, string l, bool reserv);
	string getTipo() const;
	string getLocal() const;int getPreco() const;
};

//===================================================

class SalaReuniao: public Espaco {
	int preco;
	int capacidade;
	bool video = false;
	bool audio = false;
	int acres_video = 50;
	int acres_audio = 50;
	bool reservado = false;
public:
	SalaReuniao();
	SalaReuniao(int Capacidade, bool reserv);
	int getPreco() const;
	int getCapacidade() const;
};


#endif /* ESPACO_H_ */
