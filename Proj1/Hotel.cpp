/*
 * Hotel.cpp
 *
 *  Created on: 07/11/2018
 *      Author: joao_
 */


#include "Hotel.h"

/**
 * Constructor
 * clientes - Clientes do hotel
 * funcionarios - Funcionarios do hotel
 * quartos - Quartos do hotel
 * salasreuniao - Salas de reuniao do hotel
 */
Hotel::Hotel(vector<Cliente *> clientes, vector<Funcionario *> funcionarios, vector<Quarto *> quartos, vector<SalaReuniao *> salasreuniao)
{
	this->clientes=clientes;
	this->funcionarios=funcionarios;
	this->quartos=quartos;
	this->salasreuniao=salasreuniao;
	data = Data("16-11-2018");
}

/**
 * Destructor
 */
Hotel::~Hotel(){}


/**
 * Exporta clientes para ficheiro de texto
 * file - ficheiro que guarda informacao dos clientes
 */
void Hotel::exportClientes(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < clientes.size(); i++)
	{
		os << *clientes[i] << endl;
	}

	os.close();
}


/**
 * Exporta funcionarios para ficheiro de texto
 * file - ficheiro que guarda informacao dos funcionarios
 */
void Hotel::exportFuncionarios(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < funcionarios.size(); i++)
	{
		os << funcionarios[i] << endl;
	}

	os.close();
}

/**
 * Exporta quartos para ficheiro de texto
 * file - ficheiro que guarda informacao dos quartos
 */
void Hotel::exportQuartos(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < quartos.size(); i++)
	{
		os << quartos[i] << endl;
	}

	os.close();
}

/**
 * Exporta salas de reuniao para ficheiro de texto
 * file - ficheiro que guarda informacao das salas de reuniao
 */
void Hotel::exportSalasReuniao(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < salasreuniao.size(); i++)
	{
		os << salasreuniao[i] << endl;
	}

	os.close();
}

/**
 * Adiciona cliente ao vetor de clientes
 * nome - Nome do cliente
 * NIF - NIF do cliente
 */
void Hotel::addCliente(string nome, int NIF, unsigned int numRes)
{
	Cliente * cl = new Cliente(nome, NIF, numRes);
	clientes.push_back(cl);
}

/**
 * Adiciona funcionario ao vetor de funcionarios
 * nome - Nome do funcionario
 * supervisor - Verdade se o funcionario for supervisor
 */
void Hotel::addFuncionario(string nome, bool supervisor)
{
	Funcionario * func = new Funcionario(nome, supervisor);
	funcionarios.push_back(func);
}

/**
 * Adiciona quarto ao vetor dos quartos
 * tipo - tipo do quarto
 * lugar - local do quarto
 */
void Hotel::addQuarto(string tipo, string lugar, bool res)
{
	Quarto * quarto = new Quarto(tipo, lugar, res);
	quartos.push_back(quarto);
}

/**
 * Adiciona sala de reuniao ao vetor das salas de reuniao
 * capacidade - capacidade da sala de reuniao
 * video - verdade se sala de reuniao tiver equipamento de video
 * audio - verdade se sala de reuniao tiver equipamento de audio
 */
void Hotel::addSalaReuniao(int capacidade, bool video, bool audio, bool res)
{
	SalaReuniao * sr = new SalaReuniao(capacidade, video, audio, res);
	salasreuniao.push_back(sr);
}

/**
 * Remove cliente do vector de clientes presentes no hotel
 * nome - Nome do cliente
 */
void Hotel::removeCliente(string nome)
{
	for(unsigned int i = 0; i < clientes.size(); i++)
	{
		if(clientes[i]->getNome() == nome)
		{
			clientes.erase(clientes.begin()+i);
		}
	}
}

/**
 * Retorna vector dos clientes
 */
vector<Cliente *> Hotel::getClientes() const
{
	return clientes;
}

