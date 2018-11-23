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
	cin.ignore(10000, '\n');
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
		cout << "Data : " << d.getDia() << "-" << d.getMes() << "-" << d.getAno() << endl << endl;


		cout << "1 Fazer uma Reserva"     << endl;
		cout << "2 Criar um espaco"       << endl;
		cout << "3 Contratar funcionario" << endl;
		cout << "4 Ver Ficheiros" 	      << endl;
		cout << "5 Sair"                  << endl;
		cout << "Inserir opcao que pretende: ";

		cin >> optionCM;
		cin.clear();
		cin.ignore(10000, '\n');
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
				CriarEspaco (h);
				break;
			}

			case 3:
			{
				ContratarFuncionarios(h);
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
	string espaco;
	int preco;
	string d1, d2;

	cout << "Nome? " ;
	getline(cin, nome);
	cout << endl;
	cout << "NIF? " ;
	cin >> NIF;
	cin.clear();
	cin.ignore(10000, '\n');

	while ((100000000 > NIF) || (NIF > 999999999))
	{
		cout << endl << "Por favor introduza um NIF valido (numero com 9 digitos): " ;
		cin >> NIF;
		cin.clear();
		cin.ignore(10000, '\n');
	}


	cout << endl;

	for(unsigned int i = 0; i < h->getClientes().size(); i++)
	{
		if(h->getClientes()[i]->getNIF() == NIF)
		{
			existe = true;
		}
	}
	if(!existe)
	{
		h->addCliente(nome, NIF, 0);
	}

	cout << "Data de inicio da reserva (dd-mm-aaaa): ";
	cin >> d1;
	cin.clear();
	cin.ignore(10000, '\n');
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
	cin.clear();
	cin.ignore(10000, '\n');
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

	cout << "Tipo de reserva que pretende efetuar( '1'->quarto) ou '2'->sala de reuniao ): ";
	cin >> espaco;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl;


	if(espaco == "1")
	{
		cout << "Quartos do hotel: " << endl << endl;
		h->printQuartos();
		cout << endl << "Numero do quarto que pretende reservar: ";
		unsigned int i;
		cin >> i;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << endl;

		while(h->getQuartos()[i-1]->getRes() == "Reservado")
		{
			cout << "O quarto escolhido encontra-se reservado. Por favor escolher outro: ";
			cin >> i;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl;
		}


		cout << "Preco a pagar: ";

		preco = h->getQuartos()[i-1]->getPrecoFinal(d1, d2);

		cout << preco << endl << endl;

		//h->getQuartos()[i-1]->setRes();
		//h->getQuartos()[i-1]->getReservas().push_back(data1);
		//h->getQuartos()[i-1]->getReservas().push_back(data2);

		string opcaoconf;
		cout << "Deseja confirmar a reserva? ('sim' ou 'nao'): ";
		cin >> opcaoconf;
		cin.clear();
		cin.ignore(10000, '\n');

		bool resconf = false;
		while (!resconf) {
			if (opcaoconf == "sim"){
				h->getQuartos()[i-1]->setRes();
				for(unsigned int i = 0; i < h->getClientes().size(); i++)
					{
						if(h->getClientes()[i]->getNIF() == NIF)
						{
							h->getClientes()[i]->incNR();
							int aa = (h->getClientes()[i]->getNR());
						}
					}
				cout << endl << "Reserva confirmada e finalizada" << endl << endl;
				resconf = true;
				}


			else if (opcaoconf == "nao") {
				cout << "Reserva nao confirmada" << endl << endl;
				resconf = true;
			}
			else {
				try {
					throw OpcaoInvalidast(opcaoconf);
				}
				catch (OpcaoInvalidast &e)
					{
						cout << e.getOpcao() << " nao e uma opcao valida" << endl << endl;
					}
			}
		}


		return true;
	}
	else if(espaco == "2")
	{
		cout << "Salas de reuniao: " << endl << endl;
		h->printSalasReuniao();
		cout << endl << "Numero da sala de reuniao que pretende reservar: ";
		unsigned int i;
		cin >> i;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << endl;

		while(h->getSalasReuniao()[i-1]->getRes() == "Reservada")
		{
			cout << "A sala de reuniao escolhida encontra-se reservada. Por favor escolher outra: ";
			cin >> i;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl;
		}
		cout << "Preco a pagar: ";

		int precoDia;
		precoDia = h->getSalasReuniao()[i-1]->getPrecoFinalSalas(d1, d2);

		cout << precoDia << endl << endl;

		string opcaoconf;
		cout << "Deseja confirmar a reserva? ('sim' ou 'nao'): ";
		cin >> opcaoconf;
		cin.clear();
		cin.ignore(10000, '\n');

		bool resconf = false;
		while (!resconf) {
			if (opcaoconf == "sim"){
				h->getSalasReuniao()[i-1]->setRes();
				for(unsigned int i = 0; i < h->getClientes().size(); i++)
					{
						if(h->getClientes()[i]->getNIF() == NIF)
						{
							h->getClientes()[i]->incNR();
						}
					}
				cout << "Reserva confirmada e finalizada" << endl << endl;
				resconf = true;
				}


			else if (opcaoconf == "nao") {
				cout << "Reserva nao confirmada" << endl << endl;
				resconf = true;
			}
			else {
				try {
					throw OpcaoInvalidast(opcaoconf);
				}
				catch (OpcaoInvalidast &e)
					{
						cout << e.getOpcao() << " nao e uma opcao valida" << endl << endl;
					}
			break;
			}
		}


		return true;
	}
	cout << endl;
	return true;
}

