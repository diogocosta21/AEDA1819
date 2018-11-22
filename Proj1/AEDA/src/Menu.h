/*
 * Menu.h
 *
 *  Created on: 16/11/2018
 *      Author: joao_
 */

#ifndef MENU_H_
#define MENU_H_


#pragma once
#include <iostream>
#include <limits>

#include "Hotel.h"
#include "FileReader.h"

/**
 * Coloca a data de quando o utilizador entra
 */
Data setData();

/**
 * Main menu
 * @param h - hotel
 */
bool HotelMenu(Hotel *h);

/**
 * Menu para fazer reserva
 * @param h - hotel
 */
bool FazerReserva (Hotel *h);

/**
 * Menu para ver ficheiros
 * @param h - hotel
 */
bool VerFicheiro (Hotel *h);

/**
 * Menu para criar espaços
 * @param h - hotel
 */
bool CriarEspaco(Hotel *h);

#endif /* MENU_H_ */