/**
 * Retorna vector dos funcionarios
 */
vector<Funcionario *> Hotel::getFuncionarios() const
{
	return funcionarios;
}

/**
 * Retorna vector dos quartos
 */
vector<Quarto *> Hotel::getQuartos() const
{
	return quartos;
}

/**
 * Retorna vector das salas de reuniao
 */
vector<SalaReuniao *> Hotel::getSalasReuniao() const
{
	return salasreuniao;
}

/**
 * Retorna data
 */
Data Hotel::getData() const
{
	return data;
}

/**
 * Imprime informacao dos clientes
 */
void Hotel::printClientes() const
{
	for(unsigned int i = 0; i < clientes.size(); i++)
	{
		cout << clientes[i]->getInformacao() << endl;
	}
}

/**
 * Imprime informacao dos clientes ordendados pelo NIF
 */
void Hotel::printClientesByNIF() const
{
	vector<Cliente *> v = clientes;
	unsigned int j;

	for(unsigned int m = v.size()/2; m > 0; m /= 2)
	{
		for(unsigned int i = m; i < v.size(); i++)
		{
			Cliente* c = v[i];
			for(j = i; j >= m && c->getNIF() > v[j-m]->getNIF(); j -= m)
			{
				v[j] = v[j-m];
			}
			v[j] = c;
		}
	}

	for(unsigned int i = 0; i < v.size(); i++)
		cout << v[i]->getInformacao() << endl;
}

/**
 * Imprime informacao dos funcionarios
 */
void Hotel::printFuncionarios() const
{
	for(unsigned int i = 0; i < funcionarios.size(); i++)
	{
		cout << funcionarios[i]->getInformacao() << endl;
	}
}

/**
 * Imprime informacao dos quartos
 */
void Hotel::printQuartos() const
{
	unsigned int j = 1;
	for(unsigned int i = 0; i < quartos.size(); i++)
	{
		cout << j << " - ";
		cout << quartos[i]->getInformacao() << endl;
		j++;
	}
}

/**
 * Imprime informacao dos quartos ordenados pelo preco
 */
void Hotel::printQuartosPorPreco() const
{
	vector<Quarto *> v = quartos;
	unsigned int j;
	unsigned int k = 1;

	for(unsigned int m = v.size()/2; m > 0; m /= 2)
	{
		for(unsigned int i = m; i < v.size(); i++)
		{
			Quarto* q = v[i];
			for(j = i; j >= m && q->getPreco() > v[j-m]->getPreco(); j -= m)
			{
				v[j] = v[j-m];
			}
			v[j] = q;
		}
	}

	for(unsigned int i = 0; i < v.size(); i++)
	{
		cout << k << " - ";
		cout << v[i]->getInformacao() << endl;
		k++;
	}
}

/**
 * Imprime informacao das salas de reuniao
 */
void Hotel::printSalasReuniao() const
{
	unsigned int j = 1;
	for(unsigned int i = 0; i < salasreuniao.size(); i++)
	{
		cout << j << " - ";
		cout << salasreuniao[i]->getInformacao() << endl;
		j++;
	}
}

/**
 * Imprime informacao das salas de reuniao ordenadas pelo preco
 */
void Hotel::printSalasReuniaoPorPreco() const
{
	vector<SalaReuniao *> v = salasreuniao;
	unsigned int j;
	unsigned int k = 1;

	for(unsigned int m = v.size()/2; m > 0; m /= 2)
	{
		for(unsigned int i = m; i < v.size(); i++)
		{
			SalaReuniao* sr = v[i];
			for(j = i; j >= m && sr->getPreco() > v[j-m]->getPreco(); j -= m)
			{
				v[j] = v[j-m];
			}
			v[j] = sr;
		}
	}

	for(unsigned int i = 0; i < v.size(); i++)
	{
		cout << k << " - ";
		cout << v[i]->getInformacao() << endl;
		k++;
	}
}










