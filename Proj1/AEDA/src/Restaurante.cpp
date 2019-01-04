/*
 * Restaurante.cpp
 *
 *  Created on: 04/01/2019
 *      Author: joao_
 */

#include "Restaurante.h"

using namespace std;

/**
 * Construtor para restaurantes das redondezas
 * @param t tipo de cozinha do restaurante
 * @param d distancia do restaurante ao hotel
 */
Restaurante::Restaurante(string n, string t, int d)
{
	this->nome = n;
	this->tipo = t;
	this->dist = d;
}

/**
 * Destrutor
 */
Restaurante::~Restaurante()
{}

/**
 * Altera o nome do restaurante
 */
void Restaurante::setNome(string n)
{
	nome = n;
}

/**
 * Altera o tipo de cozinha
 */
void Restaurante::setTipo(string t)
{
	tipo = t;
}

/**
 * Altera distancia do restaurante ao hotel
 */
void Restaurante::setDist(int d)
{
	dist = d;
}

/**
 * @return nome do restaurante
 */
string Restaurante::getNome() const
{
	return this->nome;
}

/**
 * @return tipo de cozinha do restaurante
 */
string Restaurante::getTipo() const
{
	return this->tipo;
}

/**
 * @return distancia do restaurante ao hotel
 */
int Restaurante::getDist() const
{
	return this->dist;
}

/**
 * Overload do operador <
 * @param r2 restaurante a ser comparado
 * @return verdadeiro ou falso de acordo com o tipo de cozinha do restaurante por ordem alfabetica. Se o tipo for igual, retorna verdadeiro ou falso de acordo com a distancia do restaurante ao hotel
 */
bool Restaurante::operator <(const Restaurante & r2) const
{
	if(this->getTipo() == r2.getTipo())
		return this->getDist() <= r2.getDist();

	return this->getTipo() < r2.getTipo();
}

/**
 * Overload do operador ==
 * @param r2 restaurante a ser comparado
 * @return verdadeiro se o restaurante tiver o mesmo nome, o mesmo tipo de cozinha e a mesma distancia ao hotel
 */
bool Restaurante::operator ==(const Restaurante & r2) const
{
	if(this->getNome() == r2.getNome())
		if(this->getTipo() == r2.getTipo())
			if(this->getDist() == r2.getDist())
				return true;

	return false;
}

/**
 * Overload do operador <<
 * @param os ostream onde se guarda a infomaçao
 * @param r1 restaurante cuja informaçao e guardada
 */
ostream &operator<< (ostream &os, Restaurante &r1)
{
	os << r1.getNome() << ", " << r1.getTipo() << ", " << r1.getDist() << ";";
}
