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
 * Define supervisor responsavel pelo espaco
 * @param supervisor responsavel
 */
void Espaco::setSupervisor(Supervisor *sup)
{
	this -> sup = sup;
}

/**
 * @return funcionario responsavel pelo espaco
 */
Supervisor *Espaco::getSupervisor() const
{
	return sup;
}


//=============================================

/**
 * Constructor
 * @param t - Tipo de quarto
 * @param l - Local do quarto
 */
Quarto::Quarto(string t, string l, bool res/*, vector<Data> r*/)
{
	tipo = t;
	local = l;
	reservado = res;
	//this->r = r;
}

/**
 * @return o tipo de quarto
 */
string Quarto::getTipo() const
{
	return tipo;
}

/**
 * @return local do quarto
 */
string Quarto::getLocal() const
{
	return local;
}

/**
 * @return preco do quarto
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

	else if(getTipo() == "duplo")
	{
		if(getLocal() == "frente")
			return duplo_preco * 1.25;
		else if(getLocal() == "traseiras")
			return duplo_preco;
	}
	else
		throw TipoInvalido(tipo);
}

/**
 * @return preco do quarto em determinados meses
 * @param d - data da reserva
 */
int Quarto::getPrecoMes(Data d) const {
	int mes = d.getMes();
	if ((6 <= mes && mes <= 8) || mes == 12){
		return getPrecoQuarto()*1.5;
	}
	else
		return getPrecoQuarto();
}

/**
 * @return preco da reserva
 * @param d1 - dia inicial da reserva
 * @param d2 - dia final da reserva
 */
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
 * @return informacao sobre se o quarto está ou nao reservado
 */
string Quarto::getRes() const
{
	if(reservado == true)
		return "Reservado";
	else
		return "Nao reservado";
}

/**
 * @return vector com as datas das reservas
 */
/*vector<Data> Quarto::getReservas() const
{
	return r;
}*/

/**
 * Poe quarto reservado
 */
void Quarto::setRes()
{
	reservado = true;  // falta ir ao ficheiro txt e mudar
}

/**
 * Escreve para ofstream a informacao do quarto no formato usado no ficheiro de texto
 * @param os - ostream onde é guardada informacao
 * @param c1 - Quarto cuja informacao é lida
 */
ostream &operator << (ostream &os, Quarto &q1)
{
	os << q1.getRes() << ", " << q1.getTipo() << ", " << q1.getLocal(); /*<< ", " << q1.getReservas()*/
	/*for(unsigned int i = 0; i < q1.getReservas().size(); i++)
	{
		os << ", " << q1.getReservas()[i] << " - " << q1.getReservas()[i+1];
	}*/
	return os;
}

/**
 * @return string com o local, o tipo e o preco do quarto
 */
string Quarto::getInformacao() const
{
	stringstream ss;
	ss << getTipo() << ", " << getLocal() << ", " << getRes();
	/*for(unsigned int i = 0; i < getReservas().size(); i++)
	{
		ss << ", " << getReservas()[i] << " - " << getReservas()[i+1];
	}*/
	return ss.str();
}

//==========================================================================

/**
 * Constructor
 * @param capacidade - Capacidade da sala de reuniao
 * @param video - verdade se a sala tem equipamento de video
 * @param audio - verdade se a sala tem equipamento de audio
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
 * @return preco da sala de reuniao
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
	else
		throw CapacidadeInvalida(capacidade);
}


/**
 * @return preco da sala em determinados meses
 * @param d - data da reserva
 */
int SalaReuniao::getPrecoMes(Data d) const {
	int mes = d.getMes();
	if ((6 <= mes && mes <= 8) || mes == 12){
		return getPreco()*1.25;
	}
	else
		return getPreco();
}

/**
 * @return string com informacao da existencia de equipamento de video na sala
 */
string SalaReuniao::getVideo() const
{
	if(video)
		return "Com equipamento de video";
	else
		return "Sem equipamento de video";
}


/**
 * @return string com informacao da existencia de equipamento de audio na sala
 */
string SalaReuniao::getAudio() const
{
	if(audio)
		return "Com equipamento de audio";
	else
		return "Sem equipamento de audio";
}


/**
 * @return capacidade da sala
 */
int SalaReuniao::getCapacidade() const {
	return capacidade;
}

/**
 * @return informacao sobre se a sala de reuniao está ou nao reservada
 */
string SalaReuniao::getRes() const
{
	if(reservado)
		return "Reservada";
	else
		return "Nao reservada";
}

/**
 * @return sala de reuniao reservada
 */
void SalaReuniao::setRes()
{
	reservado = true;
}

/**
 * Escreve para ofstream a informacao da sala de reuniao no formato usado no ficheiro de texto
 * @param os - ostream onde é guardada informacao
 * @param c1 - Sala de informacao cuja informacao é lida
 */
ostream &operator << (ostream &os, SalaReuniao &sr1)
{
	os << sr1.getRes() << ", " << sr1.getCapacidade() << ", " << sr1.getVideo() << ", " << sr1.getAudio();
	return os;
}


/**
 * @return string com a capacidade, informacao dos equipamentos e o preco do quarto
 */
string SalaReuniao::getInformacao() const
{
	stringstream ss;
	ss << " " << getCapacidade() << " -" << getVideo() << " -" << getAudio() << " -" << getRes() << " -" << getPreco();
	return ss.str();
}

