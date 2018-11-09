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

class Hotel {
private:
	vector<Cliente *> clientes;
	vector<Funcionario *> funcionarios;
	vector<Quarto *> quartos;
	vector<SalaReuniao *> salasreuniao;
	Data data;
public:
	Hotel(vector<Cliente *> clientes, vector<Funcionario *> funcionarios, vector<Quarto *> quartos, vector<SalaReuniao *> salasreuniao);
	virtual ~Hotel();
	void exportClientes(string file);
	void exportFuncionarios(string file);
	void exportQuartos(string file);
	void exportSalasReuniao(string file);
	void addCliente(string nome, int NIF);
	void addFuncionario(string nome, int NIF, bool supervisor);
	void addQuarto(string tipo, string lugar);
	void addSalaReuniao(int capacidade);
	vector<Cliente *> getClientes() const;
	vector<Funcionario *> getFuncionarios() const;
	vector<Quarto *> getQuartos() const;
	vector<SalaReuniao *> getSalasReuniao() const;
	Data getData() const;
	void printClientesByName() const;
	void printClientesByID() const;
	void printFuncionarios() const;
	void printFuncionariosByName() const;
	void printQuartos() const;
	void printSalasReuniao() const;
};



#endif /* HOTEL_H_ */
