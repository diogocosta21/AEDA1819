/*
 * Espaco.cpp
 *
 *  Created on: 02/11/2018
 *      Author: joao_
 */


#include "Espaco.h"
#include <iostream>

using namespace std;

/**
 * Define funcionario responsavel pelo espaco
 */
void Espaco::setSupervisor(Supervisor *sup)
{
	this -> sup = sup;
}

/**
 * Retorna funcionario responsavel pelo espaco
 */
Supervisor *Espaco::getSupervisor() const
{
	return sup;
}


//=============================================

/**
 * Constructor
 * t - Tipo de quarto
 * l - Local do quarto
 */
Quarto::Quarto(string t, string l, bool res)
{
	tipo = t;
	local = l;
	reservado = res;
}

/**
 * Retorna o tipo de quarto
 */
string Quarto::getTipo() const
{
	return tipo;
}

/**
 * Retorna local do quarto
 */
string Quarto::getLocal() const
{
	return local;
}

/**
 * Retrona preco do quarto
 */
int Quarto::getPreco() const
{
	if(getTipo() == "simples") {
		if(getLocal() == "frente")
			return simples_preco * 1.25;
		else if(getLocal() == "traseiras")
			return simples_preco;
		//else excecao
	}

	else if(getTipo() == "duplo") {
		if(getLocal() == "frente")
			return duplo_preco * 1.25;
		else if(getLocal() == "traseiras")
			return duplo_preco;
		//else excecao

		//else excecao
	}
}

/**
 * Retorna informacao sobre se o quarto está ou nao reservado
 */
string Quarto::getRes() const
{
	if(reservado)
		return "Reservado";
	else
		return "Nao reservado";
}

/**
 * Poe quarto reservado
 */
void Quarto::setRes()
{
	reservado = true;
}

/**
 * Escreve para ofstream a informacao do quarto no formato usado no ficheiro de texto
 * os - ostream onde é guardada informacao
 * c1 - Quarto cuja informacao é lida
 */
ostream &operator << (ostream &os, Quarto &q1)
{
	os << q1.getTipo() << ", " << q1.getLocal() << ", " << q1.getPreco();
	return os;
}

/**
 * Retorna string com o local, o tipo e o preco do quarto
 */
string Quarto::getInformacao() const
{
	stringstream ss;
	ss << " " << getTipo() << ", " << getLocal() << " " << getPreco();
	return ss.str();
}

//==========================================================================

/**
 * Constructor
 * capacidade - Capacidade da sala de reuniao
 * video - verdade se a sala tem equipamento de video
 * audio - verdade se a sala tem equipamento de audio
 */
SalaReuniao::SalaReuniao(int Capacidade, bool video, bool audio, bool reservado) : capacidade (Capacidade) {
	this->video=video;
	this->audio=audio;

	if (capacidade <= 20)
		preco = 100;
	if (capacidade <= 50 && capacidade > 20)
		preco = 200;

	this->reservado=reservado;
};

/**
 * Retorna preco da sala de reuniao
 */
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

/**
 * Retorna string com informacao da existencia de equipamento de video na sala
 */
string SalaReuniao::getVideo() const
{
	if(video)
		return "Com equipamento de video";
	else
		return "Sem equipamento de video";
}


/**
 * Retorna string com informacao da existencia de equipamento de audio na sala
 */
string SalaReuniao::getAudio() const
{
	if(audio)
		return "Com equipamento de audio";
	else
		return "Sem equipamento de audio";
}


/**
 * Retorna capacidade da sala
 */
int SalaReuniao::getCapacidade() const {
	return capacidade;
}

/**
 * Retorna informacao sobre se a sala de reuniao está ou nao reservada
 */
string SalaReuniao::getRes() const
{
	if(reservado)
		return "Reservada";
	else
		return "Nao reservada";
}

/**
 * Poe sala de reuniao reservada
 */
void SalaReuniao::setRes()
{
	reservado = true;
}

/**
 * Escreve para ofstream a informacao da sala de reuniao no formato usado no ficheiro de texto
 * os - ostream onde é guardada informacao
 * c1 - Sala de informacao cuja informacao é lida
 */
ostream &operator << (ostream &os, SalaReuniao &sr1)
{
	os << sr1.getCapacidade() << ", " << sr1.getVideo() << ", " << sr1.getAudio() << ", " << sr1.getPreco();
	return os;
}


/**
 * Retorna string com a capacidade, informacao dos equipamentos e o preco do quarto
 */
string SalaReuniao::getInformacao() const
{
	stringstream ss;
	ss << " " << getCapacidade() << " " << getVideo() << " " << getAudio() << " " << getPreco();
	return ss.str();
}


