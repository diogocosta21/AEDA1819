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
#include "Data.h"

Data d1;

bool HotelMenu(Hotel *h);

bool FazerReserva (Hotel *h);

bool VerFicheiro (Hotel *h);



#endif /* MENU_H_ */
