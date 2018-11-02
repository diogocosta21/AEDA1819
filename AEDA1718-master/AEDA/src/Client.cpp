/*
 * Client.cpp
 *
 *  Created on: 31/10/2017
 *      Author: ricar
 */

#include "Client.h"

/**
 * The normal constructor.
 * @param n client's name.
 * @param NIF client's NIF.
 * @param lR date in which the client made his last reservation.
 * @param a client's address.
 */
Client::Client(string n, unsigned int NIF, Date lR, string a): name(n)
{
	this->NIF = NIF;
	this->lastReservation = lR;
	this->address = a;
}

/**
 * The destructor.
 *
 */
Client::~Client() {

}

/**
 * @return name.
 */
string Client::getName() const
{
	return name;
}

/**
 *  @return NIF.
 */
unsigned int Client::getNIF() const
{
	return NIF;
}

/**
 * @return address.
 */
string Client::getAddress() const
{
	return address;
}

/**
 * Changes the client's address.
 * @param newAddress the new address.
 */
void Client::setAddress(string newAddress)
{
	this->address = newAddress;
}

/**
 * @return the date in which the client made his last reservation.
 */
Date Client::getLastReservation() const
{
	return lastReservation;
}

/**
 * A virtual member.
 * @return string with the client's name and NIF.
 */
string Client::getInformation() const
{
	stringstream ss;

	ss << " " << getName() << ", " << getNIF();

	return ss.str();
}

/**
 * Changes the "lastResevation" to the current date.
 */
void Client::setLastReservation(const Date &d)
{
	this->lastReservation = d;
}

/**
 * @return true if the clients are the same or false otherwise.
 */
bool Client::operator== (const Client & c2) const
{
	return this->name == c2.getName();
}

//Registered Client


static unsigned int reg_clientID = 1;

/**
 * The constructor.
 * @param n client's name.
 * @param NIF client's NIF.
 * @param points points won by the client.
 * @param lR Date in which the client made his last reservation.
 * @param address client's address.
 */
RegisteredClient::RegisteredClient(string n, unsigned int NIF, unsigned int points, Date lR, string address): Client(n,NIF,lR, address)
{
	this->points=points;
	reg_id = reg_clientID;
	reg_clientID ++;
}

/**
 * The destructor.
 */

RegisteredClient::~RegisteredClient() {

}

/**
 * @return id of the client.
 */

unsigned int RegisteredClient::getId() const
{
	return reg_id;
}

/**
 * @return points.
 */
unsigned int RegisteredClient::getPoints() const
{
	return points;
}

/**
 * Sets points equal to p.
 * @param new value of points.
 */
void RegisteredClient::setPoints(unsigned int p)
{
	points = p;
}

/**
 * @return string with the client's name, NIF and points.
 */
string RegisteredClient::getInformation() const
{
	stringstream ss;

	ss << getId() << Client::getInformation() << ", Points: " << getPoints();

	return ss.str() ;
}

/**
 * Writes to ofstream the client's information in the format used in text files.
 * @param os ofstream where is stored the information.
 * @param rc1 registered client whose information is gonna be read.
 */
ostream &operator<< (ostream &os, RegisteredClient &rc1)
{
	os << rc1.getId() << ", " << rc1.getName() << ", " << rc1.getNIF() << ", "
			<< rc1.getLastReservation().getDay() << "/" << rc1.getLastReservation().getMonth() << "/" << rc1.getLastReservation().getYear() << ", "
			<< rc1.getAddress() << ", " << rc1.getPoints() << ";" ;
	return os;
}



//Occasional Client

static unsigned int oc_clientID = 1;

/**
 * The constructor.
 * @param n name.
 * @param NIF NIF.
 * @param lR Date in which the client made his last reservation.
 * @param address client's address.
 */
OccasionalClient::OccasionalClient(string n, unsigned int NIF, Date lR, string a): Client(n,NIF, lR, a)
{
	oc_id = oc_clientID;
	oc_clientID++;
}
/**
 * The destructor
 */
OccasionalClient::~OccasionalClient()
{

}

/**
 * @return id of the client.
 */
unsigned int OccasionalClient::getId() const
{
	return oc_id;
}

/**
 * Sets oc_id equal to id.
 * @param id new value for oc_id.
 */
void OccasionalClient::setId(unsigned int id)
{
	oc_id = id;
}

/**
 * Subtracts 1 to static member oc_clientID.
 */
void OccasionalClient::adjustId()
{
	oc_clientID--;
}

/**
 * @return string with the client's name and NIF.
 */
string OccasionalClient::getInformation() const
{
	stringstream ss;

	ss << getId() << " " << Client::getInformation();

	return ss.str() ;
}

/** Writes to ofstream the client's information in the format used in text files.
 * @param os ofstream where is stored the information.
 * @param oc1 occasional client whose information is going to be read.
 */
ostream &operator<< (ostream &os, OccasionalClient &oc1)
{
	os << oc1.getId() << ", " << oc1.getName() << ", " << oc1.getNIF() << ", "
			<< oc1.getLastReservation().getDay() << "/" << oc1.getLastReservation().getMonth() << "/" << oc1.getLastReservation().getYear() << ", "
			<< oc1.getAddress() << ";";
	return os;
}


