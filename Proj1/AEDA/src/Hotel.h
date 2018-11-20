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

using namespace std;

#include "Cliente.h"
#include "Espaco.h"
#include "Funcionario.h"
#include "Excecoes.h"

class Hotel {
private:
	/**
	 * Vector com clientes no hotel
	 */
	vector<Cliente *> clientes;
	/**
	 * Vector com funcionarios do hotel
	 */
	vector<Funcionario *> funcionarios;
	/**
	 * Vector com quartos do hotel
	 */
	vector<Quarto *> quartos;
	/**
	 * Vector com salas de reuniao do hotel
	 */
	vector<SalaReuniao *> salasreuniao;
	/**
	 * Data atual
	 */
	Data data;
public:
	Hotel(vector<Cliente *> clientes, vector<Funcionario *> funcionarios, vector<Quarto *> quartos, vector<SalaReuniao *> salasreuniao);
	virtual ~Hotel();
	void exportClientes(string file);
	void exportFuncionarios(string file);
	void exportQuartos(string file);
	void exportSalasReuniao(string file);
	void addCliente(string nome, int NIF, unsigned int numRes);
	void addFuncionario(string nome, bool supervisor);
	void addQuarto(string tipo, string lugar, bool res);
	void addSalaReuniao(int capacidade, bool video, bool audio, bool res);
	void removeCliente(string nome);
	vector<Cliente *> getClientes() const;
	vector<Funcionario *> getFuncionarios() const;
	vector<Quarto *> getQuartos() const;
	vector<SalaReuniao *> getSalasReuniao() const;
	Data getData() const;
	void printClientes() const;
	void printClientesByNIF() const;
	void printFuncionarios() const;
	void printQuartos() const;
	void printQuartosPorPreco() const;
	void printSalasReuniao() const;
	void printSalasReuniaoPorPreco() const;
};



#endif /* HOTEL_H_ */
