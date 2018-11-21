#include <iostream>
#include <limits>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>

#include "Menu.h"

using namespace std;

Data setData()
{
	string d;
	cout << "Data de hoje (dd-mm-aaaa): ";
	cin >> d;
	cin.clear();
	cout << endl;
	return Data(d);
}

static Data d = setData();

bool HotelMenu(Hotel *h)
{
	unsigned int optionCM = 0;
	bool flag = false;

	while (!flag)
	{

		cout << "***********************" << endl;
		cout << "|      Bem-vindo      |" << endl;
		cout << "***********************" << endl;
		cout << "Date : " << d.getDia() << "-" << d.getMes() << "-" << d.getAno() << endl << endl;


		cout << "1 Fazer uma Reserva"     << endl;
		cout << "2 Criar um espaco"       << endl;
		cout << "3 Contratar funcionario" << endl;
		cout << "4 Ver Ficheiros" 	      << endl;
		cout << "5 Sair"                  << endl;
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
							cin.clear();
							cin.ignore(10000,'\n');
							cout << endl;

							cout << "Local do quarto(frente ou traseiras): ";
							cin >> local;
							cin.clear();
							cin.ignore(10000,'\n');
							cout << endl;

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
							cin.clear();
							cin.ignore(10000,'\n');
							cout << endl;

							cout << "Equipamento de video('sim' ou 'nao'): ";
							cin >> vid;
							cin.clear();
							cin.ignore(10000,'\n');
							cout << endl;

							if(vid == "sim")
								video = true;
							else if(vid == "nao")
								video = false;

							cout << "Equipamento de audio('sim' ou 'nao'): ";
							cin >> aud;
							cin.clear();
							cin.ignore(10000,'\n');
							cout << endl;

							if(aud == "sim")
								audio = true;
							else if(aud == "nao")
								audio = false;

							h->addSalaReuniao(capacidade, video, audio, res);

							break;
						}

						case 3:
						{
							flag2=true;
							break;

						}

					}
				}
				break;
			}

			case 3:
			{
				string nome;
				string sup;
				bool supervisor;

				cout << "Nome do funcionario: ";
				cin >> nome;
				cin.clear();
				cin.ignore(10000,'\n');
				cout << endl;

				cout << "Supervisor('sim' ou 'nao')? ";
				cin >> sup;
				cin.clear();
				cin.ignore(10000,'\n');
				cout << endl;

				if(sup == "sim")
					supervisor = true;
				else if(sup == "nao")
					supervisor = false;

				h->addFuncionario(nome, supervisor);

				break;
			}

			case 4:
			{
				VerFicheiro(h);
				break;
			}

			case 5:
			{
				flag = true;
				break;
			}
		}
	}
	return true;
}

bool FazerReserva (Hotel *h)
{
	bool existe = false;
	string nome;
	unsigned int NIF;
	unsigned int numRes;
	int numDias;
	string espaco;
	int preco;
	string d1, d2;

	cout << "Nome? " << endl;
	cin >> nome;
	cin.clear();
	cin.ignore(10000,'\n');
	cout << endl;
	cout << "NIF? " << endl;
	cin >> NIF;
	cin.clear();
	cin.ignore(10000,'\n');
	cout << endl;

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

	cout << "Data de inicio da reserva (dd-mm-aaaa): ";
	cin >> d1;
	Data data1 = Data(d1);
	while (data1.validateData() == false)
	{
		cout << "A data introduzida nao e valida, por favor introduza uma data valida (formato dd-mm-aaaa): ";
		cin >> d1;
		cin.clear();
		cin.ignore(10000, '\n');
		data1 = Data (d1);
	}

	cout << "Data de fim da reserva (dd-mm-aaaa): ";
	cin >> d2;
	Data data2 = Data(d2);
	while (data1.validateData() == false)
	{
		cout << "A data introduzida nao e valida, por favor introduza uma data valida (formato dd-mm-aaaa): ";
		cin >> d2;
		cin.clear();
		cin.ignore(10000, '\n');
		data2 = Data (d2);
	}

	int data1valor, data2valor;
	data1valor = data1.valorData();
	data2valor = data2.valorData();

	while (data2valor < data1valor) {
		cout << "A data de fim e anterior a data de inicio da reserva. Que data pretende editar? ('inicio' ou 'fim'): ";
		string aux;
		cin >> aux;
		cin.clear();
		cin.ignore(10000, '\n');
		if (aux == "inicio") {
			cout << "Data de inicio da reserva (dd-mm-aaaa): ";
			cin >> d1;
			Data data1 = Data(d1);
			while (data1.validateData() == false)
			{
				cout << "A data introduzida nao e valida, por favor introduza uma data valida (formato dd-mm-aaaa): ";
				cin >> d1;
				cin.clear();
				cin.ignore(10000, '\n');
				data1 = Data (d1);
			}
			data1valor = data1.valorData();
		}
		else if (aux == "fim") {
			cout << "Data de fim da reserva (dd-mm-aaaa): ";
			cin >> d2;
			Data data2 = Data(d2);
			while (data2.validateData() == false)
			{
				cout << "A data introduzida nao e valida, por favor introduza uma data valida (formato dd-mm-aaaa): ";
				cin >> d2;
				cin.clear();
				cin.ignore(10000, '\n');
				data2 = Data (d2);
			}
			data2valor = data2.valorData();
		}
		else {
			try {
				throw OpcaoInvalidast(aux);
			}
			catch (OpcaoInvalidast &e)
			{
				cout << e.getOpcao() << " nao e uma opcao valida" << endl << endl;
			}
		}
	}

	cout << "Tipo de reserva que pretende efetuar(quarto ou sala de reuniao): ";
	cin >> espaco;


	if(espaco == "quarto")
	{


		cout << "Quartos do hotel: " << endl << endl;
		h->printQuartosPorPreco();
		cout << endl << "Numero do quarto que pretende reservar: ";
		unsigned int i;
		cin >> i;
		cin.clear();
		cin.ignore(10000,'\n');
		cout << endl;

		while(h->getQuartos()[i-1]->getRes() == "Reservado")
		{
			cout << "O quarto escolhido encontra-se reservado. Por favor escolher outro: ";
			cin >> i;
			cin.clear();
			cout << endl;
		}


		cout << "Preco a pagar: ";

		preco = h->getQuartos()[i-1]->getPrecoFinal(d1, d2);

		cout << preco;

		h->getQuartos()[i-1]->setRes();

		cout << "Reserva finalizada";

		return true;
	}

	if(espaco == "sala de reuniao")
		{
			cout << "Salas de reuniao: " << endl << endl;
			h->printSalasReuniaoNaoReservadasPorPreco();
			cout << endl << "Numero da sala de reuniao que pretende reservar: ";
			unsigned int i;
			cin >> i;
			cin.clear();
			cout << endl;

			while(h->getSalasReuniao()[i-1]->getRes() == "Reservado")
			{
				cout << "A sala de reuniao escolhida encontra-se reservada. Por favor escolher outra: ";
				cin >> i;
				cin.clear();
				cout << endl;
			}

			cout << "Preco a pagar: ";

			int precoDia;
			precoDia = h->getQuartos()[i-1]->getPrecoMes(d);

			preco = precoDia * numDias;

			cout << preco;

			h->getSalasReuniao()[i-1]->setRes();

			cout << "Reserva finalizada" << endl;

			return true;
		}
	return true;
}

