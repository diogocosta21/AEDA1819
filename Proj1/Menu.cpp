#include <iostream>
#include <limits>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>

#include "Menu.h"

using namespace std;



bool HotelMenu(Hotel *h)
{
	unsigned int optionCM = 0;
	bool flag = false;
	string d;

	cout << "Data de hoje(dd-mm-aaaa): ";
	cin >> d;

	d1 = Data(d);

	while (!flag)
	{

		cout << "***********************" << endl;
		cout << "|      Bem-vindo      |" << endl;
		cout << "***********************" << endl << endl;


		cout << "1 Fazer uma Reserva"    << endl;
		cout << "2 Criar um espaco"      << endl;
		cout << "3 Ver Ficheiros" 	     << endl;
		cout << "4 Sair"                 << endl;
		cout << "Inserir opcao que pretende: ";

		cin >> optionCM;
		cin.clear();
		cout << endl;

		switch (optionCM)
		{
			case 1:
			{
				FazerReserva (h);
				break;
			}

			case 2:
			{
				unsigned int optionCM2 = 0;
				bool flag2 = false;
				while (!flag2)
				{
					cout << "***********************" << endl;
					cout << "|   Criar um espaço   |" << endl;
					cout << "***********************" << endl << endl;

					cout << "1 Criar um quarto" << endl;
					cout << "2 Criar uma sala de reuniao" << endl;
					cout << "3 Voltar" << endl;
					cout << "Inserir a opcao desejada: ";

					cin >> optionCM2;
					cin.clear();
					cin.ignore(10000,'\n');

					switch (optionCM2)
					{
						case 1:
						{
							string tipo;
							string local;
							bool res = false;

							cout << "Tipo de quarto(simples ou duplo): ";
							cin >> tipo;

							cout << "Local do quarto(frente ou traseiras): ";
							cin >> local;

							h->addQuarto(tipo, local, res);

							break;
						}

						case 2:
						{
							int capacidade;
							string vid, aud;
							bool video;
							bool audio;
							bool res = false;

							cout << "Capacidade da sala: ";
							cin >> capacidade;

							cout << "Equipamento de video('sim' ou 'nao'): ";
							cin >> vid;

							if(vid == "sim")
								video = true;
							else if(vid == "nao")
								video = false;

							cout << "Equipamento de audio('sim' ou 'nao'): ";
							cin >> aud;

							if(aud == "sim")
								audio = true;
							else if(aud == "nao")
								audio = false;

							h->addSalaReuniao(capacidade, video, audio, res);

							break;
						}

						case 3:
						{
							flag2 = true;
							break;
						}
					}
				}
			}
		}
	}
}

bool FazerReserva (Hotel *h)
{
	bool existe = false;
	string nome;
	unsigned int NIF;
	unsigned int numRes;
	string numDias;
	string espaco;
	int preco;

	cout << "Nome? " << endl;
	cin >> nome;
	cout << "NIF? " << endl;
	cin >> NIF;

	for(unsigned int i = 0; i < h->getClientes().size(); i++)
	{
		if(h->getClientes()[i]->getNome() == nome)
		{
			numRes++;
			existe = true;
		}
	}
	if(!existe)
	{
		unsigned int numRes = 1;
		h->addCliente(nome, NIF, numRes);
	}

	cout << "Tipo de reserva que pretende efetuar(quarto ou sala de reuniao): ";
	cin >> espaco;

	if(espaco == "quarto")
	{
		cout << "Numero de dias que pretende estar hospedado: " << endl;
		cin >> numDias;
		cout << endl;

		cout << "Quartos do hotel: " << endl << endl;
		h->printQuartosPorPreco();
		cout << endl << "Numero do quarto que pretende reservar: ";
		unsigned int i;
		cin >> i;

		while(h->getQuartos()[i-1]->getRes() == "Reservado")
		{
			cout << "O quarto escolhido encontra-se reservado. Por favor escolher outro: ";
			cin >> i;
		}

		cout << "Preco a pagar: ";

		preco = h->getQuartos()[i-1]->getPreco();
		if((d1.getMes() >= 6 && d1.getMes() <= 8) || d1.getMes() == 12)
			preco = preco * 1.50;
		preco = preco * numDias;

		cout << preco;

		h->getQuartos()[i-1]->setRes();

		cout << "Reserva finalizada";

		return true;
	}

	if(espaco == "sala de reuniao")
		{
			cout << "Salas de reuniao: " << endl << endl;
			h->printSalasReuniaoPorPreco();
			cout << endl << "Numero da sala de reuniao que pretende reservar: ";
			unsigned int i;
			cin >> i;

			while(h->getSalasReuniao()[i-1]->getRes() == "Reservado")
			{
				cout << "A sala de reuniao escolhida encontra-se reservada. Por favor escolher outra: ";
				cin >> i;
			}

			cout << "Preco a pagar: ";

			preco = h->getSalasReuniao()[i-1]->getPreco();
			if((d1.getMes() >= 6 && d1.getMes() <= 8) || d1.getMes() == 12)
				preco = preco * 1.50;
			preco = preco * numDias;

			cout << preco;

			h->getSalasReuniao()[i-1]->setRes();

			cout << "Reserva finalizada" << endl;

			return true;
		}
}



