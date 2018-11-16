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
	/**
	 * Funcionario reponsavel pelo espaço
	 */
	Funcionario *func;
public:
	void setFuncionario(Funcionario *func);
	Funcionario *getFuncionario() const;
};

//===================================================

class Quarto: public Espaco {
	/**
	 * Especifica o tipo de quarto
	 */
	string tipo;
	/**
	 * Especifica o local do quarto
	 */
	string local;
	/**
	 * Preco base de um quarto simples
	 */
	int simples_preco = 75;
	/**
	 * Preco base de um quarto duplo
	 */
	int duplo_preco = 100;
	/**
	 * Indica se quarto está reservado ou nao
	 */
	bool reservado;
public:
	Quarto() {};
	Quarto (string t, string l, bool res);
	string getTipo() const;
	string getLocal() const;
	int getPreco() const;
	string getRes() const;
	string getInformacao() const;
	void setRes();
	friend ostream &operator << (ostream &os, Quarto &q1);
};

//===================================================

class SalaReuniao: public Espaco {
	/**
	 * Preco da reserva da sala de reuniao
	 */
	int preco;
	/**
	 * Capacidade da sala de reuniao
	 */
	int capacidade;
	/**
	 * É verdade caso a sala tenha equipamento de video e falso no caso contrario
	 */
	bool video;
	/**
	 * É verdade caso a sala tenha equipamento de audio e falso no caso contrario
	 */
	bool audio;
	/**
	 * Acrescimo do preco das salas com equipamento de video
	 */
	int acres_video = 50;
	/**
	 * Acrescimo do preco das salas com equipamento de audio
	 */
	int acres_audio = 50;
	/**
	 * Indica se sala de reuniao está reservada ou nao
	 */
	bool reservado;
public:
	SalaReuniao();
	SalaReuniao(int Capacidade, bool video, bool audio, bool reservado);
	int getPreco() const;
	int getCapacidade() const;
	string getAudio() const;
	string getVideo() const;
	string getRes() const;
	void setRes();
	string getInformacao() const;
	friend ostream &operator << (ostream &os, SalaReuniao &q1);
};


#endif /* ESPACO_H_ */
