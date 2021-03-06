/*
 * Hotel.cpp
 *
 *  Created on: 07/11/2018
 *      Author: joao_
 */


#include "Hotel.h"

/**
 * Constructor
 * @param clientes - Clientes do hotel
 * @param funcionarios - Funcionarios do hotel
 * @param quartos - Quartos do hotel
 * @param salasreuniao - Salas de reuniao do hotel
 */
Hotel::Hotel(vector<Cliente *> clientes, vector<Funcionario *> funcionarios, vector<Quarto *> quartos, vector<SalaReuniao *> salasreuniao, vector<Supervisor *> supervisores)
{
	this->clientes=clientes;
	this->funcionarios=funcionarios;
	this->quartos=quartos;
	this->salasreuniao=salasreuniao;
	this->supervisores=supervisores;
	data = Data("16-11-2018");
}

/**
 * Destructor
 */
Hotel::~Hotel(){}


/**
 * Exporta clientes para ficheiro de texto
 * @param file - ficheiro que guarda informacao dos clientes
 */
void Hotel::exportClientes(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < clientes.size(); i++)
	{
		os << *clientes[i] << ";" << endl;
	}

	os.close();
}


/**
 * Exporta funcionarios para ficheiro de texto
 * @param file - ficheiro que guarda informacao dos funcionarios
 */
void Hotel::exportFuncionarios(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < funcionarios.size(); i++)
	{
		os << *funcionarios[i] << ";" << endl;
	}

	os.close();
}

/**
 * Exporta supervisores para ficheiro de texto
 * @param file - ficheiro que guarda informacao dos funcionarios
 */
void Hotel::exportSupervisores(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < supervisores.size(); i++)
	{
		os << *supervisores[i] << ";" << endl;
	}

	os.close();
}

/**
 * Exporta quartos para ficheiro de texto
 * @param file - ficheiro que guarda informacao dos quartos
 */
void Hotel::exportQuartos(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < quartos.size(); i++)
	{
		os << *quartos[i] << ";" << endl;
	}

	os.close();
}

/**
 * Exporta salas de reuniao para ficheiro de texto
 * @param file - ficheiro que guarda informacao das salas de reuniao
 */
void Hotel::exportSalasReuniao(string file)
{
	ofstream os;
	os.open(file.c_str());

	for(unsigned int i = 0; i < salasreuniao.size(); i++)
	{
		os << *salasreuniao[i] << ";" << endl;
	}

	os.close();
}

/**
 * Exporta os restaurantes para ficheiro de texto
 * @param file - ficheiro que guarda informa�ao dos restaurantes
 */
void Hotel::exportRestaurantes(string file)
{
	ofstream os;
	os.open(file.c_str());

	BSTItrIn <Restaurante> it (restaurantes);
	vector <Restaurante> v;

	while (!it.isAtEnd())
	{
		v.push_back(it.retrieve());
		it.advance();
	}


	for(unsigned int i = 0; i < v.size(); i++)
	{
		os << v[i] << endl;
	}

	os.close();
}

/**
 * Adiciona cliente ao vetor de clientes
 * @param nome - Nome do cliente
 * @param NIF - NIF do cliente
 */
void Hotel::addCliente(string nome, int NIF, unsigned int numRes)
{
	Cliente * cl = new Cliente(nome, NIF, numRes);
	clientes.push_back(cl);
}

/**
 * Adiciona funcionario ao vetor de funcionarios
 * @param nome - Nome do funcionario
 */
void Hotel::addFuncionario(string nome)
{
	Funcionario * func = new Funcionario(nome);
	funcionarios.push_back(func);
}

/**
 * Adiciona supervisor ao vetor de supervisores
 * @param nome - Nome do supervisor
 */
void Hotel::addSupervisor(string nome, int numQuartos)
{
	Supervisor * sup = new Supervisor(nome, numQuartos);
	supervisores.push_back(sup);
}

/**
 * Adiciona quarto ao vetor dos quartos
 * @param tipo - tipo do quarto
 * @param lugar - local do quarto
 */
void Hotel::addQuarto(string tipo, string lugar, bool res, string nome)
{
	Quarto * quarto = new Quarto(tipo, lugar, res, nome);
	quartos.push_back(quarto);
}

/**
 * Adiciona sala de reuniao ao vetor das salas de reuniao
 * @param capacidade - capacidade da sala de reuniao
 * @param video - verdade se sala de reuniao tiver equipamento de video
 * @param audio - verdade se sala de reuniao tiver equipamento de audio
 */
void Hotel::addSalaReuniao(int capacidade, bool video, bool audio, bool res, string nome)
{
	SalaReuniao * sr = new SalaReuniao(capacidade, video, audio, res, nome);
	salasreuniao.push_back(sr);
}

/**
 * Adiciona restaurante a arvore binaria de pesquisa dos restaurantes
 * @param nome - nome do restaurante
 * @param tipo - tipo de cozinha do restaurante
 * @param dist - distancia do restaurante ao hotel
 */
