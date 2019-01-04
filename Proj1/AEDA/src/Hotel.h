/*
 * Hotel.h
 *
 *  Created on: 07/11/2018
 *      Author: joao_
 */

#ifndef HOTEL_H_
#define HOTEL_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>

using namespace std;

#include "BST.h"
#include "Cliente.h"
#include "Espaco.h"
#include "Funcionario.h"
#include "Excecoes.h"


struct AntigosClientes
{
	int operator() (const Cliente* c1) const
	{
		string s1 = c1->getNome();

		int v = 0;
		for ( unsigned int i=0; i< s1.size(); i++ )
		 v = 37*v + s1[i];
		return v;

	}

	bool operator() (const Cliente *c1, const Cliente *c2) const
	{
		return c1 == c2;
	}
};


typedef unordered_set<Cliente*, AntigosClientes, AntigosClientes> tabHAntigos;


class Hotel {
private:
	/**
	 * @brief vector com clientes no hotel
	 */
	vector<Cliente *> clientes;
	/**
	 * @brief vector com funcionarios do hotel
	 */
	vector<Funcionario *> funcionarios;
	/**
	 * @brief vector com supervisores do hotel
	 */
	vector<Supervisor *> supervisores;
	/**
	 * @brief vector com quartos do hotel
	 */
	vector<Quarto *> quartos;
	/**
	 * @brief vector com salas de reuniao do hotel
	 */
	vector<SalaReuniao *> salasreuniao;
	/**
	 * @brief data atual
	 */
	Data data;
	/**
	 * @brief arvore binaria com restaurantes das redondezas
	 */
	BST <Restanturante> restaurantes;
public:
	Hotel(vector<Cliente *> clientes, vector<Funcionario *> funcionarios, vector<Quarto *> quartos, vector<SalaReuniao *> salasreuniao, vector<Supervisor *> supervisores);
	virtual ~Hotel();
	void exportClientes(string file);
	void exportFuncionarios(string file);
	void exportSupervisores(string file);
	void exportQuartos(string file);
	void exportSalasReuniao(string file);
	void addCliente(string nome, int NIF, unsigned int numRes);
	void addFuncionario(string nome);
	void addSupervisor(string nome, int numQuartos);
	void addQuarto(string tipo, string lugar, bool res, string nome);
	void addSalaReuniao(int capacidade, bool video, bool audio, bool res, string nome);
	void removeCliente(string nome);
	void setFuncionario(Funcionario func);
	vector<Cliente *> getClientes() const;
	vector<Funcionario *> getFuncionarios() const;
	vector<Supervisor *> getSupervisores() const;
	vector<Quarto *> getQuartos() const;
	vector<SalaReuniao *> getSalasReuniao() const;
	Supervisor* getSupComMenosEspacos() const;
	Data getData() const;
	void printClientes() const;
	void printClientesByNIF() const;
	void printFuncionarios() const;
	void printSupervisores() const;
	void printQuartos() const;
	void printQuartosPorPreco() const;
	void printQuartosNaoReservados() const;
	void printQuartosNaoReservadosPorPreco() const;
	void printSalasReuniao() const;
	void printSalasReuniaoPorPreco() const;
	void printSalasReuniaoNaoReservadas() const;
	void printSalasReuniaoNaoReservadasPorPreco() const;
};



#endif /* HOTEL_H_ */
