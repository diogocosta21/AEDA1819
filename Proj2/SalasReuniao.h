
#ifndef SALASREUNIAO_H
#define SALASREUNIAO_H


#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>

class SalaReuniao {

	int preco;
	int capacidade;
	bool video = false;
	bool audio = false;
	int acres_video = 50;
	int acres_audio = 50;

public:
	SalaReuniao();
	SalaReuniao(int Capacidade);
	int getPreco() const;
	int getCapacidade() const;
};






#endif /*SALASREUNAIAO_H */
