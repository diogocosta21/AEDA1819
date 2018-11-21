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
int Quarto::getPrecoQuarto() const
{
	if(getTipo() == "simples")
	{
		if(getLocal() == "frente")
			return simples_preco * 1.25;
		else if(getLocal() == "traseiras")
			return simples_preco;
	}

	else //(getTipo() == "duplo")
	{
		if(getLocal() == "frente")
			return duplo_preco * 1.25;
		else if(getLocal() == "traseiras")
			return duplo_preco;
	}
}

int Quarto::getPrecoMes(Data d) const {
	int mes = d.getMes();
	if ((6 <= mes && mes <= 8) || mes == 12){
		return getPrecoQuarto()*1.5;
	}
	else
		return getPrecoQuarto();
}

int Quarto::getPrecoFinal(Data d1, Data d2) const {
	int d1ano = d1.getAno();
	int d1mes = d1.getMes();
	int d1dia = d1.getDia();
	int d2ano = d2.getAno();
	int d2mes = d2.getMes();
	int d2dia = d2.getDia();

	int dias100 = 0;
	int dias150 = 0;

	int limite = 530;     // ate fim de junho
	int limite2 = 831;    // ate fim de agosto
	int limite3 = 1130;   // ate fim de novembro
	int limite4 = 1231;   // ate fim de dezembro

	if (d1ano != d2ano)
	{
		Data FimAno = Data(31, 12, d1ano);
		Data InicioAno = Data(01, 01, (d1ano++));
		int intervalo1 = getPrecoFinal( d1, FimAno);
		int intervalo2 = getPrecoFinal( InicioAno, d2);
		return intervalo1 + intervalo2;

	}
	else {
		int auxd1, auxd2;
		auxd1 = (d1mes*100) + d1dia;
		auxd2 = (d2mes*100) + d2dia;
		for (int aux = auxd1 ; aux <= auxd2 ; aux++) {
			if (aux <= limite)
				dias100++;
			if (aux <= limite2)
				dias150++;
			if (aux <= limite3)
				dias100++;
			if (aux <= limite4)
				dias150++;
		}
	}
	return dias100*getPrecoQuarto() + dias150*1.5*getPrecoQuarto();
}

/**
 * Retorna informacao sobre se o quarto est� ou nao reservado
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
	reservado = true;  // falta ir ao ficheiro txt e mudar
}

/**
 * Escreve para ofstream a informacao do quarto no formato usado no ficheiro de texto
 * os - ostream onde � guardada informacao
 * c1 - Quarto cuja informacao � lida
 */
ostream &operator << (ostream &os, Quarto &q1)
{
	os << q1.getTipo() << ", " << q1.getLocal() << ", " << q1.getPrecoQuarto();
	return os;
}

/**
 * Retorna string com o local, o tipo e o preco do quarto
 */
string Quarto::getInformacao() const
{
	stringstream ss;
	ss << " " << getTipo() << ", " << getLocal() << " " << getPrecoQuarto();
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

int SalaReuniao::getPrecoMes(Data d) const {
	int mes = d.getMes();
	if ((6 <= mes && mes <= 8) || mes == 12){
		return getPreco()*1.5;
	}
	else
		return getPreco();
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
 * Retorna informacao sobre se a sala de reuniao est� ou nao reservada
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
 * os - ostream onde � guardada informacao
 * c1 - Sala de informacao cuja informacao � lida
 */
ostream &operator << (ostream &os, SalaReuniao &sr1)
{
	os << sr1.getCapacidade() << ", " << sr1.getVideo() << ", " << sr1.getAudio() << ", " << sr1.getRes();
	return os;
}


/**
 * Retorna string com a capacidade, informacao dos equipamentos e o preco do quarto
 */
string SalaReuniao::getInformacao() const
{
	stringstream ss;
	ss << " " << getCapacidade() << " - " << getVideo() << " - " << getAudio() << " - " << getRes() << " - " << getPreco();
	return ss.str();
}

