/*
 * Manu.cpp
 *
 *  Created on: 02/11/2018
 *      Author: up201505198
 */


#pragma once
#include <iostream>
#include <limits>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_set>

#include "Menu.h"



bool HotelMenu(Hotel *h)
{
	unsigned int optionCM = 0;
	bool flag = false;

	while (!flag)
	{

		cout << "***********************" << endl;
		cout << "|      Bem-vindo      |" << endl;
		cout << "***********************" << endl << endl;


		cout << "1 Fazer uma Reserva"    << endl;
		cout << "2 Cancelar uma Reserva" << endl;
		cout << "3 Criar um espaco"      << endl;
		cout << "4 Ver Ficheiros" 	     << endl;
		cout << "6 Sair"                 << endl;
		cout << "Insert the desired option: ";

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
				CancelarReserva (h);
				break;
			}

			case 3:
			{
				unsigned int optionCM3 = 0;
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
				}

					cin >> optionCM3;
					cin.clear();
					cin.ignore(10000,'\n');



				}

			}
		}
	}

bool FazerReserva (Hotel *h) {

}