bool VerFicheiro (Hotel *h)
{
	unsigned int optionVFM;
	bool flag = false;

	while (!flag)
	{
		cout << "***************************" << endl;
		cout << "|      Ver Ficheiros      |" << endl;
		cout << "***************************" << endl << endl;

		cout << "1 Clientes" << endl;
		cout << "2 Funcionarios" << endl;
		cout << "3 Espacos" << endl;
		cout << "4 Back" << endl;
		cout << "Insira a opcao desejada: ";
		cin >> optionVFM;
		cin.clear();
		cin.ignore(10000, '\n');

		switch(optionVFM)
		{
			case 1:
			{
				int optionVFM1;
				bool flag2 = false;

				while (!flag2)
				{
					cout << endl;
					cout << "*************************" << endl;
					cout << "|        Clientes       |" << endl;
					cout << "*************************" << endl << endl;

					cout << "1 Ver clientes" << endl;
					cout << "2 Ver clientes por NIF" << endl;
					cout << "3 Back" << endl;
					cout << "Insert the desired option: " << endl;
					cin >> optionVFM1;
					cin.clear();
					cin.ignore(10000, '\n');

					switch (optionVFM1)
					{
						case 1:
						{

							cout << endl << "Clientes:" <<  endl << endl;
							h->printClientes();

							break;
						}

						case 2:
						{
							cout << endl;
							h->printClientesByNIF();
							cout << endl;

							break;
						}
						case 3:
						{
							flag2 = true;
							break;
						}
					}
				}
				break;
			}

			case 2:
			{
				cout <<endl;
				h->printFuncionarios();
				cout << endl;
				break;
			}

			case 3:
			{
				int optionVFM3;
				bool flag2 = false;

				while (!flag2)
				{
					cout << endl;
					cout << "*************************" << endl;
					cout << "|        Espacos        |" << endl;
					cout << "*************************" << endl << endl;

					cout << "1 Ver quartos" << endl;
					cout << "2 Ver quartos nao reservados por preco" << endl;
					cout << "3 Ver salas de reuniao" << endl;
					cout << "4 Ver salas de reuniao nao reservadas por preco" << endl;
					cout << "5 Back" << endl;
					cout << "Insert the desired option: " ;
					cin >> optionVFM3;
					cin.clear();
					cin.ignore(10000, '\n');

					switch (optionVFM3)
					{
						case 1:
						{
							cout << endl;
							h->printQuartos();
							break;
						}

						case 2:
						{
							cout << endl;
							h->printQuartosNaoReservadosPorPreco();
							break;
						}

						case 3:
						{
							cout << endl;
							h->printSalasReuniao();

						}

						case 4:
						{
							cout << endl;
							h->printSalasReuniaoNaoReservadasPorPreco();
							break;
						}

						case 5:
						{
							flag2 = true;
							cout << endl;
							break;
						}
					}
				}
				break;
			}

			case 4:
				flag = true;

		}
	}

	return true;
}

