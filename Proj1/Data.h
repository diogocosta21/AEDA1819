/*
 * Data.h
 *
 *  Created on: 06/11/2018
 *      Author: joao_
 */

#ifndef DATA_H_
#define DATA_H_


#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;


class Data {
private:
	unsigned int dia;
	unsigned int mes;
	unsigned int ano;
public:
	Data(){};
	Data (unsigned int d, unsigned int m, unsigned int a);
	Data (string data);
	virtual ~Data();
	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getAno() const;
	unsigned int converteEmDias();
	unsigned int daysBetween (Data d1);
	bool operator <= (const Data& right) const;
	bool operator ==(const Data& right) const;
	bool validateData();
};


#endif /* DATA_H_ */
