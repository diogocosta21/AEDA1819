/*
 * Data.cpp
 *
 *  Created on: 06/11/2018
 *      Author: joao_
 */

#include "Data.h"


/**
 * Construtor
 * @param d - dia
 * @param m - mes
 * @param a - ano
 */
Data::Data(unsigned int d, unsigned int m, unsigned int a) : dia(d), mes(m), ano(a)
{}

/**
 * Construtor com string
 * @param string da data no formato dd-mm-aaaa
 */
Data::Data(string data)
{
	string d = data.substr(0, data.find('-'));
	data = data.substr(data.find('-') + 1);
	string m = data.substr(0, data.find('-'));
	data = data.substr(data.find('-') + 1);

	dia = (unsigned int) stoi(d.c_str());
	mes = (unsigned int) stoi(m.c_str());;
	ano = (unsigned int) stoi(data.c_str());;

}

/**
 * Destrutor
 */
Data::~Data()
{}

/**
 * @return dia
 */
unsigned int Data::getDia() const
{
	return this->dia;
}


/**
 * @return mes
 */
unsigned int Data::getMes() const
{
	return this->mes;
}


/**
 * @return ano
 */
unsigned int Data::getAno() const
{
	return this->ano;
}


/**
 * Converte a data em dias desde inicio do ano
 * @return numero de dias
 */
unsigned int Data::converteEmDias ()
{
	int converteEmDias = 0;
	int diasdoMes[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	converteEmDias+= dia;
	for (int i = mes-1; i > 0; i--)
	{
	    converteEmDias += diasdoMes[i];
	}
	for (int i = ano-1; i > 1582; i--)
	{
	    if(ano % 4 == 0)
	    	converteEmDias += 366;
	    else
	    	converteEmDias += 365;
	}

	return converteEmDias;
}


/**
 *
 */
unsigned int Data::valorData() {
	int valordata = 0;
	valordata = (ano * 10000) + (mes*100) + dia;
	return valordata;
}


/**
 * @return numero de dias entre duas datas
 * @param d1 - data a ser comparada
 */
unsigned int Data::daysBetween (Data d1)
{
	if (this->converteEmDias() > d1.converteEmDias())
	        return this->converteEmDias() - d1.converteEmDias();
	    else
	        return d1.converteEmDias() - this->converteEmDias();
}


/**
 * @return true se a data � anterior ou igual � data da direita
 * @param right - data a ser comparada
 */
bool Data::operator <= (const Data& right) const
{
	vector<int> l,r;

	l.push_back(this->ano);
	l.push_back(this->mes);
	l.push_back(this->dia);
	r.push_back(right.ano);
	r.push_back(right.mes);
	r.push_back(right.dia);

	if (l == r)
		return true;

	for(unsigned int i = 0; i < l.size(); i++)
	{
		if(l[i] < r[i])
			return true;
		else if(l[i] > r[i])
			return false;
	}

	return false;
}


/**
 * @return true se duas data sao iguais
 * @param right - data a ser comparada
 */
bool Data::operator ==(const Data& right) const

{
	if(this->dia == right.dia && this->mes== right.mes && this->ano == right.ano)
		return true;

	return false;
}


/**
 * @return true se a data � valida
 */
bool Data::validateData()
{
	if(mes < 0 || mes > 12)
		return false;
	if(dia < 0 || dia > 31)
		return false;
	if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
		return false;

	if(mes == 2 && ano%4 == 0 && dia > 29)
		return false;

	if(mes == 2 && ano%4 != 0 && dia > 28)
		return false;

	return true;
}