void Hotel::addRestaurante(string nome, string tipo, int dist)
{
	Restaurante r = new Restaurante(nome, tipo, dist);
	restaurantes.insert(r);
}

/**
 * Remove cliente do vector de clientes presentes no hotel
 * @param nome - Nome do cliente
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
 * @return vector dos clientes
 */
vector<Cliente *> Hotel::getClientes() const
{
	return clientes;
}

/**
 * @return vector dos funcionarios
 */
vector<Funcionario *> Hotel::getFuncionarios() const
{
	return funcionarios;
}

/**
 * @return vector dos supervisores
 */
vector<Supervisor *> Hotel::getSupervisores() const
{
	return supervisores;
}

/**
 * @return vector dos quartos
 */
vector<Quarto *> Hotel::getQuartos() const
{
	return quartos;
}

/**
 * @return vector das salas de reuniao
 */
vector<SalaReuniao *> Hotel::getSalasReuniao() const
{
	return salasreuniao;
}

Supervisor* Hotel::getSupComMenosEspacos() const
{
	Supervisor *s = supervisores[0];
 	for(unsigned int i = 0; i < supervisores.size(); i++)
	{
		if(supervisores[i]->getNumQuartos() < s->getNumQuartos())
			s = supervisores[i];
	}
 	return s;
}


/**
 * @return data
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
 * Imprime informacao dos supervisores
 */
void Hotel::printSupervisores() const
{
	for(unsigned int i = 0; i < supervisores.size(); i++)
	{
		cout << supervisores[i]->getInformacao() << endl;
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
			for(j = i; j >= m && q->getPrecoQuarto() > v[j-m]->getPrecoQuarto(); j -= m)
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
 * Imprime os quartos nao reservados
 */
 void Hotel::printQuartosNaoReservados() const
{
	vector<Quarto *> v;
	unsigned int k = 1;
	for (unsigned int i = 0; i < quartos.size() ; i++)
	{
		if (quartos[i]->getRes() == "Nao reservado")
			v.push_back(quartos[i]);
	}
 	for(unsigned int i = 0; i < v.size(); i++)
	{
		cout << k << " - ";
		cout << v[i]->getInformacao() << endl;
		k++;
	}
}
 /**
 * Imprime os quartos nao reservados por preco
 */
 void Hotel::printQuartosNaoReservadosPorPreco() const {
 	vector<Quarto *> v = quartos;
	unsigned int j;
	unsigned int k = 1;
 	for(unsigned int m = v.size()/2; m > 0; m /= 2)
	{
		for(unsigned int i = m; i < v.size(); i++)
		{
			Quarto* q = v[i];
			for(j = i; j >= m && q->getPrecoQuarto() > v[j-m]->getPrecoQuarto(); j -= m)				{
					v[j] = v[j-m];
			}
			v[j] = q;
		}
	}
 	vector <Quarto *> aux;
 	for (unsigned int i = 0; i < v.size() ; i++)
	{
		if (v[i]->getRes() == "Nao reservado")
				aux.push_back(v[i]);
	}
 	for(unsigned int i = 0; i < aux.size(); i++)
	{
		cout << k << " - ";
		cout << aux[i]->getInformacao() << endl;
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
			for(j = i; j >= m && sr->getPrecoSala() > v[j-m]->getPrecoSala(); j -= m)
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

/**
 * Imprime salas de reuniao nao reservadas
 */
void Hotel::printSalasReuniaoNaoReservadas() const
{
	vector<SalaReuniao *> v;
	unsigned int k = 1;
	for (unsigned int i = 0; i < salasreuniao.size() ; i++)
	{
		if (salasreuniao[i]->getRes() == "Nao reservada")
			v.push_back(salasreuniao[i]);
	}
 	for(unsigned int i = 0; i < v.size(); i++)
	{
		cout << k << " - ";
		cout << v[i]->getInformacao() << endl;
		k++;
	}
}

/**
 * Imprime salas de reuniao nao reservadas ordenadas pelo pre�o
 */
void Hotel::printSalasReuniaoNaoReservadasPorPreco() const {
 	vector<SalaReuniao *> v = salasreuniao;
	unsigned int j;
	unsigned int k = 1;
 	for(unsigned int m = v.size()/2; m > 0; m /= 2)
	{
		for(unsigned int i = m; i < v.size(); i++)
		{
			SalaReuniao* q = v[i];
			for(j = i; j >= m && q->getPrecoSala() > v[j-m]->getPrecoSala(); j -= m)
			{
					v[j] = v[j-m];
			}
			v[j] = q;
		}
	}
 	vector <SalaReuniao *> aux;
 	for (unsigned int i = 0; i < v.size() ; i++)
	{
		if (v[i]->getRes() == "Nao reservada")
				aux.push_back(v[i]);
	}
 	for(unsigned int i = 0; i < aux.size(); i++)
	{
		cout << k << " - ";
		cout << aux[i]->getInformacao() << endl;
		k++;
	}
}







