/*
 * Supplier.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Supplier.h"

unsigned int static supplierID = 1;

/**
 * The constructor.
 * @param n name.
 * @param NIF NIF.
 * @param ad address.
 */
Supplier::Supplier(string n, unsigned int NIF, string ad): name(n), address(ad)
{
	this->NIF = NIF;
	id = supplierID;
	supplierID++;
}

/**
 * The deconstructor.
 */
Supplier::~Supplier() {
}

/**
 * @return name.
 */
string Supplier::getName() const
{
	return name;
}

/**
 * @return address.
 */
string Supplier::getAddress() const
{
	return address;
}

/**
 * @return NIF.
 */
unsigned int Supplier::getNIF() const
{
	return NIF;
}

/**
 * @return supplier's id.
 */
unsigned int Supplier::getId() const
{
	return id;
}

/**
 * @return string with the supplier's information.
 */
string Supplier::getInformation () const
{
	stringstream ss;

	ss << getId() << " " << getName() << ", " << getNIF() << endl << "Address: " << getAddress() << endl;

	return ss.str();
}

/**
 * Writes to ofstream the supplier's information in the format used in text files.
 * @param os ofstream where is stored the information.
 * @param s1 supplier whose information is going to be read.
 */
ostream &operator<< (ostream &os, Supplier &s1)
{
	os << s1.getId() << ", " << s1.getName() <<  ", " << s1.getNIF() << ", " << s1.getAddress() << ";";
	return os;
}

