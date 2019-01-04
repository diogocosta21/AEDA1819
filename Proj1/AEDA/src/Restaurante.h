/*
 * Restaurante.h
 *
 *  Created on: 04/01/2019
 *      Author: joao_
 */

#ifndef RESTAURANTE_H_
#define RESTAURANTE_H_

#include <string>

using namespace std;



class Restaurante {
private:
	/**
	 * @brief nome do restaurante
	 */
	string nome;
	/**
	 * @brief tipo de cozinha do restaurante.
	 */
	string tipo;
	/**
	 * @brief distancia do restaurante ao hotel.
	 */
	int dist;
public:
	/**
	 * Construtor usado para inicializar a arvore binaria de pesquisa.
	 */
	Restaurante(){};
	Restaurante(string n, string t, int d);
	virtual ~Restaurante();
	void setNome(string n);
	void setTipo(string t);
	void setDist(int d);
	string getNome() const;
	string getTipo() const;
	int getDist() const;

	friend ostream &operator<< (ostream &os, Restaurante &r1);
	bool operator< (const Restaurante & r2) const;
	bool operator== (const Restaurante & r2) const;
 };



#endif /* RESTAURANTE_H_ */
