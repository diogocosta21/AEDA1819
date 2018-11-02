/*
 * SalasReuniao.cpp
 *
 *  Created on: 02/11/2018
 *      Author: up201505198
 */


#include "SalasReuniao.h"


SalaReuniao::SalaReuniao(int Capacidade) : capacidade (Capacidade) {
	if (capacidade <= 20)
		preco = 100;
	if (capacidade <= 50 && capacidade > 20)
		preco = 200;
};


int SalaReuniao::getPreco() const {

	int acrescimos = 0;
	if (video == true) {acrescimos += acres_video;}
	if (audio == true) {acrescimos += acres_audio;}
	if (capacidade <= 20)
		{
		int aux = preco + acrescimos;
		return aux;
		}
	else if (capacidade > 20 && capacidade <= 50) {
		int aux = preco + acrescimos;
		return aux;
	}
	else {return 0;}

	/* else if (capacidade > 50 ) {excecao demasiado}
	 * else excecao invalido
	 */
}



int SalaReuniao::getCapacidade() const {
	return capacidade;
}
