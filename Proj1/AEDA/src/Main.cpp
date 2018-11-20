/*
 * Main.cpp
 *
 *  Created on: 09/11/2018
 *      Author: up201505198
 */



#include <iostream>
#include <vector>

#include "Hotel.h"
#include "Menu.h"
#include "FileReader.h"

using namespace std;

#define ClientesFile "clientes.txt"
#define QuartosFile "quartos.txt"
#define SalasReuniaoFile "salasReuniao.txt"
#define FuncionariosFile "funcionarios.txt"

int main()
{
	vector <Cliente *> clientes = FileReader::readClientes(ClientesFile);
	vector <Quarto *> quartos = FileReader::readQuartos(QuartosFile);
	vector <SalaReuniao *> salasreuniao = FileReader::readSalasReuniao(SalasReuniaoFile);
	vector <Funcionario *> funcionarios = FileReader::readFuncionarios(FuncionariosFile);


	Hotel h(clientes, funcionarios, quartos, salasreuniao);

	HotelMenu (&h);

	h.exportClientes (ClientesFile);
	h.exportQuartos (QuartosFile);
	h.exportSalasReuniao (SalasReuniaoFile);
	h.exportFuncionarios (FuncionariosFile);

	return 0;
}
