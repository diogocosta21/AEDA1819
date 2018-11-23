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
	this->sup = sup;
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
Quarto::Quarto(string t, string l, bool res, string nome)
{
	tipo = t;
	local = l;
	reservado = res;
	this->nome = nome;
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
			return simples_preco * 1.5;
		else if(getLocal() == "traseiras")
			return simples_preco;
	}

	else if(getTipo() == "duplo")
	{
		if(getLocal() == "frente")
			return duplo_preco * 1.5;
		else if(getLocal() == "traseiras")
			return duplo_preco;
	}
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

	int limite = 631;     // ate fim de junho
	int limite2 = 832;    // ate fim de agosto
	int limite3 = 1131;   // ate fim de novembro
	int limite4 = 1232;   // ate fim de dezembro
	bool anobi = false ;
	if (d1ano % 4 == 0)
		anobi = true;

	if (d1ano != d2ano)
	{
		Data FimAno = Data(32, 12, d1ano);
		Data InicioAno = Data(01, 01, d2ano);
		int intervalo1 = getPrecoFinal( d1, FimAno);
		int intervalo2 = getPrecoFinal( InicioAno, d2);
		return intervalo1 + intervalo2;

	}
	else {
		int auxd1, auxd2;
		auxd1 = (d1mes*100) + d1dia;
		auxd2 = (d2mes*100) + d2dia;
		for (int aux = auxd1 ; aux < auxd2 ; aux++) {
			if (0 < aux && aux <= limite)
				dias100++;
			if (limite < aux && aux <= limite2)
				dias150++;
			if (limite2 < aux && aux <= limite3)
				dias100++;
			if (limite3< aux && aux <= limite4)
				dias150++;
			int g = (aux/100);
			if ( (g == 4 || g == 6 || g == 9 || g == 11) && (aux%100 == 30) )
				aux += 70;
			else if ( g == 2 ) {
				if (anobi == true) {
					if (aux%100 == 29)
						aux += 71;
				}
				else
					if (aux%100 == 28)
						aux += 72;
			}
			else if (aux%100 == 31)
				aux += 69;
		}
	}

	return dias100*getPrecoQuarto() + dias150*1.5*getPrecoQuarto();
}


int SalaReuniao::getPrecoFinalSalas(Data d1, Data d2) const {
	int d1ano = d1.getAno();
	int d1mes = d1.getMes();
	int d1dia = d1.getDia();
	int d2ano = d2.getAno();
	int d2mes = d2.getMes();
	int d2dia = d2.getDia();

	int dias100 = 0;
	int dias150 = 0;

	if (d1ano != d2ano)
	{
		Data FimAno = Data(32, 12, d1ano);
		Data InicioAno = Data(01, 01, d2ano);
		int intervalo1 = getPrecoFinalSalas( d1, FimAno);
		int intervalo2 = getPrecoFinalSalas( InicioAno, d2);
		return intervalo1 + intervalo2;
	}

	int limite = 1131; // fim Novembro;
	int limite2 = 1232; // fim de Dezembro

	bool anobi = false ;
	if (d1ano % 4 == 0)
		anobi = true;

	else {
		int auxd1, auxd2;
		auxd1 = (d1mes*100) + d1dia;
		auxd2 = (d2mes*100) + d2dia;
		for (int aux = auxd1 ; aux < auxd2 ; aux++) {
			if (0 < aux && aux < limite )
				dias100++;
			if (limite < aux && aux <= limite2)
				dias150++;
			int g = (aux/100);
			if ( (g == 4 || g == 6 || g == 9 || g == 11) && (aux%100 == 30) )
				aux += 70;
			else if ( g == 2 ) {
				if (anobi == true) {
					if (aux%100 == 29)
						aux += 71;
				}
				else
					if (aux%100 == 28)
						aux += 72;
			}
			else if (aux%100 == 31)
				aux += 69;
		}
	}

	return dias100*getPrecoSala() + dias150*1.5*getPrecoSala();

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
 *  @return nome do funcionario responsavel
 */
string Quarto::getNome() const
{
	return nome;
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
 * @param os - ostream onde é guardada informacao
 * @param c1 - Quarto cuja informacao é lida
 */
ostream &operator << (ostream &os, Quarto &q1)
{
	os << q1.getNome() << ", " << q1.getRes() << ", " << q1.getTipo() << " , " << q1.getLocal();
	return os;
}

/**
 * @return string com o local, o tipo e o preco do quarto
 */
string Quarto::getInformacao() const
{
	stringstream ss;
	ss << getTipo() << ", " << getLocal() << ", " << getRes() << " , " << getNome();;

	return ss.str();
}

//==========================================================================

/**
 * Constructor
 * @param capacidade - Capacidade da sala de reuniao
 * @param video - verdade se a sala tem equipamento de video
 * @param audio - verdade se a sala tem equipamento de audio
 */
SalaReuniao::SalaReuniao(int Capacidade, bool video, bool audio, bool reservado, string nome) : capacidade (Capacidade) {
	this->video=video;
	this->audio=audio;

	if (capacidade <= 20)
		preco = 100;
	if (capacidade <= 50 && capacidade > 20)
		preco = 200;

	this->reservado=reservado;
	this->nome = nome;
};

/**
 * @return preco da sala de reuniao
 */
int SalaReuniao::getPrecoSala() const {

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
}


/**
 * @return preco da sala em determinados meses
 * @param d - data da reserva
 */
int SalaReuniao::getPrecoMes(Data d) const {
	int mes = d.getMes();
	if ((6 <= mes && mes <= 8) || mes == 12){
		return getPrecoSala()*1.5;
	}
	else
		return getPrecoSala();
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

/*
 *  @return nome do funcionario responsavel
 */
string SalaReuniao::getNome() const {
	return nome;
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
	os << sr1.getNome() << ", " << sr1.getRes() << ", " << sr1.getCapacidade() << ", " << sr1.getVideo() << ", " << sr1.getAudio();
	return os;
}


/**
 * @return string com a capacidade, informacao dos equipamentos e o preco do quarto
 */
string SalaReuniao::getInformacao() const
{
	stringstream ss;
	ss << getCapacidade() << ", " << getVideo() << ", " << getAudio() << ", " << getRes() << ", " << getPrecoSala() << ", " << getNome();
	return ss.str();
}