bool CriarEspaco (Hotel *h)
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
					//vector<Data> data;

					cout << endl << "Tipo de quarto ('simples' ou 'duplo'): ";
					cin >> tipo;
					cin.clear();
					cin.ignore(10000, '\n');

					while ((tipo != "simples") && (tipo != "duplo")){
						try{
							throw OpcaoInvalidast(tipo);
						}
						catch (OpcaoInvalidast&e) {
							cout << endl << e.getOpcao() << " nao e uma opcao valida. Por favor introduza uma opcao valida ('simples' ou 'duplo'): ";
						}
						cin >> tipo;
						cin.clear();
						cin.ignore(10000, '\n');
						cout << endl;
					}

					cout << endl << "Local do quarto ('frente' ou 'traseiras'): ";
					cin >> local;
					cin.clear();
					cin.ignore(10000, '\n');

					while ((local != "frente") && (local != "traseiras")){
						try {
							throw OpcaoInvalidast(local);
						}
						catch (OpcaoInvalidast&e) {
							cout << endl << e.getOpcao() << " nao e uma opcao valida. Por favor introduza uma opcao valida ('frente' ou 'traseiras'): ";
						}
						cin >> local;
						cin.clear();
						cin.ignore(10000, '\n');
					}



					Supervisor *s = h->getSupComMenosEspacos();

					string n = s->getNome();

					h->addQuarto(tipo, local, res, n);

					h->getQuartos()[h->getQuartos().size() - 1]->setSupervisor(s);
					h->getSupComMenosEspacos()->incNr();

					cout << endl;
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
					cin.ignore(10000, '\n');
					cout << endl;

					while ((capacidade < 0 ) || (capacidade > 50)) {
						try {
								throw CapacidadeInvalida(capacidade);
							}
						catch (CapacidadeInvalida &e)
							{
								cout << "A capacidade deve ser um numero inteiro entre 0 e 50." << endl;
							}
						cout << "Por favor tente de novo: " ;
						cin >> capacidade ;
						cin.clear();
						cin.ignore(10000, '\n');
						cout << endl;
					}

					cout << "Equipamento de video('sim' ou 'nao'): ";
					cin >> vid;
					cin.clear();
					cin.ignore(10000, '\n');
					cout << endl;


					while ((vid != "sim" ) && ( vid != "nao")) {
						try {
							throw OpcaoInvalidast(vid);
						}
						catch (OpcaoInvalidast &e)
							{
								cout << e.getOpcao() << " nao e uma opcao valida" << endl << endl;
							}
						cout << "Por favor introduza uma resposta valida ('sim' ou 'nao'): ";
						cin >> vid;
						cin.clear();
						cin.ignore(10000, '\n');
						cout << endl;
					}

					if(vid == "sim")
						video = true;
					else if(vid == "nao")
						video = false;

					cout << "Equipamento de audio('sim' ou 'nao'): ";
					cin >> aud;
					cin.clear();
					cin.ignore(10000, '\n');
					cout << endl;



					while ((aud != "sim" ) && ( aud != "nao")) {
						try {
							throw OpcaoInvalidast(aud);
						}
						catch (OpcaoInvalidast&e)
						{
							cout << e.getOpcao() << " nao e uma opcao valida" << endl << endl;
						}

						cout << "Por favor introduza uma resposta valida ('sim' ou 'nao'): ";
						cin >> aud;
						cin.clear();
						cin.ignore(10000, '\n');
						cout << endl;
						}

					if(aud == "sim")
							audio = true;
					else if(aud == "nao")
						audio = false;

					Supervisor *s = h->getSupComMenosEspacos();
					string n = s->getNome();
					h->addSalaReuniao(capacidade, video, audio, res, n);
					h->getQuartos()[h->getQuartos().size() - 1]->setSupervisor(s);
					h->getSupComMenosEspacos()->incNr();

					cout << endl;
					break;
				}

				case 3:
					flag2 = true;
			}
		}

	cout << endl;
	return true;
}

bool ContratarFuncionarios(Hotel *h)
{
	string nome;
	string sup;

	cout << "Supervisor('sim' ou 'nao')? ";
	cin >> sup;
	cin.clear();
	cin.ignore(10000, '\n');
	cout << endl;

	while ((sup != "sim") && (sup != "nao")) {
		try {
			throw OpcaoInvalidast(sup);
		}
		catch (OpcaoInvalidast&e)
		{
			cout << e.getOpcao() << " nao e uma opcao valida. Por favor introduza uma opcao valida ('sim' ou 'nao'): ";
			cin >> sup;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << endl;
		}
	}

	if(sup == "nao")
	{
		cout << "Nome do funcionario: ";
		getline(cin, nome);
		cout << endl;

		h->addFuncionario(nome);
	}
	else if(sup == "sim")
	{
		int numQuartos;

		cout << "Nome do funcionario: ";
		getline(cin,nome);
		cout << endl;

		numQuartos = 0;

		h->addSupervisor(nome, numQuartos);
	}

	cout << endl;
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
		cout << "Inserir a opcao desejada: ";
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
				string s;
				cout <<endl;
				cout << "Escolher ficheiro('funcionarios' ou 'supervisores'): ";
				cin >> s;
				if (s == "funcionarios")
				{
					h->printFuncionarios();
					h->printSupervisores();
				}
				else if(s == "supervisores")
					h->printSupervisores();

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

							break;
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

	cout << endl;
	return true;
}

