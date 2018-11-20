/*
 * Reservas.h
 *
 *  Created on: 16/11/2018
 *      Author: joao_
 */

#ifndef RESERVAS_H_
#define RESERVAS_H_

using namespace std;

#include "Cliente.h"
#include "Espaco.h"
#include "Data.h"

class Reservation {
private:
	/**
	 * Cliente que faz reserva
	 */
	Cliente *cliente;
	/**
	 * Data da reserva
	 */
	Data data;
	/**
	 * Preco da reserva
	 */
	unsigned int price;
	/**
	 * Numero da reserva
	 */
	unsigned int id;
public:
	Reservation(){};
	Reservation(Cliente *c1, Data d1, unsigned int price, unsigned int id);
	virtual ~Reservation();
	unsigned int getPrice();
	unsigned int getId();
	unsigned int


};




#endif /* RESERVAS_H_ */
