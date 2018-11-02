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



bool CompanyMenu(Company *c)
{
	unsigned int optionCM = 0;
	bool flag = false;

	while (!flag)
	{

		cout << "***********************" << endl;
		cout << "|     Porto Rivers    |" << endl;
		cout << "***********************" << endl << endl;


		cout << "1 Make reservation"   << endl;
		cout << "2 Cancel reservation" << endl;
		cout << "3 Work with us"     << endl;
		cout << "4 View files"         << endl;
		cout << "5 Check bank"		   << endl;
		cout << "6 Exit"               << endl;
		cout << "Insert the desired option: ";

		cin >> optionCM;
		cin.clear();
		cout << endl;

		switch (optionCM)
		{
			case 1:
			{
				MakeReservation (c);
				break;
			}

			case 2:
			{
				CancelReservation (c);
				break;
			}

			case 3:
			{
				unsigned int optionCM3 = 0;
				bool flag2 = false;
				while (!flag2)
				{
					cout << "***********************" << endl;
					cout << "|     Work with us    |" << endl;
					cout << "***********************" << endl << endl;

					cout << "1 Become a supplier" << endl;
					cout << "2 Add offer" << endl;
					cout << "3 Back" << endl;
					cout << "Insert the desired option: ";

					cin >> optionCM3;
					cin.clear();
					cin.ignore(10000,'\n');
