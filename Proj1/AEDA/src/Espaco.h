/*
 * Espaco.h
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */

#ifndef ESPACO_H_
#define ESPACO_H_

#include "Funcionario.h"
#include "Data.h"
#include "Excecoes.h"
#include <string>
#include <vector>

using namespace std;

class Espaco {
protected:
	/**
	 * @brief supervisor reponsavel pelo espaço
	 */
	Supervisor *sup;
public:
	void setSupervisor(Supervisor *sup);
	Supervisor *getSupervisor() const;
};

//===================================================

class Quarto: public Espaco {
	/**
	 * @brief especifica o tipo de quarto
	 */
	string tipo;
	/**
	 * @brief especifica o local do quarto
	 */
	string local;
	/**
	 * @brief preco base de um quarto simples
	 */
	int simples_preco = 80;
	/**
	 * @brief preco base de um quarto duplo
	 */
	int duplo_preco = 100;
	/**
	 * @brief indica se quarto está reservado ou nao
	 */
	bool reservado;
	/**
	 * @brief nome do supervisor responsavel
	 */
	string nome;
public:
	//Quarto() {};
	Quarto (string t, string l, bool res, string nome);
	string getTipo() const;
	string getLocal() const;
	int getPrecoQuarto() const;
	int getPrecoMes(Data d) const;
	int getPrecoFinal(Data d1, Data d2) const;
	string getNome() const;
	string getRes() const;
	vector<Data> getReservas() const;
	string getInformacao() const;
	void setRes();
	friend ostream &operator << (ostream &os, Quarto &q1);
};

//===================================================

class SalaReuniao: public Espaco {
	/**
	 * @brief preco da reserva da sala de reuniao
	 */
	int preco;
	/**
	 * @brief capacidade da sala de reuniao
	 */
	int capacidade;
	/**
	 * @brief é verdade caso a sala tenha equipamento de video e falso no caso contrario
	 */
	bool video;
	/**
	 * @brief é verdade caso a sala tenha equipamento de audio e falso no caso contrario
	 */
	bool audio;
	/**
	 * @brief acrescimo do preco das salas com equipamento de video
	 */
	int acres_video = 50;
	/**
	 * @brief acrescimo do preco das salas com equipamento de audio
	 */
	int acres_audio = 50;
	/**
	 * @brief indica se sala de reuniao está reservada ou nao
	 */
	bool reservado;
	/**
	* @brief nome do supervisor responsavel
	*
	*/
	string nome;

public:
	SalaReuniao();
	SalaReuniao(int Capacidade, bool video, bool audio, bool reservado, string nome);
	int getPrecoSala() const;
	int getPrecoMes(Data d) const;
	int getCapacidade() const;
	string getAudio() const;
	string getVideo() const;
	string getRes() const;
	void setRes();
	string getNome() const;
	int getPrecoFinalSalas(Data d1, Data d2) const;
	string getInformacao() const;
	friend ostream &operator << (ostream &os, SalaReuniao &q1);
};


#endif /* ESPACO_H_ */
