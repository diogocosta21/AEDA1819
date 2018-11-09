/*
 * Menu.h
 *
 *  Created on: 02/11/2018
 *      Author: up201505198
 */

#pragma once
#include <iostream>
#include <limits>

#include "Hotel.h"
#include "FileReader.h"

bool HotelMenu(Hotel *h);

bool FazerReserva (Hotel *h);

bool CancelarReserva (Hotel *h);
