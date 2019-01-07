/*
 * Excurssoes.h
 *
 *  Created on: 07/01/2019
 *      Author: up201505198
 */

#ifndef AEDA_SRC_EXCURSSOES_H_
#define AEDA_SRC_EXCURSSOES_H_

#include <queue>
#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Carrinha {

private:

	priority_queue <Carrinha> carrinhas;

	vector <Carrinha> carrinhasv;

	int numlugaresoc;

	int id_carrinha;

public:

	Carrinha (int id, int num);
	void ordenavec() const;
	void VecparaQueue() const;
	void QueueparaVec() const;

};

#endif /* AEDA_SRC_EXCURSSOES_H_ */
